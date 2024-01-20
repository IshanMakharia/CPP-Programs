#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTIONS_H
#include "Account.h"
#include "Savings_account.h"
#include "Checking_account.h"
#include "Trust_account.h"
#include <vector>
using namespace std;

void display(vector <Account> &accounts);
void deposit(vector <Account> &accounts, double amount);
void withdraw(vector <Account> &accounts, double amount);

void display(vector <Savings_account> &accounts);
void deposit(vector <Savings_account> &accounts, double amount);
void withdraw(vector <Savings_account> &account, double amount);

void display(vector <Checking_account> &accounts);
void deposit(vector <Checking_account> &accounts, double amount);
void withdraw(vector <Checking_account> &account, double amount);

void display(vector <Trust_account> &accounts);
void deposit(vector <Trust_account> &accounts, double amount);
void withdraw(vector <Trust_account> &account, double amount);

#endif // DEFAULT_FUNCTIONS_H
