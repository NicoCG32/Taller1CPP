#include "Curso.h"

Curso::Curso() {}
Curso::Curso(int id, std::string nombre, int max, std::string carrera, std::string nombre_profesor) {
    this->codigo = id;
    this->nombre = nombre;
    this->max_estudiantes = max;
    this->carrera = carrera;
    this->nombre_profesor = nombre_profesor;

    alumnosInscritos = LinkedList<Inscripcion>();
}
Curso::~Curso() {}
int Curso::getCodigo() {
    return codigo;
}
std::string Curso::getNombre() {
    return nombre;
}
int Curso::getMaxEstudiantes() {
    return max_estudiantes;
}
std::string Curso::getCarrera() {
    return carrera;
}
std::string Curso::getNombreProfesor() {
    return nombre_profesor;
}
void Curso::setCodigo(int codigo) {
    this->codigo = codigo;
}
void Curso::setNombre(std::string nombre) {
    this->nombre = nombre;
}
void Curso::setMaxEstudiantes(int max_estudiantes) {
    this->max_estudiantes = max_estudiantes;
}
void Curso::setCarrera(std::string carrera) {
    this->carrera = carrera;
}
void Curso::setNombreProfesor(std::string nombre_profesor) {
    this->nombre_profesor = nombre_profesor;
}
std::string Curso::toString() {
    return "Codigo: " + std::to_string(codigo) + ", Nombre: " + nombre + ", Max Estudiantes: " + std::to_string(max_estudiantes) + ", Carrera: " + carrera + ", Nombre Profesor: " + nombre_profesor;
}
