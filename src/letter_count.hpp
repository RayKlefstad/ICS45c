 #include <iostream>
 #include <cctype>
 using namespace std;
 
 int char_to_index(char ch)
 {
    if (tolower(ch) >= 'a' && tolower(ch) <= 'z')
    {
        return tolower(ch) - 'a';
    } else 
    {
        return -1;
    }
    
 }

 char index_to_char(int i)
 {
    return static_cast<char>('A' + i);
 }

 void count(string s, int counts[])
 {
    for (char c : s)
    { 
        counts[char_to_index(c)]++;
    }
 }

 void print_counts(int counts[], int len)
 {
    for (int i = 0; i <= len; i++)
    {
        cout << index_to_char(i) << ' ' << counts[i] << endl;
    }
 }