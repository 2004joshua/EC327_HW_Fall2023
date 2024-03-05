#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
using namespace std;

//In LinkedList.h you may change the instances of <typename R> into <typename T> (and other instances of R into T) if you wish. (optional)
//Please do not make any other changes in this file.

template<typename T>
class LinkedList
{

    public:
        LinkedList();
        ~LinkedList();
        void addFirst(T element);
        virtual void addLast(T element);
        T getFirst() const noexcept(false);
        T getLast() const noexcept(false);
        T removeFirst() noexcept(false);
        T removeLast() noexcept(false);
        int getSize();
        
    protected:
        template<typename R>
        class Node;
        Node<T>* head;
        Node<T>* tail;
        int size;

    template<typename R>
    class Node
    {
        public:
            R element;
            Node<R>* next;
            Node(){ //no-arg constructor
                next = NULL;
            }
            Node(R element){ //constructor
                this->element = element;
                next = NULL;
            }
    };
};

#endif
