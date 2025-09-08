#pragma once

#include "Node.h"

template <typename T>

class LinkedList{
    
private:
    Node<T>* start;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void add(T value);
    void remove(T value);
    T* get(int index);
    int getSize();

};
    
