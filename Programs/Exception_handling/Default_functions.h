#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTIONS_H
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include <vector>
#include <memory>
using namespace std;

void display( vector<shared_ptr<Account>> &accounts);
void withdraw( vector<shared_ptr<Account>> &accounts, double amount);
void deposit( vector<shared_ptr<Account>> &accounts, double amount);
void display_main_menu();
void display_menu();
#endif // DEFAULT_FUNCTIONS_H
