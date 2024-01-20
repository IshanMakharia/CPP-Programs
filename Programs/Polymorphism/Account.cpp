#include "Account.h"

Account::Account(string name, double balance)
    :name(name), balance(balance) {
        
}

bool Account::withdraw(double amount) {
    if( balance-amount <= 0 )
        return false;
    balance -= amount;
    return true;
}

bool Account::deposit(double amount) {
    if(amount <= 0)
        return false;
    balance += amount;
    return true;
}

void Account::print(ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[ Account : " << name << " : " << balance << " ]";
}