#include <iostream>
#include "letter_count.hpp"
using namespace std;

constexpr int N_CHARS = ('Z' - 'A' + 1);

int main()
{
    int N_CHARS[N_CHARS] = {0};
    string s;
    cout << "Enter your string: ";
    getline(cin, s);
    count(s, N_CHARS);
    print_counts(N_CHARS, 25);
    return 0;
}