#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int line_number1{0}, line_number2 {0};
    string line{};
    ifstream in_file {"../romeoandjuliet.txt"};
    ofstream out_file1 {"../romeoandjuliet_copy1.txt"};
    ofstream out_file2 {"../romeoandjuliet_copy2.txt"};
    if(!in_file || !out_file1 || !out_file2) {
        cerr << "File Opening Error!" << endl;
        return 1;
    }
    
    while(getline(in_file, line)) {
        out_file1 << setw(7) << left << ++line_number1 << line << endl;
        if (!(line == ""))
            out_file2 << setw(7) << left << ++line_number2 << line << endl;
        else
            out_file2 << line << endl;
    }
    cout << "File Updated Successfully....." << endl;
    
    in_file.close();
    out_file1.close();
    out_file2.close();
    return 0;
}