//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main() {
//    string words{}, key{};
//    int total_words{0}, word_searched{0};
//    fstream in_file {"romeoandjuliet.txt", ios::in};
//    if(!in_file) {
//        cerr << "File Opening Error!" << endl;
//        return 1;
//    }
//    
//    cout << "\n\n\tEnter a word to be searched : ";
//    cin >> key;
//    while (in_file >> words) {
//        total_words++;
//        size_t i = words.find(key);
//        if( i != string::npos)
//            word_searched++;
//    }
//    cout << "\tTotal " << total_words << " words were seached....." << endl;
//    cout << "\tAnd " << key << " was found " << word_searched << " times\n" << endl;
//    
//    in_file.close();
//    return 0;
//}




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool find_substring(string &word_to_find, string &word_read);

int main() {
    string word_read{}, word_to_find{};
    int word_count{0}, match_count{0};
    fstream in_file {"../romeoandjuliet.txt", ios::in};
    if(!in_file) {
        cerr << "File Opening Error!" << endl;
        return 1;
    }
    
    cout << "\n\nEnter a word to be searched : ";
    cin >> word_to_find;
    cout << endl;
    while (in_file >> word_read) {
        word_count++;
        if( find_substring(word_to_find, word_read)) {
            match_count++;
            cout << word_read << "\t";
        }
    }
    cout << "\n\nTotal " << word_count << " words were seached....." << endl;
    cout << "And " << word_to_find << " was found " << match_count << " times\n" << endl;
    
    in_file.close();
    return 0;
}

bool find_substring(string &word_to_find, string &word_read) {
    size_t i = word_read.find(word_to_find);
    if( i != string::npos )
        return true;
    return false;
}