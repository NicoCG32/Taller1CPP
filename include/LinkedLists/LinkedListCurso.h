#pragma once

#include "Nodos/NodeCurso.h"

class LinkedListCurso {
private:
    NodeCurso* start;
    int size;
public:
    LinkedListCurso();
    ~LinkedListCurso();
    
    void add(Curso* curso);
    void remove(int index);
    Curso* get(int index);
    int getSize();
    bool isEmpty();
    void clear();
};