#pragma once

/*Los cursos tienen un código único, nombre, cantidad máxima de estudiantes, carrera y
nombre del profesor que dicta el curso. */

#include <iostream>
#include <string>

class Curso {
private:
    int codigo;
    std::string nombre;
    int max_estudiantes;
    std::string carrera;
    std::string nombre_profesor;

public:
    Curso(int codigo, std::string nombre, int max_estudiantes, std::string carrera, std::string nombre_profesor);
    ~Curso();

    int getCodigo();
    std::string getNombre();
    int getMaxEstudiantes();
    std::string getCarrera();
    std::string getNombreProfesor();

    void setCodigo(int codigo);
    void setNombre(std::string nombre);
    void setMaxEstudiantes(int max_estudiantes);
    void setCarrera(std::string carrera);
    void setNombreProfesor(std::string nombre_profesor);
    
    std::string toString();

};
