#include <iostream>
#include "Stack.h"
#include "StackException.h"
using namespace std;

//Only modify the pop function in this file.

// Sets size to 0 and dynamically allocates an array of size 25 for elements.
template <typename T>
Stack<T>::Stack() {
  size = 0;
  elements = new T[25];
}

// Returns true if size is 0, false if not.
template <typename T>
bool Stack<T>::isEmpty() const {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}

// Pushes value onto stack if the size is less than 25.
template <typename T>
void Stack<T>::push(T value) {
  if (size < 25) {
    elements[size] = value;
    size++;
  } else {
    return;
  }
}

// Pops top element off stack.
// MODIFY THIS FUNCTION TO THROW A StackException OBJECT IF STACK IS EMPTY
template <typename T>
T Stack<T>::pop() {
  if (size != 0) {
    return elements[--size];
  } else {
    throw StackException(); //replace return -1 with the exception
  }
}

// Returns the size of the stack.
template <typename T>
int Stack<T>::getSize() const {
  return size;
}
