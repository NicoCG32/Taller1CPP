#pragma once

class NodeNota {
    
private:
    float nota;
    NodeNota* next;
    
public:
    NodeNota(float nota);
    ~NodeNota();
    float getNota();
    NodeNota* getNext();
    void setNota(float nota);
    void setNext(NodeNota* next);
};
