#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool is_palindrome(const string &words) {
    queue<char> q{};
    stack<char> s{};
    for (char c : words) {
        if(isalnum(c)) {
            c = toupper(c);
            q.push(c);
            s.push(c);
        }
    }
    char c1{}, c2{};
    while(!q.empty()) {
        c1 = q.front();
        c2 = s.top();
        if(c1 != c2)
            return false;
        q.pop();
        s.pop();
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