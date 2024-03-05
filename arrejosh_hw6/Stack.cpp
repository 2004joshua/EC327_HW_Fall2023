#include <iostream> 
#include "Stack.h"

template<typename T>
Stack<T>::Stack() : elements(new T[25]), size(0) {};

template<typename T>
bool Stack<T>::isEmpty() const{
    return (size == 0) ? true : false; 
}

template<typename T>
void Stack<T>::push(T value){
    if(size < 25){
        elements[size++] = value; 
    }
}

template<typename T>
T Stack<T>::pop(){
    if(!isEmpty()){
        return elements[--size]; 
    }
}

template<typename T> 
int Stack<T>::getSize() const{
    return size; 
}

template class Stack<char>; 