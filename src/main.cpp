#include <iostream>
#include <string>
#include "sistema.h"

/*
Gestión de alumnos: Registro, búsqueda y eliminación de alumnos.
Gestión de cursos: Creación, búsqueda y eliminación de cursos.
Inscripción de cursos: Inscribir a alumnos en cursos. También se debe poder suprimir la inscripción a estos.
Gestión de notas: Asignación de notas a alumnos en cursos específicos.
Reportes: Consultar la información de un alumno (cursos inscritos y notas) y calcular promedios de notas por curso y el promedio general del alumno.
*/

void registrarAlumno(Sistema sistema);
void crearCurso(Sistema sistema);
void inscribir(Sistema sistema);
void registrarNota(Sistema sistema);
void reportes(Sistema sistema);
void buscarAlumno(Sistema sistema);
void buscarCurso(Sistema sistema);
void eliminarInscripcion(Sistema sistema);
void eliminarAlumno(Sistema sistema);
void eliminarCurso(Sistema sistema);

int main() {
    Sistema sistema;
    int op = -1;
    while (op != 0) {
        std::cout << "\n--- Menu ---\n"
                  << "0) Registrar alumno\n"
                  << "1) Crear curso\n"
                  << "2) Inscribir\n"
                  << "3) Registrar nota\n"
                  << "4) Reportes\n"
                  << "5) Buscar alumno\n"
                  << "6) Buscar curso\n"
                  << "7) Eliminar inscripcion\n"
                  << "8) Eliminar alumno\n"
                  << "9) Eliminar curso\n"
                  << "-1) Salir\nOpcion: ";
        
        std::cin >> op;

        switch (op) {
            case 0:
                registrarAlumno(sistema);
                break;
            case 1:
                crearCurso(sistema);
                break;
            case 2:
                inscribir(sistema);
                break;
            case 3:
                registrarNota(sistema);
                break;
            case 4:
                reportes(sistema);
                break;
            case 5:
                buscarAlumno(sistema);
                break;
            case 6:
                buscarCurso(sistema);
                break;
            case 7:
                eliminarInscripcion(sistema);
                break;
            case 8:
                eliminarAlumno(sistema);
                break;
            case 9:
                eliminarCurso(sistema);
                break;
            case -1:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";    
            }
    };
    return 0;
}

void registrarAlumno(Sistema sistema) {
    
    std::cout << "Registrar Alumno\n" ;
    
    std::string nombre, apellido, carrera;
    int id, dia, mes, year;

    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido: ";
    std::cin >> apellido;
    std::cout << "Carrera: ";
    std::cin >> carrera;
    std::cout << "Fecha de Ingreso (dia/mes/year): ";

    std::cin >> dia >> mes >> year; 

    sistema.registrarAlumno(id, nombre, apellido, carrera, Fecha(dia, mes, year));

    std::cout << "Alumno " << nombre << " " << apellido << " registrado exitosamente.\n";
}
void crearCurso(Sistema sistema) {

    std::cout << "Crear Curso\n" ;

    int codigo, max_estudiantes;
    std::string nombre, carrera, nombre_profesor;
    std::cout << "Codigo: ";
    std::cin >> codigo;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Maximo de Estudiantes: ";
    std::cin >> max_estudiantes;
    std::cout << "Carrera: ";
    std::cin >> carrera;
    std::cout << "Nombre del Profesor: ";
    std::cin >> nombre_profesor;

    Curso c = sistema.crearCurso(codigo, nombre, max_estudiantes, carrera, nombre_profesor);
    std::cout << "Curso " << c.toString() << " creado exitosamente.\n";
}

void inscribir(Sistema sistema) {

    std::cout << "Inscribir Alumno a Curso\n" ;

    int id_alumno, codigo_curso;
    std::cout << "ID del Alumno: ";
    std::cin >> id_alumno;
    std::cout << "Codigo del Curso: ";
    std::cin >> codigo_curso;

    Inscripcion i = sistema.inscribirAlumno(id_alumno, codigo_curso);
    std::cout << "Inscripcion realizada: " << i.toString() << "\n";

}
void eliminarInscripcion(Sistema sistema) {

    std::cout << "Eliminar Inscripcion de Alumno a Curso\n" ;

    int id_alumno, codigo_curso;
    std::cout << "ID del Alumno: ";
    std::cin >> id_alumno;
    std::cout << "Codigo del Curso: ";
    std::cin >> codigo_curso;

    sistema.eliminarInscripcion(id_alumno, codigo_curso);
}

void registrarNota(Sistema sistema) {
    
    std::cout << "Registrar Nota de Alumno en Curso\n" ;

    int id_alumno, codigo_curso;
    float nota;
    std::cout << "ID del Alumno: ";
    std::cin >> id_alumno;
    std::cout << "Codigo del Curso: ";
    std::cin >> codigo_curso;
    std::cout << "Nota: ";
    std::cin >> nota;

    sistema.registrarNota(id_alumno, codigo_curso, nota);
}

void reportes(Sistema sistema) {
 
}

void buscarAlumno(Sistema sistema) {
    
}

void eliminarAlumno(Sistema sistema) {
    
    std::cout << "Eliminar Alumno por ID\n" ;

    int id_alumno;
    std::cout << "ID del Alumno: ";
    std::cin >> id_alumno;

    sistema.eliminarAlumno(id_alumno);
}

void eliminarCurso(Sistema sistema) {
    
    std::cout << "Eliminar Curso por Codigo\n" ;

    int codigo_curso;
    std::cout << "Codigo del Curso: ";
    std::cin >> codigo_curso;

    sistema.eliminarCurso(codigo_curso);
}
