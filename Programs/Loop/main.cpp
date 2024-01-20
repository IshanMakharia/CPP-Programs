#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    char input;
    vector <int> numbers{};
    
    do{
        
        cout << "\nSelect an option from menu to perform operation: " << endl;
        cout << "\nP - print numbers" << endl;
        cout << "A - add a number" << endl;
        cout << "M - display mean of the numbers" << endl;
        cout << "S - display the smallest number" << endl;
        cout << "L - displat the largest number" << endl;
        cout << "Q - quit\n" << endl;
        cin >> input;
        
        if(input=='P' || input=='p') {
            if(numbers.size()==0){
                cout << "[] - the list is empty" << endl;
            }
            else
            {
                cout << "[ ";
                for(auto values: numbers)
                    cout << values << " ";
                cout << "]" << endl;
            }
        }
        else if(input=='A' || input=='a')
        {
            int add{};
            cout << "Enter an integer to add to the list: ";
            cin >> add;
            numbers.push_back(add);
            cout << add << " added" << endl;
        }
        else if(input=='M' || input=='m')
        {
            int mean{}, sum{}; 
            if(numbers.size()==0)
                cout << "Unable to calculate the mean - no idea" << endl;
            else
            {
                for(auto values: numbers)
                    sum += values;
                mean = static_cast<double>(sum)/numbers.size();
                cout << "Mean of the numbers in the list is: " << mean << endl;
                cout << fixed << setprecision(1);
            }    
        }
        else if(input=='S' || input=='s')
        {
            int smaller{};
            if(numbers.size()==0)
                cout << "Unable to determine the smallest number - list is empty" << endl;
            else
            {
                smaller = numbers.at(0);
                for(auto values: numbers)
                {
                    if(values < smaller)
                    {
                        smaller = values;
                    }
                }
                cout << "The smallest number is " << smaller << endl;
            }
        }
        else if(input=='L' || input=='l')
        {
            int larger{};
            if(numbers.size()==0)
                cout << "Unable to determine the largest number - list is empty" << endl;
            else
            {
                larger = numbers.at(0);
                for(auto values: numbers)
                {
                    if(values > larger)
                    {
                        larger = values;
                    }
                }
                cout << "The largest number is " << larger << endl;
            }
        }
        else if(input=='Q' || input=='q')
        {
            cout << "Goodbye....." << endl;
        }
        else
        {
            cout << "Unknown selection, please try again" << endl;
        }
        
        
    }while(input != 'Q' && input != 'q');
   
        
    return 0;
}