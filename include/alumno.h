#pragma once

#include <string>
using namespace std;

class LinkedListInscripcion;

class Alumno{
    
private:
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    LinkedListInscripcion* cursosInscritos;

public:
    Alumno();
    Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);
    ~Alumno();
    
    int getId();
    string getNombre();
    string getApellido();
    string getCarrera();
    string getFechaIngreso();

    void setId(int id);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCarrera(string carrera);
    void setFechaIngreso(string fechaIngreso);

    string toString();

    LinkedListInscripcion* getCursosInscritos();
};
