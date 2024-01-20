#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <deque>

using namespace std;

bool is_palindrome(const string &s) {
    deque<char> d;
    for(char c : s) {
        if(isalnum(c))
            d.push_back(toupper(c));
    }
    char c1{}, c2{};
    while(d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        if(c1 != c2)
            return false;
        d.pop_front();
        d.pop_back();
    }
    return true;
}

int main() {
    vector<string> test_strings { "a" , "aa" , "aba" , "abba" , "abbcbba" , "ab" , "abc" , "radar" , "bob" , "ana" , "avid diva" , "Amore, Roma" , "A Toyota's a toyota"
        , "A Santa at NASA" , "c++" , "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!" , "This is a palindrome" , "palindrome"};
        
    cout << setw(10) << left << "RESULTS" << "STRINGS" << boolalpha << endl;
    for (const auto &s: test_strings) {
        cout << setw(10) << is_palindrome(s) << s << endl;
    }
    cout << endl;
    return 0;
}