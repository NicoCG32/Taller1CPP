#pragma once
#include "Curso.h"

class NodeCurso {
private:
    Curso curso;
    NodeCurso* next;
public:
    NodeCurso(Curso& curso);
    ~NodeCurso();

    Curso& getCurso();
    NodeCurso* getNext();
    
    void setCurso(Curso& curso);
    void setNext(NodeCurso* next);
};
