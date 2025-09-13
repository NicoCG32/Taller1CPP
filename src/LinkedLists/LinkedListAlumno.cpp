#include "LinkedLists/LinkedListAlumno.h"

#include <iostream>
using namespace std;

LinkedListAlumno::LinkedListAlumno() {
    start = nullptr;
    size = 0;
}
LinkedListAlumno::~LinkedListAlumno() {
    clear();
}
void LinkedListAlumno::add(Alumno& alumno) {
    NodeAlumno* newNode = new NodeAlumno(alumno);
    if (isEmpty()) {
        start = newNode;
    } else {
        NodeAlumno* current = start;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}
void LinkedListAlumno::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: Índice fuera de rango" << endl;
        return;
    }
    NodeAlumno* toDelete;
    if (index == 0) {
        toDelete = start;
        start = start->getNext();
    } else {
        NodeAlumno* current = start;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    delete toDelete;
    size--;
}
Alumno* LinkedListAlumno::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: Índice fuera de rango" << endl;
        return nullptr;
    }
    NodeAlumno* current = start;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return &current->getAlumno();
}
int LinkedListAlumno::getSize() {
    return size;
}
bool LinkedListAlumno::isEmpty() {
    return size == 0;
}
void LinkedListAlumno::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}