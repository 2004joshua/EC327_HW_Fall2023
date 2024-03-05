#include <string> 
#include "Q2.h"
#include <cstring> 

bool isPalindrome(char word[]){
    
    int length = strlen(word);
    char word2[length + 1]; //takes into consideration of the null terminator
    
    for(int i = 0; i < length; i++){

        word2[i] = word[length - 1 - i] ;

    }

    word2[length] = '\0'; //sets the last index as the null terminator since the loop wont cover it

    if(strcmp(word,word2) == 0){ //if the comparison of the two comes out as 0 its true
        
        return true;

    }
    else{

        return false; 

    }
}
bool isPalindrome(unsigned int num){
    std::string numstr = std::to_string(num);

    int first = 0, last = numstr.length() - 1;

    std::string numstr2; 

    numstr2.resize(numstr.length());

    for(int i = first; i <= last; i++){

        numstr2[i] = numstr[last - i]; //std::string dont have null operators

    }
    if( numstr2 == numstr){ //with normal strings theyre compared with == 
        return true; 
    }
    else{
        return false;
    }
}
bool isPalindrome(int numarray[], int size){
    int numarray2[size]; 

    for(int i = 0; i < size; i++){
        numarray2[i] = numarray[size - 1 - i]; 
    }

    for(int j = 0; j < size; j++){
        if(numarray[j] != numarray2[j]){
            return false;
        }
    }
    return true;
}

