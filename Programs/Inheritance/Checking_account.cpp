#include "Checking_account.h"

Checking_account::Checking_account(string name, double balance)
        :Account{name, balance} {
            
}

bool Checking_account::withdraw(double amount) {
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

ostream &operator<<(ostream &os, const Checking_account &accounts) {
    os << "[ Checking_Account : " << accounts.name << " : " << accounts.balance << " ]" << endl;
    return os;
}

Checking_account::~Checking_account()
{
}

