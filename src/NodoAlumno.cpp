#include "nodoAlumno.h"

NodoAlumno::NodoAlumno(Alumno value_){
    value = value_;
    next = nullptr;
}
NodoAlumno::~NodoAlumno() {}
Alumno NodoAlumno::getValue() { return value; }
NodoAlumno* NodoAlumno::getNext() { return next; }
void NodoAlumno::setValue(Alumno value_) { value = value_; }
void NodoAlumno::setNext(NodoAlumno* n) { next = n; }
