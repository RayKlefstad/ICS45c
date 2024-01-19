#include <gtest/gtest.h>

#include <sstream>

#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase) {
  string test = "hEllO wOrLd";

  to_lowercase(test);
  EXPECT_STREQ("hello world", test.c_str());
}

TEST(WordCount, LoadStopWords) {
  stringstream test("hello world");

  const auto stop_words = load_stopwords(test);

  EXPECT_TRUE(stop_words.contains("hello"));
  EXPECT_TRUE(stop_words.contains("world"));
  EXPECT_FALSE(stop_words.contains("foo"));
}

TEST(WordCount, CountWords) {
  stringstream test("aa aa bc foo bar");
  const auto counts = count_words(test, {});

  EXPECT_EQ(counts.at("aa"), 2);
  EXPECT_EQ(counts.at("bc"), 1);
  EXPECT_EQ(counts.at("foo"), 1);
  EXPECT_EQ(counts.at("bar"), 1);
  EXPECT_FALSE(counts.contains("baz"));
}

TEST(WordCount, OutputWordCounts) {
  map<string, int> word_counts;
  word_counts["foo"] = 1;
  word_counts["bar"] = 5;
  word_counts["xy"] = 3;

  stringstream output;
  output_word_counts(word_counts, output);
  EXPECT_STREQ(output.str().c_str(), "bar 5\nfoo 1\nxy 3\n");
}

