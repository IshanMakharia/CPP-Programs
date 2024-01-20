#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
    friend ostream &operator<<(ostream &os, const Account &accounts);
protected:
    static constexpr const char *def_name{"Unnamed"};
    static constexpr const double def_balance{0.0}; 
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    bool deposit(double amount);
    double get_balance() const;
    ~Account();

};

#endif // ACCOUNT_H
