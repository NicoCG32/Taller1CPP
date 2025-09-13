#include "Nodos/NodeAlumno.h"

NodeAlumno::NodeAlumno(Alumno& alumno) {
    this->alumno = alumno;
    this->next = nullptr;
}
NodeAlumno::~NodeAlumno() {}

Alumno& NodeAlumno::getAlumno() {
    return this->alumno;
}
NodeAlumno* NodeAlumno::getNext() {
    return this->next;
}

void NodeAlumno::setAlumno(Alumno& alumno) {
    this->alumno = alumno;
}
void NodeAlumno::setNext(NodeAlumno* next) {
    this->next = next;
}