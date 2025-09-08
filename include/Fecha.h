#pragma once
#include <string>

class Fecha {
    private:
        int dia;
        int mes;
        int year;
        
    public:
        Fecha();
        Fecha(int dia, int mes, int year);
        ~Fecha();
        int getDia();
        int getMes();
        int getYear();
        
        void setDia(int dia);
        void setMes(int mes);
        void setYear(int year);
        
        std::string toString();
};