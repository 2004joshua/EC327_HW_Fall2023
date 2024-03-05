#include "StackException.h"
#include <exception>


const char* StackException::what() const throw(){
    return "There are no items on stack!";
}
