#pragma once

#include "../Nodos/NodeInscripcion.h"

class LinkedListInscripcion {

private:
    NodeInscripcion* start;
    int size;

public:
    LinkedListInscripcion();
    ~LinkedListInscripcion();

    void add(Inscripcion* inscripcion);
    void remove(int index);
    Inscripcion* get(int index);
    int getSize();
    bool isEmpty();
    void clear();
};