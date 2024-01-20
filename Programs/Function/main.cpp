#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

void display_menu();
char read_selection();
void print_numbers(const vector<int>&);
void add_numbers(vector<int>&);
void mean(const vector<int>&);
void smallest_number(const vector<int>&);
void largest_number(const vector<int>&);
void quit();
void print(const vector<int>&);
void find_number(const vector<int>&);

int main()
{
    char input;
    vector <int> numbers{};
    
    do{
    display_menu();
    input = read_selection();
    
//    if(input == 'P')
//        print_numbers(numbers);
//    else if(input == 'A')
//        add_numbers(numbers);
//    else if(input == 'M')
//        mean(numbers);
//    else if(input == 'S')
//        smallest_number(numbers);
//    else if(input == 'L')
//        largest_number(numbers);
//    else if(input == 'F')
//        find_number(numbers);
//    else if(input == 'Q')
//        quit();
//    else
//        cout << "Invalid input, Please try again!!" << endl;
        
    switch(input)
        {
            case 'P':
                print_numbers(numbers);
                break;
            case 'A':
                add_numbers(numbers);
                break;
            case 'M':
                mean(numbers);
                break;
            case 'S':
                smallest_number(numbers);
                break;
            case 'L':
                largest_number(numbers);
                break;
            case 'F':
                find_number(numbers);
                break;
            case 'Q':
                quit();
                break;
            default :
                cout << "Invalid input, Please try again!!" << endl;
        }
    }while(input != 'Q');
}

void display_menu()
{
    cout << "\nSelect an option from menu to perform operation: " << endl;
    cout << "\nP - print numbers" << endl;
    cout << "A - add a number" << endl;
    cout << "M - display mean of the numbers" << endl;
    cout << "S - display the smallest number" << endl;
    cout << "L - displat the largest number" << endl;
    cout << "F - to find a number" << endl;
    cout << "Q - quit\n" << endl;
}

char read_selection()
{
    char input;
    cin >> input;
    return toupper(input);
}

void print_numbers(const vector<int> &num)
{
    if(num.size() == 0)
        cout << "[] - The list is empty" << endl;
    else
    {
        print(num);
    }
}

void add_numbers(vector<int> &num)
{
    int add;
    cout << "Enter an integer to add: ";
    cin >> add;
    num.push_back(add);
    cout << "Added..." << endl;
}
void mean(const vector<int> &num)
{
    if(num.size() == 0)
        cout << "There is no numbers in the list" << endl;
    else
    {
        int total{};
        double avg{};
        for(auto values: num)
            total += values;
        avg = static_cast<double>(total) / (num.size());
        cout << "Mean of numbers: " << avg << endl;
        cout << fixed << setprecision(1);
    }
}

void smallest_number(const vector<int> &num)
{
    if(num.size() == 0)
        cout << "There is no numbers in the list" << endl;
    else
    {
        int small{};
        small = num.at(0);
        for(auto values: num)
        {
            if(values < small)
                small = values;
        }
        cout << "The smallest number is: " << small << endl;
    }
}

void largest_number(const vector<int> &num)
{
    if(num.size() == 0)
        cout << "There is no numbers in the list" << endl;
    else
    {
        int large{};
        large = num.at(0);
        for(auto values: num)
        {
            if(values > large)
                large = values;
        }
        cout << "The largest number is: " << large << endl;
    }
}

void quit()
{
    cout << "Goodbye....." << endl;
}

void print(const vector<int> &num)
{
    cout << "[";
        for(auto values: num)
            cout << values << " ";
        cout << "]" << endl;
}

void find_number(const vector<int> &num)
{
    int target{};
    bool b{false};
    cout << "Enter a number to find: ";
    cin >> target;
    for(auto values: num)
    {
        if(values == target)
            b = true;
    }
    if(b)
        cout << "\n" << target << " is found..." << endl;
    else
        cout << "\n" << target << " is not found..." << endl;
    
}