#include "fecha.h"

#include <string>

Fecha::Fecha(){}
Fecha::Fecha(int dia, int mes, int year){ //Intenté usar año pero me tiraba error XDDD, tengo que aprender a escribir code en inglés o usar el UTF-8
    this->dia = dia;
    this->mes = mes;
    this->year = year;
}
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getYear() { return year; }
void Fecha::setDia(int dia) { this->dia = dia; }
void Fecha::setMes(int mes) { this->mes = mes; }
void Fecha::setYear(int year) { this->year = year; }
std::string Fecha::toString() {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(year);
}
Fecha::~Fecha(){}
