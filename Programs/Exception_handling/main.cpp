#include "Account.h"
#include "Checking_Account.h"
#include "Default_functions.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

string name{};
double balance{0};
double rate{0};

void display_add_menu_1();
void display_add_menu_2();
void display_deposit_menu();
void display_withdraw_menu();

int main()
{
    shared_ptr<Account>  saving_accounts = make_shared<Savings_Account>();
    vector<shared_ptr<Account>> saving_accounts_vector;// = make_unique<vector<shared_ptr<Account>>>();
    shared_ptr<Account> checking_accounts = make_shared<Checking_Account>();
    unique_ptr<vector<shared_ptr<Account>>> checking_accounts_vector = make_unique<vector<shared_ptr<Account>>>();
    shared_ptr<Account> trust_accounts = make_shared<Trust_Account>();
    unique_ptr<vector<shared_ptr<Account>>> trust_accounts_vector = make_unique<vector<shared_ptr<Account>>>();
    unique_ptr<vector<shared_ptr<Account>>> total_accounts = make_unique<vector<shared_ptr<Account>>>();
    char option_input[1], task_input;

    do {
    starting_point:
        display_main_menu();
        cin >> option_input;
        option_input[0] = toupper(option_input[0]);

        if(option_input[0] == 'S') {
            try {
                do {
                    cout << "\nSavings_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_2();
                        *saving_accounts = Savings_Account{name,balance,rate};
                        saving_accounts_vector.push_back(saving_accounts);
                        total_accounts->push_back(saving_accounts);
                    } else if(task_input == '2') {
                        display(saving_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(saving_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(saving_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'C') {
            try {
                do {
                    cout << "\nChecking_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_1();
                        *checking_accounts = Checking_Account{name, balance};
                        checking_accounts_vector->push_back(checking_accounts);
                        total_accounts->push_back(checking_accounts);
                    } else if(task_input == '2') {
                        display(*checking_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(*checking_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(*checking_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'T') {
            try {
                do {
                    cout << "\nTrust_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_2();
                        *trust_accounts = Trust_Account{name, balance, rate};
                        trust_accounts_vector->push_back(trust_accounts);
                        total_accounts->push_back(trust_accounts);
                    } else if(task_input == '2') {
                        display(*trust_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(*trust_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(*trust_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'D') {
            display(*total_accounts);
        }

        else if(option_input[0] == 'Q') {
            cout << "..........!!Thank you!!.........." << endl;
        }

        else {
            cout << "Invalid option!! Please try again." << endl;
        }

    } while(option_input[0] != 'Q');

    return 0;
}

void display_add_menu_1()
{
    cout << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
}
void display_add_menu_2()
{
    cout << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
    cout << "Enter the interest rate : ";
    cin >> rate;
}
void display_deposit_menu()
{
    cout << "Enter an amount to deposit : ";
    cin >> balance;
}
void display_withdraw_menu()
{
    cout << "Enter an amount to withdraw : ";
    cin >> balance;
}