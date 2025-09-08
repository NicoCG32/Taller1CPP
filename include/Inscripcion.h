#pragma once
#include "Alumno.h"
#include "Curso.h"
#include "LinkedList.h"

class Inscripcion {

private:
    Alumno alumno;
    Curso curso;
    LinkedList<float> notas;

public:
    Inscripcion();
    Inscripcion(Alumno alumno, Curso curso);
    ~Inscripcion();

    Alumno getAlumno();
    Curso getCurso();
    LinkedList<float> getNotas();

    void setAlumno(Alumno alumno);
    void setCurso(Curso curso);
    void agregarNota(float nota);

    std::string toString();
    
};