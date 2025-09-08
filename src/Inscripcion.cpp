#include "Inscripcion.h"

Inscripcion::Inscripcion() {}
Inscripcion::Inscripcion(Alumno alumno, Curso curso) : alumno(alumno), curso(curso) {}
Inscripcion::~Inscripcion() {}
Alumno Inscripcion::getAlumno() {
    return alumno;
}
Curso Inscripcion::getCurso() {
    return curso;
}
LinkedList<float> Inscripcion::getNotas() {
    return notas;
}
void Inscripcion::setAlumno(Alumno alumno) {
    this->alumno = alumno;
}
void Inscripcion::setCurso(Curso curso) {
    this->curso = curso;
}
void Inscripcion::agregarNota(float nota) {
    notas.add(nota);
}
std::string Inscripcion::toString() {
    return "Inscripcion[Alumno: " + alumno.toString() + ", Curso: " + curso.toString() + "]";
}
