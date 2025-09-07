#pragma once

#include "NodoCurso.h"

class LinkedListCurso {
    
private:
    NodoCurso* start;
    int size;

public:
    LinkedListCurso();
    ~LinkedListCurso();

    void add(Curso value);
    void remove(Curso value);
    NodoCurso* get(Curso value);
    bool isEmpty();

    int getSize();
};