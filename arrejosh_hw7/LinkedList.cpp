#include "LinkedList.h"

#include <stdexcept>
using namespace std;

//Do not change this file

template<typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    while(size > 0){
        removeFirst();
    }
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    if(tail == NULL){
        tail = head;
    }
    size++;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    Node<T>* newNode = new Node<T>(element);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
    } 
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename T>
T LinkedList<T>::getFirst() const noexcept(false)
{
    if(size == 0){
        throw runtime_error("No elements in the list");
    } 
    else {
        return head->element;
    }
}

template<typename T>
T LinkedList<T>::getLast() const noexcept(false)
{
    if(size == 0){
        throw runtime_error("No elements in the list");
    } 
    else {
        return tail->element;
    }
}

template<typename T>
T LinkedList<T>::removeFirst() noexcept(false)
{
    if(size == 0){
        throw runtime_error("No elements in the list");
    } 
    else {
        Node<T>* temp = head;
        head = head->next;
        size--;
        if(head == NULL){
            tail = NULL;
        }
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
T LinkedList<T>::removeLast() noexcept(false)
{
    if(size == 0){
        throw runtime_error("No elements in the list");
    } 
    else if (size == 1){
        Node<T>* temp = head;
        head = tail = NULL;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    } 
    else {
        Node<T>* current = head;
        for(int i = 0; i < size - 2; i++){
            current = current->next;
        }
        Node<T>* temp = tail;
        tail = current;
        tail->next = NULL;
        size--;
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
int LinkedList<T>::getSize(){
    return size;
}

template class LinkedList<int>;
