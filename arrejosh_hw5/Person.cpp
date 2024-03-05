#include <cstring>
#include "Person.h"
#include <cmath> 


Person::Person(){
    weight = 0.0; //this-> will refer to these values
    height = 0.0;
    name[0] = '\0'; 
}

Person::Person(double weight, double height, char name[]){
    this-> weight = weight;
    this->height = height;
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name)-1] = '\0'; //last index will have the termination character
}

//set functions setup the Person function at the beginning

void Person::setWeight(double weight){
    this->weight = weight; //points back to weight
}
void Person::setHeight(double height){
    this->height = height; //points back to height
}
void Person::setName(char name[]){
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name)-1] = '\0'; //points back to name 
}

//get functions return 
double Person::getWeight(){
    return weight;
}
double Person::getheight(){
    return height;
}

char* Person::getName(){
    return name;
}

double Person::getBMI(){
    return (weight / pow(height,2)) * 703.0;
}

