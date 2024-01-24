// This "include guard" protects this header from being included twice:
#ifndef WORD_COUNT_HPP
#define WORD_COUNT_HPP

// These are the includes that are necessary for the header. You might need more in the
// actual implementation. Note that <iosfwd> is a special "stripped down" version of <iostream>
// that's usually good enough for a header file but not enough to actually work with iostreams.
#include <iosfwd>
#include <map>
#include <set>
#include <string>

void to_lowercase(std::string& str);

std::set<std::string> load_stopwords(std::istream& stopwords);

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords);

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output);

#endif // End of the include guard.
