#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H
#include <iostream>
using namespace std;

class I_Printable{
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
    //friend I_Printable &operator=(const I_Printable &lhs, const I_Printable &rhs);
public:
    virtual void print(ostream &os) const = 0;
  //  virtual void  assignment_operator(const I_Printable &rhs) = 0;
    virtual ~I_Printable() = default;

};

#endif // I_PRINTABLE_H
