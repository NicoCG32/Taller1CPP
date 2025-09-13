#include "Nodos/NodeInscripcion.h"
#include "Inscripcion.h"

NodeInscripcion::NodeInscripcion(Inscripcion* inscripcion) {
    this->inscripcion = inscripcion;
    this->next = nullptr;
}
NodeInscripcion::~NodeInscripcion() {
    delete this->inscripcion;
}

Inscripcion* NodeInscripcion::getInscripcion() {
    return this->inscripcion;
}
NodeInscripcion* NodeInscripcion::getNext() {
    return this->next;
}

void NodeInscripcion::setInscripcion(Inscripcion* inscripcion) {
    this->inscripcion = inscripcion;
}
void NodeInscripcion::setNext(NodeInscripcion* next) {
    this->next = next;
}