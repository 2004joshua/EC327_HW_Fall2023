#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

#include "Stack.h"
#include <exception> //gives us the class we inherit from

using namespace std;

class StackException : public exception {
    public:
        virtual const char* what() const throw(); 
}; 

#endif