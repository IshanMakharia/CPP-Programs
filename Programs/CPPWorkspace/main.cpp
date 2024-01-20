#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;


class I_Printable{
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
    //friend I_Printable &operator=(const I_Printable &lhs, const I_Printable &rhs);
public:
    virtual void print(ostream &os) const = 0;
  //  virtual void  assignment_operator(const I_Printable &rhs) = 0;
    virtual ~I_Printable() = default;

};
ostream &operator<<(ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}


class IllegalBalanceException : public exception {
public:
    IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal Balance Exception";
    }
    ~IllegalBalanceException() = default;

};
class InsufficientFundsException : public exception {
public:
    InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Insufficient Funds Exception";
    }
    ~InsufficientFundsException() = default;

};


class Account : public I_Printable {
protected:
    static constexpr const char *def_name {"Unnamed"};
    static constexpr const double def_balance {0.0};
    string name;
    double balance;
public:
    Account(string name = def_name, double amount = def_balance);
    virtual bool withdraw(double amount) = 0;
    virtual bool deposit(double amount) =0;
    virtual void print(ostream &os) const override;
    virtual ~Account() = default;

};
Account::Account(string name, double balance)
    :name(name), balance(balance) {
        if(balance < 0.0)
            throw IllegalBalanceException{};
        //cout << "Successfully Added" << endl;
}

bool Account::withdraw(double amount) {
    if( balance-amount <= 0 )
        throw InsufficientFundsException{};
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


class Savings_Account : public Account {
protected:
    static constexpr const double def_rate {0};
    double rate;
public:
    Savings_Account(string name = def_name, double amount = def_balance, double rate = def_rate);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Savings_Account() = default;

};
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


class Checking_Account : public Account {
protected:
    static constexpr const double withdraw_fee{1.50};
public:
    Checking_Account(string name = def_name, double amount = def_balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Checking_Account() = default;

};
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


class Trust_Account : public Savings_Account {
protected:
    static constexpr double bonus_amount {50.0};
    static constexpr double bonus_threshold {5000.0};
    static const int max_withdrawals {3};
    static constexpr double max_withdraw_percent {20};
    int num_withdrawals;
public:
    Trust_Account(string name = def_name, double amount = def_balance, double rate = def_rate);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;
    virtual ~Trust_Account() = default;

};
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
    if(amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

void Trust_Account::print(ostream &os) const{
    os.precision(2);
    os << fixed;
    os << "[ Trust_Account : " << name << " : " << balance << " : " << rate << "% : " << num_withdrawals << " withdrawals ]" << endl;
}





string name{};
double balance{0};
double rate{0};
void display( vector<shared_ptr<Account>> &accounts);
void withdraw( vector<shared_ptr<Account>> &accounts, double amount);
void deposit( vector<shared_ptr<Account>> &accounts, double amount);
void display_main_menu();
void display_menu();
void display_add_menu_1();
void display_add_menu_2();
void display_deposit_menu();
void display_withdraw_menu();





int main()
{
    shared_ptr<Account>  saving_accounts;// = make_shared<Savings_Account>();
    vector<shared_ptr<Account>> saving_accounts_vector;// = make_unique<vector<shared_ptr<Account>>>();
    shared_ptr<Account> checking_accounts;// = make_shared<Checking_Account>() ;
    unique_ptr<vector<shared_ptr<Account>>> checking_accounts_vector = make_unique<vector<shared_ptr<Account>>>();
    shared_ptr<Account> trust_accounts;// = make_shared<Trust_Account>();
    unique_ptr<vector<shared_ptr<Account>>> trust_accounts_vector = make_unique<vector<shared_ptr<Account>>>();
    unique_ptr<vector<shared_ptr<Account>>> total_accounts = make_unique<vector<shared_ptr<Account>>>();
    char option_input[1], task_input;

    do {
    starting_point:
        display_main_menu();
        cin >> option_input;
        option_input[0] = toupper(option_input[0]);

        if(option_input[0] == 'S') {
            try {
                do {
                    cout << "\nSavings_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_2();
                        saving_accounts = make_shared<Savings_Account>(name,balance,rate);
                        saving_accounts_vector.push_back(saving_accounts);
                        total_accounts->push_back(saving_accounts);
                    } else if(task_input == '2') {
                        display(saving_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(saving_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(saving_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'C') {
            try {
                do {
                    cout << "\nChecking_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_1();
                        checking_accounts = make_shared<Checking_Account>(name, balance);
                        checking_accounts_vector->push_back(checking_accounts);
                        total_accounts->push_back(checking_accounts);
                    } else if(task_input == '2') {
                        display(*checking_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(*checking_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(*checking_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'T') {
            try {
                do {
                    cout << "\nTrust_Account section : ";
                    display_menu();
                    cin >> task_input;
                    if(task_input == '1') {
                        display_add_menu_2();
                        trust_accounts = make_shared<Trust_Account>(name,balance,rate);
                        trust_accounts_vector->push_back(trust_accounts);
                        total_accounts->push_back(trust_accounts);
                    } else if(task_input == '2') {
                        display(*trust_accounts_vector);
                    } else if(task_input == '3') {
                        display_deposit_menu();
                        deposit(*trust_accounts_vector, balance);
                    } else if(task_input == '4') {
                        display_withdraw_menu();
                        withdraw(*trust_accounts_vector, balance);
                    } else if(task_input == '5') {
                        goto starting_point;
                    } else {
                        cout << "Invalid option!! Please try again." << endl;
                    }
                } while(task_input != '5');
            } catch(const IllegalBalanceException& ex) {
                cerr << ex.what() << endl;
            } catch(const InsufficientFundsException& ex) {
                cerr << ex.what() << endl;
            }
        }

        else if(option_input[0] == 'D') {
            display(*total_accounts);
        }

        else if(option_input[0] == 'Q') {
            cout << "..........!!Thank you!!.........." << endl;
        }

        else {
            cout << "Invalid option!! Please try again." << endl;
        }

    } while(option_input[0] != 'Q');

    return 0;
}





void display( vector<shared_ptr<Account>> &accounts) {
     cout << "\n==================== Accounts ====================" << endl;
     for (const auto values: accounts)
         cout << *values;
}

void withdraw( vector<shared_ptr<Account>> &accounts, double amount) {
    for (auto values: accounts) {
        if(values->withdraw(amount))
            cout << "Withdrawal of " << amount << " from " << *values;
        else
            cout << "Failed to withdraw " << amount << " from " << *values;
    }
}

void deposit( vector<shared_ptr<Account>> &accounts, double amount) {
    for (auto values: accounts) {
        if(values->deposit(amount))
            cout << amount << " deposited to " << *values;
        else
            cout << amount << " failed to deposit in " << *values;
    }
}

void display_main_menu() {
    cout << "\nSelect an appropriate option : " << endl;
    cout << "S - create a savings_account" << endl;
    cout << "C - create a checking_account" << endl;
    cout << "T - create a trust_account" << endl;
    cout << "D - display all the accounts" << endl;
    cout << "Q - exit" << endl;
}

void display_menu() {
    cout << "Select any task to perform : " << endl;
    cout << "1 - add account" << endl;
    cout << "2 - display accounts" << endl;
    cout << "3 - deposit money" << endl;
    cout << "4 - withdraw money" << endl;
    cout << "5 - return to main menu" << endl;
}

void display_add_menu_1()
{
    cout << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
}

void display_add_menu_2()
{
    cout << "Enter an account name : ";
    cin >> name;
    cout << "Enter the balance : ";
    cin >> balance;
    cout << "Enter the interest rate : ";
    cin >> rate;
}

void display_deposit_menu()
{
    cout << "Enter an amount to deposit : ";
    cin >> balance;
}

void display_withdraw_menu()
{
    cout << "Enter an amount to withdraw : ";
    cin >> balance;
}