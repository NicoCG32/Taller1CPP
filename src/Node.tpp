#include "node.h"
template <typename T>
Nodo<T>::Nodo(T value) {
    this->value = value;
    this->next = nullptr;
}
template <typename T>
Nodo<T>::~Nodo() {}
template <typename T>
T Nodo<T>::getValue() {
    return this->value;
}
template <typename T>
Nodo<T>* Nodo<T>::getNext() {
    return this->next;
}  
template <typename T>
void Nodo<T>::setValue(T value) {
    this->value = value;
}
template <typename T>
void Nodo<T>::setNext(Nodo<T>* next) {
    this->next = next;
}
