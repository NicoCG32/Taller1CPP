#include "Nodos/NodeNota.h"

NodeNota::NodeNota(float nota) {
    this->nota = nota;
    this->next = nullptr;
}

NodeNota::~NodeNota() {
    // Destructor implementation
}

float NodeNota::getNota() {
    return nota;
}

NodeNota* NodeNota::getNext() {
    return next;
}

void NodeNota::setNota(float nota) {
    this->nota = nota;
}

void NodeNota::setNext(NodeNota* next) {
    this->next = next;
}
