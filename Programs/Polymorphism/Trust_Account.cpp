#include "Trust_Account.h"

Trust_Account::Trust_Account(string name, double amount, double rate) 
    : Savings_Account{name, amount, rate}, num_withdrawals{0} {
        
}

bool Trust_Account::withdraw(double amount) {
    if( ( num_withdrawals < max_withdrawals ) && ( amount < (balance * (max_withdraw_percent/100) ) ) ) {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
    return false;
}

bool Trust_Account::deposit(double amount) {
    if(amount >= bonus_threshold) {
        amount += bonus_amount;
        return Savings_Account::deposit(amount);
    }
    return false;
}

void Trust_Account::print(ostream &os) const{
    os.precision(2);
    os << fixed;
    os << "[ Trust_Account : " << name << " : " << balance << " : " << rate << "% : " << num_withdrawals << " withdrawals ]" << endl;
}