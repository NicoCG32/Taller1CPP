#include "Inscripcion.h"

Inscripcion::Inscripcion() {
    this->alumno = nullptr;
    this->curso = nullptr;
    this->notas = new LinkedListNotas();
    this->promedio = 0;
}
Inscripcion::Inscripcion(Alumno* alumno, Curso* curso) {
    this->alumno = alumno;
    this->curso = curso;
    this->notas = new LinkedListNotas();
    this->promedio = 0;
}   
Inscripcion::~Inscripcion() {
    delete notas;
}

Alumno* Inscripcion::getAlumno() {
    return alumno;
}
Curso* Inscripcion::getCurso() {
    return curso;
}
float Inscripcion::getPromedio() {
    return promedio;
}
void Inscripcion::agregarNota(float nota) {
    notas->add(nota);
    calcularPromedio();
}
void Inscripcion::calcularPromedio() {
    if (notas->isEmpty()) {
        promedio = 0;
        return;
    }
    float suma = 0;
    for (int i = 0; i < notas->getSize(); i++) {
        suma += notas->get(i);
    }
    promedio = suma / notas->getSize();
}

string Inscripcion::toString() {
    return "Alumno: " + alumno->toString() + "\nCurso: " + curso->toString() + "\nPromedio: " + to_string(promedio);
}
LinkedListNotas* Inscripcion::getNotas() {
    return notas;
}