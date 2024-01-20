#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

Mystring::Mystring() : str{nullptr} {
    str = new char [1];
    *str = '\0';
}

Mystring::Mystring(const char *s) : str{nullptr} {
    if(s==nullptr) {
        str = new char [1];
        *str = '\0';
    }
    else {
        str = new char[ strlen(s) + 1 ];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source) : str{nullptr} {
    str = new char[ strlen(source.str) + 1 ];
    strcpy(str, source.str);
    //cout << str << " - using copy constructor" << endl;
}

Mystring::Mystring(Mystring &&source) : str{source.str} {
    source.str = nullptr;
    //cout << str << " - using move constructor" << endl;
}

Mystring::~Mystring() {
    delete [] str;
    //cout << str << " - using destructor" << endl;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    if(this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    if(this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

int Mystring::get_length() const {
    return strlen(str);
}

const char *Mystring::get_str() const {
    return str;
}

void Mystring::display() const {
    cout << str << " : " << get_length() << endl;
}

ostream &operator<<(ostream &os, const Mystring &obj) {
    os << obj.str;
    return os;
}

istream &operator>>(istream &is, Mystring &obj) {
    char *temp = new char[1000];
    is >> temp;
    obj = Mystring{temp};
    delete [] temp;
    return is;
}

Mystring Mystring::operator-() const {
    char *a = new char[strlen(str) + 1];
    strcpy(a, str);
    for (size_t i = 0; i < strlen(str); i++)
        a[i] = tolower(a[i]);
    Mystring temp{a};
    delete [] a;
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *a = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(a, str);
    strcat(a, rhs.str);
    Mystring temp{a};
    delete [] a;
    return temp;
}

Mystring &Mystring::operator*=(int n) {
    *this = *this*n;
    return *this;
}

Mystring &Mystring::operator++() {
    for(size_t i = 0; i<strlen(str); i++)
        str[i] = toupper(str[i]);
    return *this;
}

bool Mystring::operator<(const Mystring &rhs)const {
    return (strcmp(str, rhs.str) < 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    bool i = !(str==rhs.str);
    return i;
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) > 0);
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

Mystring operator++(Mystring &lhs, int) {
    Mystring temp{lhs};
    ++lhs;
    return temp;
}
//Mystring Mystring::operator++(int) {
//    Mystring temp{*this};
//    operator++();
//    return temp;
//}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}
//Mystring &Mystring::operator+=(const Mystring &rhs) {
//    *this = *this + rhs;
//    return *this;
//}

Mystring operator*(Mystring &lhs, int n) {
    Mystring temp;
    for(int i = 0; i<n; i++)
        temp += lhs;
    return temp;
}   