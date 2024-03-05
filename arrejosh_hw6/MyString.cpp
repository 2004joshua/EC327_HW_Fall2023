#include "MyString.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector> 
#include <limits> 


MyString::~MyString(){
    delete[] str;
    str = nullptr; 
}
ostream& operator<<(ostream &out, const MyString &a){
    out << a.str; 
    return out; 
}

istream& operator>>(std::istream &in, MyString &a) {
    vector<char> buffer(100); 
    if(in >> buffer.data()){
        buffer.push_back('\0'); 
        a.len = strlen(buffer.data()); 

        delete[] a.str; 
        a.str = new char[a.len + 1]; 

        strcpy(a.str, buffer.data()); 
    } else {
        in.setstate(ios::failbit);
    }
    return in; 
}

bool operator==(const MyString &a, const MyString &b){
    return strcmp(a.str, b.str) == 0;
}

char MyString::operator[](int index){
    const char nullchar = '\0'; 
    return (index >= 0 && index < len) ? str[index] : nullchar; 
}

MyString MyString::operator+(const MyString &a){
    int new_len = a.len + this->len; 

    char* new_str = new char[new_len + 1]; 

    strcpy(new_str,this->str); 
    strcat(new_str, a.str); 

    MyString out(new_str, new_len); 

    delete[] new_str; 

    return out; 
}

MyString::MyString(char chars[], int size)
{
    str = new char[size + 1];
    memcpy(str, chars, size);
    str[size] = '\0';
    len = size;
}

MyString MyString::append(int n, char ch)
{
    char* newstr = new char[n+this->len];
    
    for(int i=0; i<this->len;i++)
    {
        newstr[i] = this->str[i];
    }
    
    delete [] str;
    
    for(int i=0; i<n;i++)
        strncat(newstr,&ch,1);
    
    this->str = newstr;
    len += n;
    this->str[len] = '\0';
    return *this;
}

MyString MyString::assign(MyString s, int n)
{
    for(int i=0; i<n; i++)
    {
        this->str[i] = s.str[i];
    }
    this->len = n;
    
    this->str[len]='\0';
    
    return *this;
}

int MyString::compare(MyString s) const
{
    return strcmp(str, s.str);
}

int MyString::compare(int index, int n, MyString s) const
{
    char* sNew = new char [n+1];
    strncpy(sNew, &(s.str[index]), n);
    sNew[n] = '\0';
    return strcmp(str, sNew);
    
}

char * MyString::data() const
{
    return this -> str;
}

MyString MyString::commonSuffix(const MyString &s) const
{
    int minSize = this->len;
    if (this->len > s.len)
        minSize = s.len;
    int count = 0;
    for (int i = 1; i <= minSize; i++) {
        if (this->str[this->len - i] == s.str[s.len - i]) {
            count++;
        }
    }
    char temp[count];
    MyString suffix(temp,count);
    for (int i = 0; i < count; i++) {
        suffix.str[i] = s.str[s.len-count+i];
    }
    return suffix;
}

