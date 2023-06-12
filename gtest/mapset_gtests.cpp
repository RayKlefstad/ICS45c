#include <gtest/gtest.h>

#include <sstream>

#include "mapset.hpp"

using namespace std;

TEST(MapsetTests, to_lowercase) {
    EXPECT_EQ(to_lowercase("hello WORLD"), "hello world");
    EXPECT_EQ(to_lowercase("T"), "t");
    EXPECT_EQ(to_lowercase(""), "");
}

TEST(MapsetTests, load_stopwords) {
    stringstream words1{"hello WORLD test TEST bar FOO bar"};
    std::set<std::string> set1{"bar", "foo", "hello", "test", "world"};
    EXPECT_EQ(load_stopwords(words1), set1);

    stringstream words2{};
    std::set<std::string> set2;
    EXPECT_EQ(load_stopwords(words2), set2);

    stringstream words3{"A a"};
    std::set<std::string> set3{"a"};
    EXPECT_EQ(load_stopwords(words3), set3);
}

TEST(WordCount, count_words) {
    stringstream test("aa aa Aa aA AA bC bc bc BC XY XY foo FOO foO Foo BAR bar");
    std::map<std::string, int> expected{{"aa", 5}, {"bc", 4}, {"xy", 2}, {"bar", 2}};
    EXPECT_EQ(count_words(test, {"foo"}), expected);
}

TEST(WordCount, output_word_counts) {
    map<string, int> word_counts{{"foo", 1}, {"bar", 5}, {"xy", 3}};
    stringstream output;
    output_word_counts(word_counts, output);
    EXPECT_STREQ(output.str().c_str(), "bar 5\nfoo 1\nxy 3\n");
}
