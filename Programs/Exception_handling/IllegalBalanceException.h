#ifndef ILLEGALBALANCEEXCEPTION_H
#define ILLEGALBALANCEEXCEPTION_H
#include <iostream>
using namespace std;

class IllegalBalanceException : public exception {
public:
    IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal Balance Exception";
    }
    ~IllegalBalanceException() = default;

};

#endif // ILLEGALBALANCEEXCEPTION_H
