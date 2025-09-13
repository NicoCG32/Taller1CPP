#pragma once

#include "Alumno.h"
#include "Curso.h"
#include "LinkedLists/LinkedListNotas.h"

class Inscripcion {

private:
    Alumno* alumno;
    Curso* curso;
    LinkedListNotas* notas;
    float promedio;

public:
    Inscripcion();
    Inscripcion(Alumno* alumno, Curso* curso);
    ~Inscripcion();
    
    Alumno* getAlumno();
    Curso* getCurso();
    float getPromedio();

    void agregarNota(float nota);
    void calcularPromedio();

    string toString();

    LinkedListNotas* getNotas();
};