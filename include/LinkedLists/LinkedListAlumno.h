#pragma once

#include "Nodos/NodeAlumno.h"

class LinkedListAlumno {

private:
    NodeAlumno* start;
    int size;

public:
    LinkedListAlumno();
    ~LinkedListAlumno();
    
    void add(Alumno& alumno);
    void remove(int index);
    Alumno* get(int index);
    int getSize();
    bool isEmpty();
    void clear();
};
