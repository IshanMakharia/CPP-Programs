#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"
using namespace std;

class Savings_account : public Account {
    friend ostream &operator<<(ostream &os, const Savings_account &accounts);
protected:
    static constexpr const double def_rate{0.0};
    double rate;
public:
    Savings_account(string name = def_name, double balance = def_balance, double rate = def_rate);
    bool deposit(double amount);
    ~Savings_account();

};

#endif // SAVINGS_ACCOUNT_H
