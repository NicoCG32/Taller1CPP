#pragma once

#include "NodoAlumno.h"

class LinkedListAlumno {

private:
    NodoAlumno* start;
    int size;

public:
    LinkedListAlumno();
    ~LinkedListAlumno();

    void add(Alumno value);
    void remove(Alumno value);
    NodoAlumno* get(Alumno value);
    bool isEmpty();

    int getSize();
};