#pragma once
#include <string>

class Fecha {
    private:
        int dia;
        int mes;
        int año;
        
    public:
        Fecha(int dia, int mes, int año);
        int getDia();
        ~Fecha();
        int getMes();
        int getAño();
        
        std::string toString();
};