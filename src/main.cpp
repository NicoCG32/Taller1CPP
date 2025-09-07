#include <iostream>
#include "sistema.cpp"

/*
Gestión de alumnos: Registro, búsqueda y eliminación de alumnos.
Gestión de cursos: Creación, búsqueda y eliminación de cursos.
Inscripción de cursos: Inscribir a alumnos en cursos. También se debe poder suprimir la inscripción a estos.
Gestión de notas: Asignación de notas a alumnos en cursos específicos.
Reportes: Consultar la información de un alumno (cursos inscritos y notas) y calcular promedios de notas por curso y el promedio general del alumno.
*/
int main() {
    Sistema sistema;
    int op = -1;
    while (op != 0) {
        std::cout << "\n--- Menu ---\n"
                  << "1) Registrar alumno\n"
                  << "2) Crear curso\n"
                  << "3) Inscribir\n"
                  << "4) Eliminar inscripcion\n"
                  << "5) Registrar nota\n"
                  << "6) Reportes\n"
                  << "7) Eliminar alumno\n"
                  << "8) Eliminar curso\n"
                  << "0) Salir\nOpcion: ";
        
        std::cin >> op;

        switch (op) {
            case 1:
                //sistema.crearAlumno();
                break;
            case 2:
                //sistema.crearCurso();
                break;
            case 3:
                //sistema.inscribir();
                break;
            case 4:
                //sistema.registrarNota(); 
                break;
            case 5:
                //sistema.reportes();
                break; 
            case 6:
                //sistema.eliminarAlumno();
                break; 
            case 7:
                //sistema.eliminarCurso();
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";    
            }
    };
    return 0;
}