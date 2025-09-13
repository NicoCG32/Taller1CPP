#include "LinkedLists/LinkedListInscripcion.h"
#include "Inscripcion.h"

#include <iostream>
using namespace std;

LinkedListInscripcion::LinkedListInscripcion() {
    start = nullptr;
    size = 0;
}
LinkedListInscripcion::~LinkedListInscripcion() {
    clear();
}
void LinkedListInscripcion::add(Inscripcion* inscripcion) {
    NodeInscripcion* newNode = new NodeInscripcion(inscripcion);
    if (isEmpty()) {
        start = newNode;
    } else {
        NodeInscripcion* current = start;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}
void LinkedListInscripcion::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return;
    }
    NodeInscripcion* toDelete;
    if (index == 0) {
        toDelete = start;
        start = start->getNext();
    } else {
        NodeInscripcion* current = start;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    delete toDelete;
    size--;
}
Inscripcion* LinkedListInscripcion::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return nullptr;
    }
    NodeInscripcion* current = start;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current->getInscripcion();
}
int LinkedListInscripcion::getSize() {
    return size;
}
bool LinkedListInscripcion::isEmpty() {
    return size == 0;
}
void LinkedListInscripcion::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}