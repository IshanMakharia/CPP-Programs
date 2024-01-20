#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

class Account : public I_Printable {
protected:
    static constexpr const char *def_name {"Unnamed"};
    static constexpr const double def_balance {0.0};
    string name;
    double balance;
public:
    Account(string name = def_name, double amount = def_balance);
    virtual bool withdraw(double amount) = 0;
    virtual bool deposit(double amount) =0;
    virtual void print(ostream &os) const override;
    virtual ~Account() = default;

};

#endif // ACCOUNT_H
