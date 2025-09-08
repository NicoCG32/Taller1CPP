#pragma once

/* Los alumnos del sistema contienen un identificador único, nombre, apellido, carrera y fecha de ingreso
a la universidad.
*/

#include <iostream>
#include <string>
#include "Fecha.h"
#include "LinkedList.h"
#include "Inscripcion.h"

class Alumno {
    
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    Fecha fechaIngreso;

    LinkedList<Inscripcion> cursosInscritos;

public:
    Alumno();
    Alumno(int id, std::string nombre, std::string apellido, std::string carrera, Fecha fechaIngreso);
    ~Alumno();

    int getId();
    std::string getNombre();
    std::string getApellido();
    std::string getCarrera();
    Fecha getFechaIngreso();
    LinkedList<Inscripcion> getCursosInscritos();

    void setId(int id);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setCarrera(std::string carrera);
    void setFechaIngreso(Fecha fechaIngreso);

    std::string toString();
    
};