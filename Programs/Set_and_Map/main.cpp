//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <sstream>
//#include <utility>
//#include <set>
//#include <map>
//#include <string>
//
//using namespace std;
//
//void part1();
//void part2();
//void display(const map<string, int> &words);
//void display(const map<string, set<int>> &words);
//string clean_string(const string &words);
//
//int main() {
//    part1();
//    part2();
//    
//    return 0;
//}
//
//void part1() {
//    ifstream in_file{"words.txt"};
//    if(!in_file) {
//        cerr << "\nFile Opening Error!\n" << endl;
//        exit(1);
//    }
//    map<string, int> words{};
//    
//    while(!in_file.eof()) {
//        string initial_word{}, final_word{};
//        in_file >> initial_word;
//        final_word = clean_string(initial_word);
//        if(words.count(final_word)) {
//            auto it = words.find(final_word);
//            it->second++;
//        }
//        else {
//            //pair<string, int> p {final_word, 1};
//            words.insert(make_pair(final_word, 1));
//        }
//    }
//    display(words);
//    
//    in_file.close();
//}
//void part2() {
//    ifstream in_file{"words.txt"};
//    if(!in_file) {
//        cerr << "\nFile Opening Error!\n" << endl;
//        exit(1);
//    }
//    map<string, set<int>> words{};
//    int line_count{0};
//    string line{};
//    
//    while(getline(in_file, line)) {
//        line_count++;
//        stringstream ss{line};
//        string initial_word{}, final_word{};
//        while(!ss.eof()) {
//            ss >> initial_word;
//            final_word = clean_string(initial_word);
//            if(words.count(final_word))
//                words[final_word].insert(line_count);
//            else {
//                pair<string, set<int>> p{final_word, line_count};
//                words.insert(p);
//                
//            }
//        }
//    }
//    display(words);
//    
//    in_file.close();
//}
//void display(const map<string, int> &words) {
//    cout << "\n===============" << endl;
//    cout  << setw(10) << left << "WORDS" 
//             << setw(5) << right << "COUNT" << endl;
//    cout << "===============" << endl;
//    for(auto pairs : words) {
//        cout << setw(10) << left << pairs.first
//                << setw(5) << right << pairs.second << endl;
//    }
//}
//
//void display(const map<string, set<int>> &words) {
//    cout << "\n====================" << endl;
//    cout << setw(10) << left << "WORDS" << "OCCURRENCES" << endl;
//    cout << "====================" << endl;
//    for (auto pairs : words) {
//        cout << setw(10) << left << pairs.first << "[ ";
//            for(auto occurrences : pairs.second) 
//                cout << occurrences << " ";
//            cout << "]" << endl;
//    }
//}
//
//string clean_string(const string &words) {
//    string result{};
//    for(const char c : words) {
//        if( c=='.' || c==',' || c==';' || c==':' )
//            continue;
//        else
//            result += c;
//    }
//    return result;
//}








#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <map>
#include <string>

using namespace std;

void part1();
void part2();
void display(const map<string, int> &words);
void display(const map<string, set<int>> &words);
string clean_string(const string &words);

int main() {
    part1();
    part2();
    
    return 0;
}

void part1() {
    map<string, int> words{};
    string line{}, word{};
    ifstream in_file{"words.txt"};
    if(in_file) {
        while(getline(in_file, line)) {
            stringstream ss{line};
            while(ss >> word) {
                word = clean_string(word);
                words[word]++;
            }
        }
        in_file.close();
        display(words);
    }
    else {
        cerr << "\nFile Opening Error!\n" << endl;
    }
}
void part2() {
    map<string, set<int>> words;
    string line{}, word{};
    ifstream in_file{"words.txt"};
    if(in_file) {
        int line_number{0};
        while(getline(in_file, line)) {
            line_number++;
            stringstream ss{line};
            while(ss >> word) {
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }
        in_file.close();
        display(words);
    }
    else {
        cerr << "\nFile Opening Error!\n" << endl;
    }
}

void display(const map<string, int> &words) {
    cout << "\n====================" << endl;
    cout  << setw(15) << left << "WORDS" 
             << setw(5) << right << "COUNT" << endl;
    cout << "====================" << endl;
    for(auto pairs : words) {
        cout << setw(15) << left << pairs.first
                << setw(5) << right << pairs.second << endl;
    }
    cout << endl;
}

void display(const map<string, set<int>> &words) {
    cout << "\n==============================" << endl;
    cout << setw(15) << left << "WORDS" << "OCCURRENCES" << endl;
    cout << "==============================" << endl;
    for (auto pairs : words) {
        cout << setw(15) << left << pairs.first << "[ ";
            for(auto line_numbers : pairs.second) 
                cout << line_numbers << " ";
            cout << "]" << endl;
    }
    cout << endl;
}

string clean_string(const string &words) {
    string result{};
    for(const char c : words) {
        if( c=='.' || c==',' || c==';' || c==':' )
            continue;
        else
            result += c;
    }
    return result;
}