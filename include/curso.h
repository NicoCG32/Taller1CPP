#pragma once
#include <string>

class Curso {
    private:
        std::string codigo;
        std::string nombre;
        int cupoMax;
        std::string carrera;
        std::string profesor;
    public:
        Curso(std::string codigo, std::string nombre, int cupoMax, std::string carrera, std::string profesor)
            : codigo(codigo), nombre(nombre), cupoMax(cupoMax), carrera(carrera), profesor(profesor) {}
        std::string getCodigo() { return codigo; }
        std::string getNombre() { return nombre; } 
        int getCupoMax() { return cupoMax; }
        std::string getCarrera() { return carrera; }
        std::string getProfesor() { return profesor; }
        
};
