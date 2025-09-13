#include "Nodos/NodeCurso.h"

using namespace std;

NodeCurso::NodeCurso(Curso& curso) {
    this->curso = curso;
    this->next = nullptr;
}
NodeCurso::~NodeCurso() {}

Curso& NodeCurso::getCurso() {
    return this->curso;
}
NodeCurso* NodeCurso::getNext() {
    return this->next;
}

void NodeCurso::setCurso(Curso& curso) {
    this->curso = curso;
}
void NodeCurso::setNext(NodeCurso* next) {
    this->next = next;
}