#include <iostream>
#include "Account.h"
#include "Savings_account.h"
#include "Default_functions.h"
#include "Checking_account.h"
#include "Trust_account.h"
#include <vector>
#include <string>

using namespace std;

string name{};
double balance{0.0};
double interest_rate{0.0};

void display_main_menu();
void display_menu();
void display_add_menu_1();
void display_add_menu_2();
void display_deposit_menu();
void display_withdraw_menu();

int main() {
    vector <Account> accounts;
    vector <Savings_account> saving_accounts;
    vector <Checking_account> checking_accounts;
    vector <Trust_account> trust_accounts;
    char task_input, option_input;
    
    do{
        Starting_point:
        display_main_menu();
        cin >> option_input;
        option_input = toupper(option_input);
        
        if(option_input == 'A') {
            do{
                cout << "\nAccount section : ";
                display_menu();
                cin >> task_input;
                if(task_input == '1') {
                    display_add_menu_1();
                    accounts.push_back(Account{name, balance});
                }
                else if(task_input == '2') {
                    display(accounts);
                }
                else if(task_input == '3') {
                    display_deposit_menu();
                    deposit(accounts, balance);
                }
                else if(task_input == '4') {
                    display_withdraw_menu();
                    withdraw(accounts, balance);
                }
                else if(task_input == '5') {
                    goto Starting_point;
                }
                else {
                    cout << "Invalid option!! Please try again." << endl;
                }
            }while(task_input != '5');
        }
        
        else if(option_input == 'S') {
            do{
                cout << "\nSavings_account section : ";
                display_menu();
                cin >> task_input;
                if(task_input == '1') {
                    display_add_menu_2();
                    saving_accounts.push_back(Savings_account{name, balance, interest_rate});
                }
                else if(task_input == '2') {
                    display(saving_accounts);
                }
                else if(task_input == '3') {
                    display_deposit_menu();
                    deposit(saving_accounts, balance);
                }
                else if(task_input == '4') {
                    display_withdraw_menu();
                    withdraw(saving_accounts, balance);
                }
                else if(task_input == '5') {
                    goto Starting_point;
                }
                else {
                    cout << "Invalid option!! Please try again." << endl;
                }
            }while(task_input != '5');
        }
        
        else if(option_input == 'C') {
            do{
                cout << "\nChecking_account section : ";
                display_menu();
                cin >> task_input;
                if(task_input == '1') {
                    display_add_menu_1();
                    checking_accounts.push_back(Checking_account{name, balance});
                }
                else if(task_input == '2') {
                    display(checking_accounts);
                }
                else if(task_input == '3') {
                    display_deposit_menu();
                    deposit(checking_accounts, balance);
                }
                else if(task_input == '4') {
                    display_withdraw_menu();
                    withdraw(checking_accounts, balance);
                }
                else if(task_input == '5') {
                    goto Starting_point;
                }
                else {
                    cout << "Invalid option!! Please try again." << endl;
                }
            }while(task_input != '5');
        }
        
        else if(option_input == 'T') {
            do{
                cout << "\nTrust_account section : ";
                display_menu();
                cin >> task_input;
                if(task_input == '1') {
                    display_add_menu_2();
                    trust_accounts.push_back(Trust_account{name, balance, interest_rate});
                }
                else if(task_input == '2') {
                    display(trust_accounts);
                }
                else if(task_input == '3') {
                    display_deposit_menu();
                    deposit(trust_accounts, balance);
                }
                else if(task_input == '4') {
                    display_withdraw_menu();
                    withdraw(trust_accounts, balance);
                }
                else if(task_input == '5') {
                    goto Starting_point;
                }
                else {
                    cout << "Invalid option!! Please try again." << endl;
                }
            }while(task_input != '5');
        }
        
        else if(option_input == 'Q') {
            cout << "..........!!Thank you!!.........." << endl;
        }
        
        else {
            cout << "Invalid option!! Please try again." << endl;
        }
        
    }while(option_input != 'Q' && option_input != 'q');
    
    return 0;
}

void display_main_menu() {
    cout << "\nSelect an appropriate option : " << endl;
    cout << "A - create an account" << endl;
    cout << "S - create an savings_account" << endl;
    cout << "C - create an checking_account" << endl;
    cout << "T - create an trust_account" << endl;
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
void display_add_menu_1() {
    cout  << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
    cout << "Added" << endl;
}
void display_add_menu_2() {
    cout  << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
    cout << "Enter the interest rate : ";
    cin >> interest_rate;
    cout << "Added" << endl;
}
void display_deposit_menu() {
    cout << "Enter an amount to deposit : ";
    cin >> balance;
}
void display_withdraw_menu() {
    cout << "Enter an amount to withdraw : ";
    cin >> balance;
}