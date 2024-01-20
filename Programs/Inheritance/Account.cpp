#include "Account.h"

Account::Account(string name, double balance)
        : name{name}, balance{balance} {
            
}

bool Account::withdraw(double amount) {
        if(balance - amount <= 0)
            return false;
        balance -= amount;
        return true;
}

bool Account::deposit(double amount) {
    if(amount < 0)
        return false;
    balance += amount;
    return true;
}

double Account::get_balance() const {
    return balance;
}

Account::~Account() {
    
}

ostream &operator<<(ostream &os, const Account &accounts) {
    os << "[ Account : " << accounts.name << " : " << accounts.balance << " ]";
    return os;
}

