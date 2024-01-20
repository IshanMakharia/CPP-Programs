#include "Savings_account.h"

Savings_account::Savings_account(string name, double balance, double rate)
        : Account{name, balance}, rate{rate} {
            
}

bool Savings_account::deposit(double amount) {
    amount += (amount * (rate/100));
    return Account::deposit(amount);
}

Savings_account::~Savings_account() {
    
}

ostream &operator<<(ostream &os, const Savings_account &accounts) {
    os << "[ Savings_Account : " << accounts.name << " : " << accounts.balance << " : " << accounts.rate << "% ]";
    return os;
}
