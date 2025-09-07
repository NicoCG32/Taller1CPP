#include "fecha.h"

#include <string>

Fecha::Fecha(int dia, int mes, int año) : dia(dia), mes(mes), año(año) {}
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAño() { return año; }
void Fecha::setDia(int dia) { this->dia = dia; }
void Fecha::setMes(int mes) { this->mes = mes; }
void Fecha::setAño(int año) { this->año = año; }
std::string Fecha::toString() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(año);
}