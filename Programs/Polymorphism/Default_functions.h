#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTIONS_H
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include <vector>
using namespace std;

void display( vector <Account *> &accounts);
void withdraw( vector <Account *> &accounts, double amount);
void deposit( vector <Account *> &accounts, double amount);
void display_main_menu();
void display_menu();
#endif // DEFAULT_FUNCTIONS_H
