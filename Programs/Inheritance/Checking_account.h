#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h"
#include <string>
using namespace std;

class Checking_account : public Account{
    friend ostream &operator<<(ostream &os, const Checking_account &accounts);
protected:
    static constexpr const double withdraw_fee{1.50};
public:
    Checking_account(string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    ~Checking_account();

};

#endif // CHECKING_ACCOUNT_H
