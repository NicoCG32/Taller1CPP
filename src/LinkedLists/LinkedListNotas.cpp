#include "LinkedLists/LinkedListNotas.h"

#include <iostream>
using namespace std;

LinkedListNotas::LinkedListNotas() {
    start = nullptr;
    size = 0;
}
LinkedListNotas::~LinkedListNotas() {
    clear();
}
void LinkedListNotas::add(float nota) {
    NodeNota* newNode = new NodeNota(nota);
    if (isEmpty()) {
        start = newNode;
    } else {
        NodeNota* current = start;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}
void LinkedListNotas::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return;
    }
    NodeNota* toDelete;
    if (index == 0) {
        toDelete = start;
        start = start->getNext();
    } else {
        NodeNota* current = start;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        toDelete = current->getNext();
        current->setNext(toDelete->getNext());
    }
    delete toDelete;
    size--;
}
float LinkedListNotas::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Error:Índice fuera de rango" << endl;
        return 0;
    }
    NodeNota* current = start;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current->getNota();
}
int LinkedListNotas::getSize() {
    return size;
}
bool LinkedListNotas::isEmpty() {
    return size == 0;
}
void LinkedListNotas::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}
