#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"
using namespace std;

class Savings_Account : public Account {
protected:
    static constexpr const double def_rate {0};
    double rate;
public:
    Savings_Account(string name = def_name, double amount = def_balance, double rate = def_rate);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Savings_Account() = default;

};

#endif // SAVINGS_ACCOUNT_H
