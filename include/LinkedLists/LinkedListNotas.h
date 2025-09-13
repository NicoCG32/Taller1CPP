#pragma once

#include "Nodos/NodeNota.h"

class LinkedListNotas {

private:
    NodeNota* start;
    int size;

public:
    LinkedListNotas();
    ~LinkedListNotas();
    
    void add(float nota);
    void remove(int index);
    float get(int index);
    int getSize();
    bool isEmpty();
    void clear();
};