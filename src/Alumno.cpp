#include "Alumno.h"
#include "LinkedLists/LinkedListInscripcion.h"

using namespace std;

Alumno::Alumno() {
    this->id = 0;
    this->nombre = "";
    this->apellido = "";
    this->carrera = "";
    this->fechaIngreso = "";
    this->cursosInscritos = nullptr;
}
Alumno::Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;
    this->cursosInscritos = new LinkedListInscripcion();
}
Alumno::~Alumno() {
    delete cursosInscritos;
}

int Alumno::getId() {
    return id;
}
string Alumno::getNombre() {
    return nombre;
}
string Alumno::getApellido() {
    return apellido;
}
string Alumno::getCarrera() {
    return carrera;
}
string Alumno::getFechaIngreso() {
    return fechaIngreso;
}
void Alumno::setId(int id) {
    this->id = id;
}
void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}
void Alumno::setApellido(string apellido) {
    this->apellido = apellido;
}
void Alumno::setCarrera(string carrera) {
    this->carrera = carrera;
}
void Alumno::setFechaIngreso(string fechaIngreso) {
    this->fechaIngreso = fechaIngreso;
}
string Alumno::toString() {
    return "ID: " + to_string(id) + ", Nombre: " + nombre + ", Apellido: " + apellido + ", Carrera: " + carrera + ", Fecha de Ingreso: " + fechaIngreso;
}
LinkedListInscripcion* Alumno::getCursosInscritos() {
    return cursosInscritos;
}