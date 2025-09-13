#pragma once

#include "Alumno.h"

class NodeAlumno {
private:
    Alumno alumno;
    NodeAlumno* next;

public:
    NodeAlumno(Alumno& alumno);
    ~NodeAlumno();

    Alumno& getAlumno();
    NodeAlumno* getNext();
    
    void setAlumno(Alumno& alumno);
    void setNext(NodeAlumno* next);
};