#include <iostream>
#include <string>
#include <fstream>
#include "Q3.h"
#include <algorithm>

void findExpression(int N, std::string & expr){
    
    std::string *array = new std::string[N];
    std::ifstream myfile;
    myfile.open("words.txt");

    if(myfile.fail()){
        std::cout << "File didn't open!\n";
        return;
    }

    int counter = 0;

    while(std::getline(myfile , array[counter]) && counter < N){ //end of file
        counter++;
    }

    myfile.close();

    for(int i = 0; i < N; i++){
        std::cout << array[i] << std::endl;
    }
    std::cout << "this is the original array \n";

    std::ofstream output; 
    output.open("output.txt");

    if(output.fail()){
        std::cout << "File didn't open!\n";
        return;
    }

    int new_counter = 0;
    std::string *new_array = new std::string[N]; 

    for(int i = 0; i < N; i++){
       if(array[i].find(expr) != std::string::npos){
        new_array[new_counter] = array[i];
        new_counter++;
       }
    }

    std::sort(new_array, new_array + new_counter, [](const std::string &a,
    const std::string& b){
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), 
        [](char c1, char c2) {
            return std::tolower(c1) < std::tolower(c2);
        });
    }); //this will sort the array insensitively

    for(int i = 0; i < new_counter; i++){
        output << new_array[i] << "\n";
    }
    
    output.close();

    for(int i = 0; i < new_counter; i++){
        std::cout << new_array[i] << std::endl;
    }

    delete[] array; 
    delete[] new_array;
}
/*int main(){

    int N = 5; //This is the lines in the file
    std::string s1("sto");
    
    findExpression(N, s1);

    return 0;
}*/