#include <iostream>
#include <cstring>

char* largestCommonSubstr(const char s1[], const char s2[]){

    //these pointers will iterate through both s1 and s2 
    const char *pstr1 = s1;
    const char *pstr2 = s2;
    const char *start = nullptr; //this pointer will be pointing to the beginning of each largest common substring

    unsigned int maxindex = 0; //keeps track of the largest common substring found 

    while(*pstr1){
        //these pointers will be initialized to pstr1's position and set the index to 0
        const char *ppstr1 = pstr1; 
        const char *ppstr2 = pstr2;
        unsigned int index = 0; 

        while(*ppstr1 && *ppstr2 && *ppstr1 == *ppstr2){ //comparison for the current position of both ppstrs
            ++ppstr1;
            ++ppstr2;
            ++index;
        }
        if(index > maxindex){//if the indexing is larger than the current max index itll be the new largest length
            maxindex = index;
            start = pstr1;
        }
        ++pstr1;
    }

    if(maxindex == 0){
        return nullptr;
    }

    char* sub_string = new char[maxindex + 1]; //setting up the return character string
    strncpy(sub_string, start, maxindex);
    sub_string[maxindex] = '\0';

    return sub_string;
}


