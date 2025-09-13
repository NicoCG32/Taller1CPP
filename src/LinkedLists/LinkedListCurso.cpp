#include "LinkedLists/LinkedListCurso.h"

#include <iostream>
using namespace std;

LinkedListCurso::LinkedListCurso() {
    start = nullptr;
    size = 0;
}
LinkedListCurso::~LinkedListCurso() {
    clear();
}
void LinkedListCurso::add(Curso* curso) {
    NodeCurso* newNode = new NodeCurso(*curso);
    if (isEmpty()) {
        start = newNode;
    } else {
        NodeCurso* current = start;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}
void LinkedListCurso::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return;
    }
    NodeCurso* toDelete;
    if (index == 0) {
        toDelete = start;
        start = start->getNext();
    } else {
        NodeCurso* current = start;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    delete toDelete;
    size--;
}
Curso* LinkedListCurso::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return nullptr;
    }
    NodeCurso* current = start;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return &current->getCurso();
}
int LinkedListCurso::getSize() {
    return size;
}
bool LinkedListCurso::isEmpty() {
    return size == 0;
}
void LinkedListCurso::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}