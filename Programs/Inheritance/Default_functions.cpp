#include "Default_functions.h"

void display(vector <Account> &accounts) {
    cout << "\n==================== Accounts ====================" << endl;
    for(const auto &values : accounts)
        cout << values << endl;
}
void deposit(vector <Account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.deposit(amount))
            cout << amount << " deposited to " << values << endl;
        else
            cout << amount << " failed to deposit in " << values << endl;
    }
}
void withdraw(vector <Account> &accounts, double amount) {
    for(auto &values: accounts){
        if(values.withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << values << endl;
        else
            cout << "Failed to withdraw " << amount << " from " << values << endl;
    }
}


void display(vector <Savings_account> &accounts) {
    cout << "\n================= Savings_Accounts =================" << endl;
    for(const auto &values: accounts)
        cout << values << endl;
}
void deposit(vector <Savings_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.deposit(amount))
            cout << amount << " deposited to " << values << endl;
        else
            cout << amount << " failed to deposit in " << values << endl;
    }
}
void withdraw(vector <Savings_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << values << endl;
        else
            cout << "Failed to withdraw " << amount << " from " << values << endl;
    }
}


void display(vector <Checking_account> &accounts) {
    cout << "\n================ Checking_Accounts ================" << endl;
    for(const auto &values: accounts)
        cout << values << endl;
}
void deposit(vector <Checking_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.deposit(amount))
            cout << amount << " deposited to " << values << endl;
        else
            cout << amount << " failed to deposit in " << values << endl;
    }
}
void withdraw(vector <Checking_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << values << endl;
        else
            cout << "Failed to withdraw " << amount << " from " << values << endl;
    }
}

void display(vector <Trust_account> &accounts) {
    cout << "\n================= Trust_Accounts =================" << endl;
    for(const auto &values: accounts)
        cout << values << endl;
}
void deposit(vector <Trust_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.deposit(amount))
            cout << amount << " deposited to " << values << endl;
        else
            cout << amount << " failed to deposit in " << values << endl;
    }
}
void withdraw(vector <Trust_account> &accounts, double amount) {
    for(auto &values: accounts) {
        if(values.withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << values << endl;
        else
            cout << "Failed to withdraw " << amount << " from " << values << endl;
    }
}