#include <iostream>
#include "sistema.cpp"

int main() {
    Sistema sistema;
    int op = -1;
    while (op != 0) {
        std::cout << "\n--- Menu ---\n"
                  << "1) Crear alumno\n"
                  << "2) Crear curso\n"
                  << "3) Inscribir\n"
                  << "4) Registrar nota\n"
                  << "5) Reportes\n"
                  << "6) Eliminar alumno\n"
                  << "7) Eliminar curso\n"
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