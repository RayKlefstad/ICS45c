#include <gtest/gtest.h>

#include <string>

#include "map_array.hpp"

using namespace std;
static_assert(std::ranges::random_access_range<MapArray<int, double>>);

TEST(MapArrayTests, Subscript) {
    MapArray<string, int> map;

    EXPECT_EQ(map["foo"], 0);
    map["foo"] = 3;
    EXPECT_EQ(map["foo"], 3);
    map["foo"] = 5;
    EXPECT_EQ(map["foo"], 5);

    MapArray<int, double> map2;
    map2[3] = 2.0;
    EXPECT_EQ(map2[3], 2.0);
    map2[3] += 1.0;
    EXPECT_EQ(map2[3], 3.0);
}

TEST(MapArrayTests, SubscriptIterators) {
    MapArray<string, int> map;

    EXPECT_EQ(map.begin(), map.end());

    map["foo"] = 10;

    EXPECT_LT(map.begin(), map.end());
    EXPECT_EQ(map.end() - map.begin(), 1);

    map["bar"] = 5;
    map["aaa"] = 1;
    map["zzz"] = 20;

    EXPECT_EQ(map.begin()->second, 1);
    EXPECT_EQ(map.end() - map.begin(),  4);
    EXPECT_EQ(map.begin()[2].second, 10);
    EXPECT_EQ((map.begin() + 1)->second, 5);
}

TEST(MapArrayTests, Iteration) {
    MapArray<string, int> map;

    map["z"] = 5;
    map["a"] = 1;
    map["b"] = 4;
    map["aa"] = 2;
    map["aaa"] = 3;

    int i = 1;

    for (const auto& [key, value] : map) {
        EXPECT_EQ(value, i++);
    }
}
