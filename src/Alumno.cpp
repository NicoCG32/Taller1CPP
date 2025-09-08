#include "Alumno.h"

Alumno::Alumno(){}
Alumno::Alumno(int id, std::string nombre, std::string apellido, std::string carrera, Fecha fechaIngreso) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;

    cursosInscritos = LinkedList<Inscripcion>();
}
Alumno::~Alumno() {}
int Alumno::getId() {
    return id;
}
std::string Alumno::getNombre() {
    return nombre;
}
std::string Alumno::getApellido() {
    return apellido;
}
std::string Alumno::getCarrera() {
    return carrera;
}
Fecha Alumno::getFechaIngreso() {
    return fechaIngreso;
}
void Alumno::setId(int id) {
    this->id = id;
}
void Alumno::setNombre(std::string nombre) {
    this->nombre = nombre;
}
void Alumno::setApellido(std::string apellido) {
    this->apellido = apellido;
}
void Alumno::setCarrera(std::string carrera) {
    this->carrera = carrera;
}
void Alumno::setFechaIngreso(Fecha fechaIngreso) {
    this->fechaIngreso = fechaIngreso;
}
std::string Alumno::toString() {
    return "ID: " + std::to_string(id) + ", Nombre: " + nombre + ", Apellido: " + apellido + ", Carrera: " + carrera + ", Fecha de Ingreso: " + fechaIngreso.toString();
}
