#ifndef STRING_HPP
#define STRING_HPP

#include <compare>
#include <iosfwd>

#include "list.hpp"

class String {
public:
    // constructs this string from a C string, defaults to empty string
    explicit String(const char *s = "");

    // construct this string as a copy of string s
    String(const String &s);

    // construct this string by moving from string s
    String(String &&s);

    // swap this string with s
    void swap(String &s);

    // assignment operator from one string, s, to this string
    String &operator=(const String &s);

    // assign to this string by moving
    String &operator=(String &&s);

    // check if we can index at position i in this string
    bool in_bounds(int index) const;

    // allow const indexing
    char operator[](int index) const;

    // returns the logical length of this string (# of chars up to '\0')
    int size() const;

    // returns a reversal of this string, does not modify this string
    String reverse() const;

    // returns index into this string for first occurrence of c
    int indexOf(char c) const;

    // returns index into this string for first occurrence of s
    int indexOf(const String &s) const;

    // compare this string with another string by equality
    // note: != is auto-generated since C++20
    bool operator==(const String &s) const;

    // C++20 way of defining all comparisons at once
    std::strong_ordering operator<=>(const String &s) const;

    // concatenate this and s to form a return string
    String operator+(const String &s) const;

    // concatenate s onto the end of this string
    String &operator+=(const String &s);

    // print this string, hint: use operator << to send buf to out
    void print(std::ostream &out) const;

    // read next word into this string
    // hint: use operator >> to read from in into buf
    void read(std::istream &in);

    // destructor for this string
    ~String();
private:
    list::Node* head;

    // private constructor that takes ownership of the given list
    explicit String(list::Node* head);
};

std::ostream &operator<<(std::ostream &out, const String &s);
std::istream &operator>>(std::istream &in, String &s);

#endif
