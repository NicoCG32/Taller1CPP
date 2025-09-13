#pragma once

class Inscripcion;

class NodeInscripcion {

private:
    Inscripcion* inscripcion;
    NodeInscripcion* next;

public:
    NodeInscripcion(Inscripcion* inscripcion);
    ~NodeInscripcion();
  
    Inscripcion* getInscripcion();
    NodeInscripcion* getNext();
  
    void setInscripcion(Inscripcion* inscripcion);
    void setNext(NodeInscripcion* next);
};