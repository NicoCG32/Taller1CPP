#pragma once

#include "curso.h"

class NodoCurso {
private:
    Curso value;
    NodoCurso* next; 

public:
    NodoCurso(Curso value_);
    ~NodoCurso();

    Curso getValue();
    NodoCurso* getNext();

    void setValue(Curso value_);
    void setNext(NodoCurso* n);
};
