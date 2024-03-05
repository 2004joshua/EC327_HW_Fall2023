#include <iostream> 
#include <cctype> 
#include <cstring> 

char MostFrequentChar(char word[], int size){

     
    if(size == 0){
        //if there is an empty string it returns the null operator
        return '\0';
    }

    int frequency[128] = {0}; //this array holds the frequency of all 128 ascii values
    int counter = 0; 

    while(word[counter] != '\0'){//counts the frequency of each character in word[]
        frequency[word[counter]]++;
        counter++; 
    }

    char mfrequency = word[0]; //this initializes the variable that will return the most freq value

    for(int i = 1; i < 128; i++){
        if(frequency[i] > frequency[mfrequency]){
            mfrequency = frequency[i];
            mfrequency = static_cast<char>(i); //turns the index into the character of the most frequent letter
        }
    }

    return mfrequency;

    
}
char MostFrequentCharCaseInsensitive(char word[], int size){
    
    if(size == 0){
        //if there is an empty string it returns the null operator
        return '\0';
    }
    for(int i = 0; i < size; i++){
        word[i] = std::tolower(static_cast<unsigned char> (word[i])); //makes all characters lowercase so it treats same letters the same
    }

    int frequency[128] = {0}; //this array holds the frequency of all 128 ascii values
    int counter = 0; 

    while(word[counter] != '\0'){//counts the frequency of each character in word[]
        frequency[word[counter]]++;
        counter++; 
    }

    char mfrequency = word[0]; //this initializes the variable that will return the most freq value

    for(int i = 1; i < 128; i++){
        if(frequency[i] > frequency[mfrequency]){
            mfrequency = frequency[i];
            mfrequency = static_cast<char>(i); //turns the index into the character of the most frequent letter
        }
    }

    return mfrequency;
}

