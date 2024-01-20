#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_account.h"
using namespace std;

class Trust_account : public Savings_account {
    friend ostream &operator<<(ostream &os, const Trust_account &accounts);
protected:
    static constexpr double bonus_amount{50.0};
    static constexpr double bonus_threshold{5000.0};
    static constexpr double max_withdrawals{3};
    static constexpr double max_withdraw_percent{20};
    int num_withdrawals;
public:
    Trust_account(string name = def_name, double balance = def_balance, double rate = def_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
    ~Trust_account();

};

#endif // TRUST_ACCOUNT_H
