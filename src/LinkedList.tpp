#include "LinkedList.h"
template <typename T>
LinkedList<T>::LinkedList(){
    this->start = nullptr;
    this->size = 0;
}
template <typename T>
LinkedList<T>::~LinkedList(){
    Nodo<T>* current = this->start;
    while (current != nullptr) {
        Nodo<T>* next = current->getNext();
        delete current;
        current = next;
    }
}
template <typename T>
void LinkedList<T>::add(T value){
    Nodo<T>* newNode = new Nodo<T>(value);
    if (this->start == nullptr) {
        this->start = newNode;
    } else {
        Nodo<T>* current = this->start;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    this->size++;
}
template <typename T>
void LinkedList<T>::remove(T value){
    if (this->start == nullptr) return;

    if (this->start->getValue() == value) {
        Nodo<T>* temp = this->start;
        this->start = this->start->getNext();
        delete temp;
        this->size--;
        return;
    }

    Nodo<T>* current = this->start;
    while (current->getNext() != nullptr && current->getNext()->getValue() != value) {
        current = current->getNext();
    }

    if (current->getNext() != nullptr) {
        Nodo<T>* temp = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete temp;
        this->size--;
    }
}

template <typename T>
T *LinkedList<T>::get(int i){
    Nodo<T>* current = this->start;
    int index = 0;
    while (current != nullptr) {
        if (index == i) {
            return current;
        }
        current = current->getNext();
        index++;
    }
    return nullptr;    
}   

template <typename T>
int LinkedList<T>::getSize(){
    return this->size;
}