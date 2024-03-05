#include <iostream> 

int* TripleCapacity(int* list, int size){

    int new_size = size * 3;
    int* new_list = new int[new_size]; //initializing new tripled array

    for(int i = 0; i < new_size; i++){
       if(i >= size){
            new_list[i] = 0; //after the original size of the array it will fill the rest with 0s
        }
        else{
            new_list[i] = list[i]; 
        } 
    }

    return new_list; 
}

