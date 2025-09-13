#include "Curso.h"
#include "LinkedLists/LinkedListInscripcion.h"

using namespace std;

Curso::Curso() {
    this->codigo = 0;
    this->nombre = "";
    this->max_estudiantes = 0;
    this->carrera = "";
    this->nombre_profesor = "";

    this->alumnosInscritos = nullptr;
}
Curso::Curso(int codigo, string nombre, int max_estudiantes, string carrera, string nombre_profesor) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->max_estudiantes = max_estudiantes;
    this->carrera = carrera;
    this->nombre_profesor = nombre_profesor;

    this->alumnosInscritos = new LinkedListInscripcion();
}
Curso::~Curso() {
    delete alumnosInscritos;
}
int Curso::getCodigo() {
    return codigo;
}
string Curso::getNombre() {
    return nombre;
}
int Curso::getMaxEstudiantes() {
    return max_estudiantes;
}
string Curso::getCarrera() {
    return carrera;
}
string Curso::getNombreProfesor() {
    return nombre_profesor;
}
void Curso::setCodigo(int codigo) {
    this->codigo = codigo;
}
void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}
void Curso::setMaxEstudiantes(int max_estudiantes) {
    this->max_estudiantes = max_estudiantes;
}
void Curso::setCarrera(string carrera) {
    this->carrera = carrera;
}
void Curso::setNombreProfesor(string nombre_profesor) {
    this->nombre_profesor = nombre_profesor;
}
string Curso::toString() {
    return "Codigo: " + to_string(codigo) + ", Nombre: " + nombre + ", Max Estudiantes: " + to_string(max_estudiantes) + ", Carrera: " + carrera + ", Nombre Profesor: " + nombre_profesor;
}
LinkedListInscripcion* Curso::getAlumnosInscritos() {
    return alumnosInscritos;
}