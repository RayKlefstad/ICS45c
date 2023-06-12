#include <gtest/gtest.h>

#include <sstream>

#include "string.hpp"

using namespace std;

String firstString("First");
String secondString("Second");
String thirdString(firstString);
String fourthString("Fourth");
String fifthString = String();

// TEST +
TEST(String, Add) {
    String ans("FirstSecond");
    EXPECT_EQ(ans, firstString + secondString);
}

// TEST +=
TEST(String, AddEq) {
    String test(firstString);
    String ans("FirstSecond");
    test += secondString;
    EXPECT_EQ(ans, test);
}

// TEST indexOf(String)
TEST(String, IndexOfStr) {
    String test(firstString);
    test += secondString;
    EXPECT_EQ(5, test.indexOf(secondString));
}

// TEST indexOf(char)
TEST(String, IndexOfChar) {
    EXPECT_EQ(4, firstString.indexOf('t'));
}

// TEST LT
TEST(String, LessThan) {
    EXPECT_FALSE(secondString < firstString);
}

// TEST GT
TEST(String, GreaterThan) {
    EXPECT_TRUE(secondString > firstString);
}

// TEST LE
TEST(String, LessEqual) {
    EXPECT_FALSE(secondString <= firstString);
}

// TEST GE
TEST(String, GreaterEqual) {
    EXPECT_TRUE(secondString >= firstString);
}

// TEST ==
TEST(String, Equals) {
    EXPECT_TRUE(firstString == thirdString);
}

// TEST <<
TEST(String, OutStream) {
    std::stringstream out;
    out << fourthString;
    std::string test = out.str();
    std::string ans("Fourth");
    EXPECT_EQ(ans, test);
}

// TEST size()
TEST(String, Size) {
    EXPECT_EQ(0, fifthString.size());
    EXPECT_EQ(6, fourthString.size());
}

// TEST []
TEST(String, OverloadIndex) {
    EXPECT_EQ('F', firstString[0]);
    EXPECT_EQ('t', firstString[firstString.size()-1]);
    EXPECT_EQ('\0', fifthString[0]);
}

