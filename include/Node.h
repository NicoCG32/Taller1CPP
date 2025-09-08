#pragma once

template <typename T>

class Nodo{

private:
    T value;
    Nodo<T>* next;
    
public:
    Nodo(T value);
    ~Nodo();

    T getValue();
    Nodo<T>* getNext();

    void setValue(T value);
    void setNext(Nodo<T>* next);
    
};
