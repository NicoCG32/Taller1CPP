#pragma once

#include "alumno.h"

class NodoAlumno {
private:
    Alumno value;
    NodoAlumno* next;
    
public:
    NodoAlumno(Alumno value_);
    ~NodoAlumno();

    Alumno getValue();
    NodoAlumno* getNext();

    void setValue(Alumno value_);
    void setNext(NodoAlumno* n);
};
