#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H
#include <iostream>
using namespace std;

class InsufficientFundsException : public exception {
public:
    InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Insufficient Funds Exception";
    }
    ~InsufficientFundsException() = default;

};

#endif // INSUFFICIENTFUNDSEXCEPTION_H
