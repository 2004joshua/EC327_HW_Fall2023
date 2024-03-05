#ifndef MYSTRING_H
#define MYSTRING_H

class MyString{
    private:
        char* char_arr; 
        int length; 
    public:
        MyString(char chars[], int size); //constructor
        MyString append(int n, char ch); //appends n copies
        MyString assign(MyString s, int n); //assigns first n number of chars into s
    
        int compare(MyString s) const; /*returns a value greater than 0, 0, or less than 0 if this string is
    greater than, equal to, or less than s, respectively*/

        int compare(int index, int n, MyString s) const; //compares this string with s(index,index+1,…,index+n-1)

        char* data() const; /*returns a pointer to a char array that contains the same
    sequence of characters as in this string object*/

        MyString commonSuffix(const MyString &s) const; /*returns the common suffix (*) of this string and
    string s, if any. Returns an empty string otherwise.*/

};

#endif