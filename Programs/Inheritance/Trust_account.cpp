#include "Trust_account.h"

Trust_account::Trust_account(string name, double balance, double rate)
        :Savings_account{name, balance, rate}, num_withdrawals{0} {
            
}

bool Trust_account::deposit(double amount) {
    if(amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_account::deposit(amount);
}

bool Trust_account::withdraw(double amount) {
    if( (num_withdrawals < max_withdrawals) && (amount < (balance * (max_withdraw_percent/100) ) ) ) {
        ++num_withdrawals;
        return Savings_account::withdraw(amount);
    }
    else
        return false;
}

Trust_account::~Trust_account() {
    
}

ostream &operator<<(ostream &os, const Trust_account &accounts) {
    os << "[ Trust_Account : " << accounts.name << " : " << accounts.balance << " : " << accounts.rate << "% : " << accounts.num_withdrawals << " withdrawals ]";
    return os;
}

