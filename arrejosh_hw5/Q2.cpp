#include <iostream> 
#include <fstream> 
#include <cstring> 
#include "Person.h"
#include <algorithm>
#include <iomanip> 

int main(){

    int N; 

    std::ifstream myfile; 
    myfile.open("input.txt"); 
    
    if(!myfile){
        std::cout << "The file didn't open!\n";
        return 1;
    }

    myfile >> N; //reads first line and makes N = 3

    Person* class_arr = new Person[N]; //dynamic person array 

    for(int i = 0; i < N; i++){
        double weight, height; 
        char name[100]; 

        myfile >> weight >> height; 
        myfile.ignore(); //ignores spaces
        myfile.getline(name, sizeof(name)); 

        class_arr[i] = Person(weight, height, name); 
    }

    myfile.close();

    //selection sort for ascending bmi
    for(int i = 0; i < N; i++){
        int min = i; 
        for(int j = i + 1; j < N; j++){
            if(class_arr[j].getBMI() < class_arr[min].getBMI()){
                min = j; 
            }
        }

        Person temp = class_arr[i]; 
        class_arr[i] = class_arr[min];
        class_arr[min] = temp; 
    }

    for(int i = 0; i < N; i++){
        double bmi = class_arr[i].getBMI();
        const char* name = class_arr[i].getName();
        std::cout << name << " " << std::fixed << std::setprecision(2) << bmi << std::endl;
    }
    
    delete[] class_arr; 

    return 0;
}