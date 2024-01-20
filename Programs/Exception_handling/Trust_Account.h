#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"
using namespace std;

class Trust_Account : public Savings_Account {
protected:
    static constexpr double bonus_amount {50.0};
    static constexpr double bonus_threshold {5000.0};
    static const int max_withdrawals {3};
    static constexpr double max_withdraw_percent {20};
    int num_withdrawals;
public:
    Trust_Account(string name = def_name, double amount = def_balance, double rate = def_rate);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Trust_Account() = default;

};

#endif // TRUST_ACCOUNT_H
