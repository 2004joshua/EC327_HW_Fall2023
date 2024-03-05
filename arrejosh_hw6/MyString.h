#ifndef __MyString__
#define __MyString__

#include <iostream>

using namespace std;

class MyString {

public:
    char *str;
    int len;

    MyString(char chars[], int size);
    MyString append(int n, char ch);
    MyString assign(MyString s, int n);
    int compare(MyString s) const;
    int compare(int index, int n, MyString s) const;
    char * data() const;
    MyString commonSuffix(const MyString &s) const;
    ~MyString(); 

    //Overloaded operators [] + ==

    friend bool operator==(const MyString &a, const MyString &b);
    char operator[](int index);  
    MyString operator+(const MyString &a);

    //Overloaded stream operators

    friend ostream& operator<<(ostream &out, const MyString &a); 
    friend istream& operator>>(istream &in, MyString &a); 
};

#endif /* defined(__MyString__) */
