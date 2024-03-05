#ifndef STACK_H
#define STACK_H

template<typename T> 
class Stack{

    public: 
        Stack();

        bool isEmpty() const; //returns true if stack is empty
    
        void push(T value); //adds new item of type T and value value to the stack

        T pop(); //returns top element, removes returned item

        int getSize() const; //returns size of the stack  
    
    private:
        T *elements; //pointer to elements
        int size; //size of stack
};

#endif