#include "alloc.hpp"

#include <cstdlib>
#include <iostream>
#include <new>
#include <stdexcept>
#include <unordered_set>

namespace pmr = std::pmr;

// Implementation details
namespace {

// The normal containers also use new/delete and we don't want to end up with infinite
// recursions. So we specifically make them use alloc / free instead via pmr.
class AllocFreeResource : public pmr::memory_resource {
    virtual void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        return std::aligned_alloc(alignment, bytes);
    }

    virtual void do_deallocate(void* p, std::size_t, std::size_t) override {
        std::free(p);
    }

    virtual bool do_is_equal(const pmr::memory_resource& other) const noexcept override {
        return dynamic_cast<const AllocFreeResource*>(&other) != nullptr;
    }
};

AllocFreeResource untracked_memory;
thread_local pmr::unordered_set<AllocationTracker::State*> trackers{&untracked_memory};

}  // namespace

AllocationTracker::State::State()
    : allocations{&untracked_memory},
      num_allocations{0},
      total_bytes{0},
      double_deletes{0},
      mismatching_deletes{0} {}

void AllocationTracker::State::add_allocation(void* ptr, std::size_t size, AllocationType type) {
    allocations[ptr] = type;
    num_allocations += 1;
    total_bytes += size;
}

bool AllocationTracker::State::delete_allocation(void* ptr, AllocationType type) {
    auto it = allocations.find(ptr);

    if (it == allocations.end()) {
        std::cerr << "ERROR: Tried to delete non-existent or already deleted pointer!\n";
        double_deletes += 1;
        return false;
    }

    if (it->second != type) {
        std::cerr
            << "ERROR: Deleted pointer through mismatching new[]/delete or new/delete[]!\n";
        mismatching_deletes += 1;
    }

    allocations.erase(it);
    return true;
}

AllocationTracker::AllocationTracker() {
    trackers.insert(&state);
}

AllocationTracker::~AllocationTracker() {
    trackers.erase(&state);
}

const pmr::unordered_map<void*, AllocationType>& AllocationTracker::get_allocations() const {
    return state.allocations;
}

std::size_t AllocationTracker::get_num_allocations() const {
    return state.num_allocations;
}

std::size_t AllocationTracker::get_bytes_allocated() const {
    return state.total_bytes;
}

std::size_t AllocationTracker::get_double_deletes() const {
    return state.double_deletes;
}

std::size_t AllocationTracker::get_mismatching_deletes() const {
    return state.mismatching_deletes;
}

void AllocationTracker::print_allocation_report(std::ostream& out) const {
    out << state.num_allocations << " allocations (" << state.total_bytes
        << " bytes) have been performed in total.\n";

    if (state.allocations.empty()) {
        out << "All allocations have been deleted!\n";
    } else {
        out << state.allocations.size() << " allocations have not been deleted yet!\n";
    }

    if (state.double_deletes) {
        out << "There were " << state.double_deletes << " double delete errors!\n";
    }

    if (state.mismatching_deletes) {
        out << "There were " << state.mismatching_deletes << " mismatching deletes!\n";
    }

    if (state.double_deletes + state.mismatching_deletes == 0) {
        out << "There were no delete errors!\n";
    }
}

void* operator new(std::size_t size) {
    if (size == 0) {
        ++size;
    }

    if (void* ptr = std::malloc(size)) {
        for (AllocationTracker::State* tracker : trackers) {
            tracker->add_allocation(ptr, size, AllocationType::Single);
        }
        return ptr;
    }

    throw std::bad_alloc{};
}

void* operator new[](std::size_t size) {
    if (size == 0) {
        ++size;
    }

    if (void* ptr = std::malloc(size)) {
        for (AllocationTracker::State* tracker : trackers) {
            tracker->add_allocation(ptr, size, AllocationType::Array);
        }
        return ptr;
    }

    throw std::bad_alloc{};
}

void operator delete(void* ptr) noexcept {
    if (!ptr) {
        return;
    }

    bool success = true;
    for (AllocationTracker::State* tracker : trackers) {
        success |= tracker->delete_allocation(ptr, AllocationType::Single);
    }

    if (success) {
        std::free(ptr);
    }
}

void operator delete(void* ptr, std::size_t) noexcept {
    if (!ptr) {
        return;
    }

    bool success = true;
    for (AllocationTracker::State* tracker : trackers) {
        success |= tracker->delete_allocation(ptr, AllocationType::Single);
    }

    if (success) {
        std::free(ptr);
    }
}

void operator delete[](void* ptr) noexcept {
    if (!ptr) {
        return;
    }

    bool success = true;
    for (AllocationTracker::State* tracker : trackers) {
        success |= tracker->delete_allocation(ptr, AllocationType::Array);
    }

    if (success) {
        std::free(ptr);
    }
}

void operator delete[](void* ptr, std::size_t) noexcept {
    if (!ptr) {
        return;
    }

    bool success = true;
    for (AllocationTracker::State* tracker : trackers) {
        success |= tracker->delete_allocation(ptr, AllocationType::Array);
    }

    if (success) {
        std::free(ptr);
    }
}
