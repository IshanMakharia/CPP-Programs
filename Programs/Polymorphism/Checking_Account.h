#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h"
using namespace std;

class Checking_Account : public Account {
protected:
    static constexpr const double withdraw_fee {1.50};
public:
    Checking_Account(string name = def_name, double amount = def_balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Checking_Account() = default;

};

#endif // CHECKING_ACCOUNT_H
