#include "Default_functions.h"

void display( vector <Account *> &accounts) {
     cout << "\n==================== Accounts ====================" << endl;
     for (auto values: accounts)
         cout << *values;
}

void withdraw( vector <Account *> &accounts, double amount) {
    for (auto values: accounts) {
        if(values->withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << *values;
        else
            cout << "Failed to withdraw " << amount << " from " << *values;
    }
}

void deposit( vector <Account *> &accounts, double amount) {
    for (auto values: accounts) {
        if(values->deposit(amount))
            cout << amount << " deposited to " << *values;
        else
            cout << amount << " failed to deposit in " << *values;
    }
}

void display_main_menu() {
    cout << "\nSelect an appropriate option : " << endl;
    cout << "S - create a savings_account" << endl;
    cout << "C - create a checking_account" << endl;
    cout << "T - create a trust_account" << endl;
    //cout << "D - display all the accounts" << endl;
    cout << "Q - exit" << endl;
}

void display_menu() {
    cout << "Select any task to perform : " << endl;
    cout << "1 - add account" << endl;
    cout << "2 - display accounts" << endl;
    cout << "3 - deposit money" << endl;
    cout << "4 - withdraw money" << endl;
    cout << "5 - return to main menu" << endl;
}