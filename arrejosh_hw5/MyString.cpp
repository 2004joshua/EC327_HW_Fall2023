#include "MyString.h"
#include <iostream> 
#include <cstring> 

char* MyString::data() const{
    return char_arr; 
}

MyString::MyString(char chars[], int size){ //constructor for a char pointer
    
    char_arr = new char[size + 1]; 
    
    for(int i = 0; i < size; i++){
        char_arr[i] = chars[i]; 
    }

    char_arr[size] = '\0';

    length = std::strlen(char_arr); 
}

MyString MyString::append(int n, char ch) {
    
    int len = length + n;

    for(int i = length; i < len; i++){
        this->char_arr[i] = ch;
    }
    return *this;

}


MyString MyString::assign(MyString s, int n){ 
    int slength = s.length; //grabs the  length of char_arr

    if(n == 0){
        return s;
    }

    char* pchar_arr = new char[n]; 

    for(int i = 0; i < n; i++){
        if(i < slength){
            pchar_arr[i] = s.char_arr[i];
        }
        else{
            pchar_arr[i] = '\0';
        }
    }

    pchar_arr[n] = '\0';

    MyString returnval(pchar_arr, length + n); 

    delete[] pchar_arr; 

    return returnval; 
}

int MyString::compare(MyString s) const{

    const char* nchar = char_arr; 
    std::string nstr(nchar); 

    const char* schar = s.data(); 
    std::string sstr(schar); 

    return nstr.compare(sstr);

}

int MyString::compare(int index, int n, MyString s) const {

    if(index < 0 || index >= length || n < 0){
        return 0;
    }

    const char* nchar = data();
    const char* schar = s.data(); 

    nchar += index; 
    schar += index; 

    for(int i = 0; i < n; i++){
        if(*nchar == '\0' || *schar == '\0'){
            return (*nchar - *schar); 
        }

        if(*nchar != *schar){
            return(*nchar - *schar);
        }

        nchar++;
        schar++;
    }

    return 0; //if both are equal

}

MyString MyString::commonSuffix(const MyString &s) const {
    const char* nchar = data();
    const char* schar = s.data();

    int nlength = length;
    int slength = s.length; 

    int nindex = nlength - 1; 
    int sindex = slength - 1; 
    int common_length = 0;

    while(nindex >= 0 && sindex >= 0 && nchar[nindex] == schar[sindex]){
        common_length++; //made this counter for the array im making for the substring
        nindex--;
        sindex--;
    }

    //if there is a common suffix this will activate
    if(common_length > 0){
        char* common_substring = new char[common_length + 1];

        for(int i = 0; i < common_length; i++){
            common_substring[i] = nchar[nindex + 1];
            nindex++;
        }

        common_substring[common_length] = '\0';

        MyString commonsuffix(common_substring, common_length);
        delete[] common_substring;

        return commonsuffix; 
    }

    MyString nada(nullptr,0);
    return nada; //if no common substring return nada
}