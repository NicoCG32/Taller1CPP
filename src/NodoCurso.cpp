#include "nodoCurso.h"

NodoCurso::NodoCurso(Curso value_) {
    value = value_;
    next = nullptr;
}
NodoCurso::~NodoCurso() {}
Curso NodoCurso::getValue() { return value; }
NodoCurso* NodoCurso::getNext() { return next; }
void NodoCurso::setValue(Curso value_) { value = value_; }
void NodoCurso::setNext(NodoCurso* n) { next = n; }

