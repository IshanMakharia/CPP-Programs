#include "Checking_Account.h"

Checking_Account::Checking_Account(string name, double amount)
    : Account{name, amount} {
        
}

bool Checking_Account::withdraw(double amount) {
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[ Checking_Account : " << name << " : " << balance << " ]" << endl;
}

