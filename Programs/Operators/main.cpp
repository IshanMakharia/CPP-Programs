/*
Pseudo code :
    Define constant values like
        1 dollar is 100 cents
        1 quarter is 25 cents 
        1 dime is 10 cents
        1 nickel is 5 cents 
        1 penny is 1 cents 
    Declare variables like
        balance, cents, dollar, quarter, dime, nickel, penny 
    Prompt the user to enter the number of cents
    Calculations 
        dollar = cent/dollar_value;
        balance = cent - (dollar*dollar_value);
        quarter = balance/quarter_value;
        balance -= (quarter*quarter_value);
        dime = balance/dime_value;
        balance -= (dime*dime_value);
        nickel = balance/nickel_value;
        balance -= (nickel*nickel_value);
        penny = balance; 
    Display the output    

*/

#include<iostream>

using namespace std;

int main()
{
    const int dollar_value{100};
    const int quarter_value{25};
    const int dime_value{10};
    const int nickel_value{5};
    
    int cent{}, balance{}, dollar{}, quarter{}, dime{}, nickel{}, penny{};
    
    cout << "Enter the amount in cents: ";
    cin >> cent;
    
    dollar = cent/dollar_value;
    balance = cent - (dollar*dollar_value);
    quarter = balance/quarter_value;
    balance -= (quarter*quarter_value);
    dime = balance/dime_value;
    balance -= (dime*dime_value);
    nickel = balance/nickel_value;
    balance -= (nickel*nickel_value);
    penny = balance;
    
    cout << "\nThe change for " << cent << " will be: " << endl;
    cout << "dollars: " << dollar << endl;
    cout << "quarters: " << quarter << endl;
    cout << "dimes: " << dime << endl;
    cout << "nickels: " << nickel << endl;
    cout << "pennies: " << penny << endl;
    
    balance = dollar = quarter = dime = nickel = penny = 0;
    
    cout << "\n\nUsing modulus opertaor....." << endl;
    
    dollar = cent/dollar_value;
    balance = cent%dollar_value;
    quarter = balance/quarter_value;
    balance %= quarter_value;
    dime = balance/dime_value;
    balance %= dime_value;
    nickel = balance/nickel_value;
    balance %= nickel_value;
    penny = balance;
    
    cout << "\nThe change for " << cent << " will be: " << endl;
    cout << "dollars: " << dollar << endl;
    cout << "quarters: " << quarter << endl;
    cout << "dimes: " << dime << endl;
    cout << "nickels: " << nickel << endl;
    cout << "pennies: " << penny << endl;
    
    cout << endl;
    return 0;
    
}