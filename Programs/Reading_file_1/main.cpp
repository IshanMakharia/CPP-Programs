#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double calculate_marks(string &answer_key, string &response);
void display_header();
void display(int &total_students, string &name, int &marks);
void dispaly_footer(double &avg);

int main() {
    
    string name{}, answer_key{}, response{};
    int total_students{0};
    double sum{0}; 
    ifstream in_file{"../responses.txt"};
    if(!in_file) {
        cerr << "File Opening Error !" << endl;
        return 1;
    }
    
    display_header();
    getline(in_file, answer_key);
    while(in_file >> name >> response) {
        int marks = calculate_marks(answer_key, response);
        sum += marks;
        total_students++;
        display(total_students, name, marks);
    }
    
    if(total_students != 0) {
        double avg = sum / total_students;
        dispaly_footer(avg);
    }
    
    in_file.close();
    return 0;
}

double calculate_marks(string &answer_key, string &response) {
    int marks;
    for (size_t i = 0; i < answer_key.length(); i++)
        if ( answer_key.at(i) == response.at(i) )
            marks++;
    return marks;
}

void display_header() {
    cout << "\n\n" << setw(25) << right << setfill('-') << "" << endl;
    cout << setfill(' ') << setw(6) << left << "S.No"
            << setw(14) << left << "STUDENT_NAME"
            << setw(5) << right << "SCORE" << endl;
    cout << setw(25) << setfill('-') << "" << endl << setfill(' ');
}

void display(int &total_students, string &name, int &marks){
    cout << setw(6) << left << total_students
            << setw(14) << left << name
            << setw(5) << right << marks << endl;
}
void dispaly_footer(double &avg) {
    cout << setprecision(1) << fixed;
    cout << setw(25) << right << setfill('-') << "" << endl;
    cout << setw(20) << left << setfill(' ') << "AVERAGE SCORE : "
            << setw(5) << right << avg << endl;
    cout << setw(25) << right << setfill('-') << "" << "\n" << endl;
}