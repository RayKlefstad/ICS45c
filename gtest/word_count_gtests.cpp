#include <gtest/gtest.h>

#include <sstream>

#include "word_count.h"

using namespace std;

TEST(WordCount, ToLowercase) {
  string test = "hEllO wOrLd";

  to_lowercase(test);
  EXPECT_STREQ("hello world", test.c_str());
}

TEST(WordCount, LoadStopWords) {
  stringstream test("hello world HELLO WORLD tEsT");

  const auto stop_words = load_stopwords(test);

  EXPECT_TRUE(stop_words.contains("hello"));
  EXPECT_TRUE(stop_words.contains("world"));
  EXPECT_FALSE(stop_words.contains("HELLO"));
  EXPECT_FALSE(stop_words.contains("WORLD"));
  EXPECT_TRUE(stop_words.contains("test"));
}

TEST(WordCount, CountWords) {
  stringstream test("aa aa Aa aA AA bC bc bc BC XY XY foo FOO foO Foo BAR bar");
  const auto counts = count_words(test, {"foo"});

  EXPECT_EQ(counts.at("aa"), 5);
  EXPECT_EQ(counts.at("bc"), 4);
  EXPECT_EQ(counts.at("xy"), 2);
  EXPECT_EQ(counts.at("bar"), 2);
  EXPECT_FALSE(counts.contains("foo"));
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

