// -------------------- Google Test Main - gtestmain.cpp -------------------- //
// :WARNING: DO NOT MODIFY THIS FILE AT ALL. :WARNING:
// This file runs Google Test with any of the unit tests you wrote in the
// test.cpp file.
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
