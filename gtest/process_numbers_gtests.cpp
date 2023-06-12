#include <gtest/gtest.h>

#include "process_numbers.hpp"

using namespace std;

TEST(ProcessNumbersTests, split_odd_even) {
    const auto test_case = [](const string& nums, const string& odds, const string& evens) {
        stringstream in{nums};
        stringstream odds_str, evens_str;
        split_odd_even(in, odds_str, evens_str);
        EXPECT_EQ(odds_str.str(), odds);
        EXPECT_EQ(evens_str.str(), evens);
    };

    test_case("1 2 3", "1 3 \n", "2\n");
    test_case("10 2 3 7 1", "1 3 7 \n", "2\n10\n");
    test_case("", "\n", "");
}
