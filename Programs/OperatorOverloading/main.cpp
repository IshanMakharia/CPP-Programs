# include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a{"Denver"};
    Mystring b{"Tokyo"};
    Mystring c{"Nairobi"};
    Mystring d{"Rio"};
    b = "TOKYO";
    a.display();
    b.display();
    b = -b;
    cout << b << endl;
    b = c+b;
    b.display();
    a+=d;
    cout << boolalpha;
    cout << a << " == " << b << " : " << (a==b) << endl;
    cout << a << " != " << b << " : " << (a!=b) << endl;
    cout << a << " < " << b << " : " << (a<b) << endl;
    cout << a << " > " << b << " : " << (a>b) << endl;
    cout << "c*2 = " << c*2 << endl;
    c*=2;
    ++a;
    ++b;
    c++;
    d++;
    a.display();
    b.display();
    c.display();
    d.display();
    return 0;
}