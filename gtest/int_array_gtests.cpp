#include <gtest/gtest.h>

#include <sstream>

#include "alloc.hpp"
#include "int_array.hpp"

using namespace std;

TEST(IntArrayTests, Length) {
    Array arr{10};
    EXPECT_EQ(arr.length(), 10);
    EXPECT_EQ(Array{}.length(), 0);
}

TEST(IntArrayTests, Subscript) {
    Array arr{10};
    arr[0] = 3;
    arr[3] = 5;
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[3], 5);
}

TEST(IntArrayTests, Print) {
    stringstream out;

    Array arr{3};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    out << arr;

    EXPECT_EQ(out.str(), "       0       1       2");
}

TEST(IntArrayTests, Read) {
    stringstream in{"1 2 3 4"};

    Array arr{3};
    in >> arr;

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

// TEST(IntArrayTests, Fill) {
//     Array arr{10};
//     arr.fill(20);
//     EXPECT_EQ(arr[0], 20);
//     arr.fill(5);
//     EXPECT_EQ(arr[9], 5);
// }
//
// TEST(IntArrayTests, OutOfBounds) {
//     Array arr{10};
//     EXPECT_ANY_THROW(arr[11]);
// }
//
// TEST(IntArrayTests, CopyConstructor) {
//     Array arr{10};
//     arr.fill(20);
//     Array arr2{arr};
//     EXPECT_EQ(arr2.length(), 10);
//     EXPECT_EQ(arr2[0], 20);
//     EXPECT_EQ(arr2[9], 20);
//
//     Array empty;
//     Array arr3{empty};
//     EXPECT_EQ(arr3.length(), 0);
// }
//
// TEST(IntArrayTests, MoveConstructor) {
//     AllocationTracker tracker;
//
//     Array arr{10};
//     arr.fill(20);
//
//     std::size_t allocs_before_move = tracker.get_num_allocations();
//     Array arr2{std::move(arr)};
//     std::size_t allocs_after_move = tracker.get_num_allocations();
//
//     EXPECT_EQ(allocs_before_move, allocs_after_move);
//
//     EXPECT_EQ(arr2.length(), 10);
//     EXPECT_EQ(arr2[0], 20);
//     EXPECT_EQ(arr2[9], 20);
//
//     Array empty;
//     Array arr3{std::move(empty)};
//     EXPECT_EQ(arr3.length(), 0);
// }
//
// TEST(IntArrayTests, Swap) {
//     AllocationTracker tracker;
//
//     Array arr{10};
//     arr.fill(20);
//     Array arr2{2};
//     arr2.fill(5);
//
//     std::size_t allocs_before_swap = tracker.get_num_allocations();
//     swap(arr, arr2);
//     std::size_t allocs_after_swap = tracker.get_num_allocations();
//
//     EXPECT_EQ(allocs_before_swap, allocs_after_swap);
//
//     EXPECT_EQ(arr2.length(), 10);
//     EXPECT_EQ(arr2[0], 20);
//     EXPECT_EQ(arr2[9], 20);
//
//     EXPECT_EQ(arr.length(), 2);
//     EXPECT_EQ(arr[0], 5);
//     EXPECT_EQ(arr[1], 5);
// }
//
// TEST(IntArrayTests, CopyAssignment) {
//     Array arr{10};
//     arr.fill(20);
//
//     Array arr2{2};
//     arr2.fill(5);
//
//     arr = arr2;
//
//     EXPECT_EQ(arr.length(), 2);
//     EXPECT_EQ(arr[0], 5);
//     EXPECT_EQ(arr[1], 5);
//
//     EXPECT_EQ(arr2.length(), 2);
//     EXPECT_EQ(arr2[0], 5);
//     EXPECT_EQ(arr2[1], 5);
//
//     arr = arr;
//
//     EXPECT_EQ(arr.length(), 2);
//     EXPECT_EQ(arr[0], 5);
//     EXPECT_EQ(arr[1], 5);
// }
//
// TEST(IntArrayTests, MoveAssignment) {
//     AllocationTracker tracker;
//
//     Array arr{10};
//     arr.fill(20);
//
//     Array arr2{2};
//     arr2.fill(5);
//
//     std::size_t allocs_before_move = tracker.get_num_allocations();
//     arr = std::move(arr2);
//     std::size_t allocs_after_move = tracker.get_num_allocations();
//     EXPECT_EQ(allocs_before_move, allocs_after_move);
//
//     EXPECT_EQ(arr.length(), 2);
//     EXPECT_EQ(arr[0], 5);
//     EXPECT_EQ(arr[1], 5);
//
//
//     arr2 = Array{5};
//     EXPECT_EQ(arr2.length(), 5);
//     arr2 = std::move(arr2);
//     arr2 = Array{7};
//     EXPECT_EQ(arr2.length(), 7);
// }
//
