#include <gtest/gtest.h>

#include "set_list.hpp"

using namespace std;

static_assert(ranges::forward_range<SetList<int>>);

TEST(SetListTests, InsertContains) {
    SetList<int> set;

    EXPECT_FALSE(set.contains(5));
    set.insert(5);
    EXPECT_TRUE(set.contains(5));
    EXPECT_FALSE(set.contains(7));
    set.insert(7);
    EXPECT_TRUE(set.contains(5));
    EXPECT_TRUE(set.contains(7));
}

TEST(SetListTests, InsertIterator) {
    SetList<int> set;

    EXPECT_EQ(set.begin(), set.end());
    set.insert(5);
    EXPECT_NE(set.begin(), set.end());
    EXPECT_EQ(*set.insert(7), 7);
    set.insert(9);
    EXPECT_EQ(*set.begin(), 9);
}

TEST(SetListTests, Iteration) {
    SetList<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(4);
    set.insert(4);

    int i = 4;
    for (int x : set) {
        EXPECT_EQ(x, i--);
    }
}

TEST(SetListTests, RangeConstructor) {
    SetList<int> set{views::iota(0, 10)};

    int i = 9;
    for (int x : set) {
        EXPECT_EQ(x, i--);
    }
}
