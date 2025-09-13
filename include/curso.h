#pragma once

#include <string>
using namespace std;

class LinkedListInscripcion;

class Curso{
private:
    int codigo;
    string nombre;
    int max_estudiantes;
    string carrera;
    string nombre_profesor;

    LinkedListInscripcion* alumnosInscritos;

public:
    Curso();
    Curso(int codigo, string nombre, int max_estudiantes, string carrera, string nombre_profesor);
    ~Curso();

    int getCodigo();
    string getNombre();
    int getMaxEstudiantes();
    string getCarrera();
    string getNombreProfesor();

    void setCodigo(int codigo);
    void setNombre(string nombre);
    void setMaxEstudiantes(int max_estudiantes);
    void setCarrera(string carrera);
    void setNombreProfesor(string nombre_profesor);
    
    string toString();

    LinkedListInscripcion* getAlumnosInscritos();
};