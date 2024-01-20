#include "Savings_Account.h"

Savings_Account::Savings_Account(string name, double amount, double rate)
    : Account{name, amount}, rate {rate} {
        
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

bool Savings_Account::deposit(double amount) {
    amount += (amount*(rate/100));
    return Account::deposit(amount);
}

void Savings_Account::print(ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[ Savings_Account : " << name << " : " << balance << " : " << rate << "% ]" << endl;
}