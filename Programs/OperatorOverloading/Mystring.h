#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);

    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(Mystring &lhs, int n);
    friend Mystring operator++(Mystring &lhs, int);

private:
    char *str;

public:
    Mystring();                                                                            //constructor
    Mystring(const char *s);                                                       //overloaded_constructor
    Mystring(const Mystring &source);                                     //copy_constructor
    Mystring(Mystring &&source);                                            //move_constructor
    ~Mystring();                                                                         //destructor
    Mystring &operator=(const Mystring &rhs);                       //overloaded_assignment_operator_copy
    Mystring &operator=(Mystring &&rhs);                              //overloaded_assignment_operator_move
    
    int get_length() const;
    const char *get_str() const;
    void display() const;
    
    Mystring operator-() const;
    Mystring operator+(const Mystring &rhs) const; 
    //Mystring &operator+=(const Mystring &rhs);
    bool operator!=(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    Mystring &operator*=(int n);
    Mystring &operator++();
    //Mystring operator++(int);
};

#endif // MYSTRING_H
