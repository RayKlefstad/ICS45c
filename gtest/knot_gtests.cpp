// ------------------------- Tests File - knot_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include <iostream>
using namespace std;
// Include all of your *.h files you want to unit test:
#include "convert_knots.h"

namespace {

TEST(ConvertKnots, Two) {
  EXPECT_NEAR(0.0383593, knots_to_miles_per_minute(2), 0.01);
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
