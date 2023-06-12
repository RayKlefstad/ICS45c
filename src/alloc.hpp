#ifndef ALLOC_HPP
#define ALLOC_HPP

#include <iosfwd>
#include <memory_resource>
#include <unordered_map>

enum class AllocationType { Single, Array };

class AllocationTracker {
public:
    struct State {
        std::pmr::unordered_map<void*, AllocationType> allocations;

        std::size_t num_allocations;
        std::size_t total_bytes;
        std::size_t double_deletes;
        std::size_t mismatching_deletes;

        State();

        void add_allocation(void* ptr, std::size_t size, AllocationType type);
        bool delete_allocation(void* ptr, AllocationType type);
    };

    AllocationTracker();

    AllocationTracker(const AllocationTracker&) = delete;
    AllocationTracker& operator=(const AllocationTracker&) = delete;

    AllocationTracker(AllocationTracker&&) = delete;
    AllocationTracker& operator=(AllocationTracker&&) = delete;

    ~AllocationTracker();

    const std::pmr::unordered_map<void*, AllocationType>& get_allocations() const;

    std::size_t get_num_allocations() const;
    std::size_t get_bytes_allocated() const;

    std::size_t get_double_deletes() const;
    std::size_t get_mismatching_deletes() const;

    void print_allocation_report(std::ostream& out) const;

private:
    State state;
};

#endif
