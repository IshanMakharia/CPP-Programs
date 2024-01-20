#include "I_Printable.h"

ostream &operator<<(ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

/*I_Printable &operator=(const I_Printable &lhs, const I_Printable &rhs) {
    lhs.assignment_operator(rhs);
    return *lhs;
}*/