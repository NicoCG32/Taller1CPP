#pragma once
#include <string>

class Alumno {
    private:
        int id;
        std::string nombre, apellido, carrera;
        int añoIngreso;
    public:
        Alumno(int id, std::string nombre, std::string apellido, std::string carrera, int añoIngreso)
            : id(id), nombre(nombre), apellido(apellido), carrera(carrera), añoIngreso(añoIngreso) {}
        
        std::string getNombre() { return nombre; }
        std::string getApellido() { return apellido; }
        std::string getCarrera() { return carrera; }
        int getAñoIngreso() { return añoIngreso; }    
};