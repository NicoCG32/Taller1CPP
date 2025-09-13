#include "App.h"
#include <iostream>
#include <string>
using namespace std;

// Función MAIN
int main() {
    App app;
    return app.main();
}

int App::main() {
    bool sistemaIniciado = sistema.iniciar();
    if (!sistemaIniciado) {
        cerr << "Error al iniciar el sistema.\n";
        return 1;
    }       
    cout << "Sistema iniciado correctamente!\n";

    int opcion = 0;

    while (opcion != -1) {
        cout << "\nMenu Principal:\n";
        cout << "1. Menu Alumno\n";
        cout << "2. Menu Curso\n";
        cout << "3. Menu Inscripcion\n";
        cout << "4. Registrar Nota\n";
        cout << "5. Menu Reporte\n";
        cout << "-1. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuAlumno();
                break;
            case 2:
                menuCurso();
                break;
            case 3:
                menuInscripcion();
                break;
            case 4:
                registrarNota();
                break;
            case 5:
                menuReporte();
                break;
            case -1:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
    return 0;
}

void App::menuAlumno() {
    cout << "Menu Alumno seleccionado.\n";
    
    int opcion = 0;
    while (opcion != -1) {
        cout << "\nMenu Alumno:\n";
        cout << "1. Crear Alumno\n";
        cout << "2. Buscar Alumno\n";
        cout << "3. Eliminar Alumno\n";
        cout << "-1. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearAlumno();
                break;
            case 2:
                buscarAlumno();
                break;
            case 3:
                eliminarAlumno();
                break;
            case -1:
                cout << "Volviendo al Menu Principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
        
    }
}

void App::menuCurso() {
    cout << "Menu Curso seleccionado.\n";
    int opcion = 0;
    while (opcion != -1) {
        cout << "\nMenu Curso:\n";
        cout << "1. Crear Curso\n";
        cout << "2. Buscar Curso\n";
        cout << "3. Eliminar Curso\n";
        cout << "-1. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearCurso();
                break;
            case 2:
                buscarCurso();
                break;
            case 3:
                eliminarCurso();
                break;
            case -1:
                cout << "Volviendo al Menu Principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

void App::menuInscripcion() {
    cout << "Menu Inscripcion seleccionado.\n";
    int opcion = 0;
    while (opcion != -1) {
        cout << "\nMenu Inscripcion:\n";
        cout << "1. Inscribir Alumno\n";
        cout << "2. Desinscribir Alumno\n";
        cout << "-1. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inscribirAlumno();
                break;
            case 2:
                desinscribirAlumno();
                break;
            case -1:
                cout << "Volviendo al Menu Principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

void App::registrarNota(){
    cout << "Registrar Nota seleccionado.\n";
    float nota;
    int idAlumno, idCurso;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;
    cout << "Ingrese ID del Curso: ";
    cin >> idCurso;
    cout << "Ingrese la Nota: ";
    cin >> nota;
    if (sistema.registrarNota(idAlumno, idCurso, nota)) {
        cout << "Nota registrada exitosamente.\n";
    } else {
        cout << "Error al registrar la nota. Verifique los IDs ingresados.\n";
    }
}

void App::menuReporte() {
    cout << "Menu Reporte seleccionado.\n";
    int opcion = 0;
    while (opcion != -1) {
        cout << "\nMenu Reporte:\n";
        cout << "1. Obtener Alumnos por Carrera\n";
        cout << "2. Obtener Cursos por Alumno\n";
        cout << "3. Obtener Promedio de Curso de un Alumno\n";
        cout << "4. Obtener Promedio General de un Alumno\n";
        cout << "-1. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                obtenerAlumnosPorCarrera();
                break;
            case 2:
                obtenerCursosPorAlumno();
                break;
            case 3:
                obtenerPromedioDeCursoDeUnAlumno();
                break;
            case 4:
                obtenerPromedioGeneralDeUnAlumno();
                break;
            case -1:
                cout << "Volviendo al Menu Principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

// Métodos de funcionalidad

void App::crearAlumno() {
    int id;
    string nombre, apellido, carrera, fechaIngreso;

    cout << "Ingrese ID del Alumno: ";
    cin >> id;
    cout << "Ingrese Nombre del Alumno: ";
    cin >> nombre;
    cout << "Ingrese Apellido del Alumno: ";
    cin >> apellido;
    cout << "Ingrese Carrera del Alumno: ";
    cin >> carrera;
    cout << "Ingrese Fecha de Ingreso del Alumno (DD/MM/AAAA): ";
    cin >> fechaIngreso;

    sistema.crearAlumno(id, nombre, apellido, carrera, fechaIngreso);
}

void App::buscarAlumno() {
    int id;
    cout << "Ingrese ID del Alumno a buscar: ";
    cin >> id;

    sistema.buscarAlumno(id);
}

void App::eliminarAlumno() {
    int id;
    cout << "Ingrese ID del Alumno a eliminar: ";
    cin >> id;

    sistema.eliminarAlumno(id);
}

void App::crearCurso() {
    int codigo, max_estudiantes;
    string nombre, carrera, nombre_profesor;

    cout << "Ingrese ID del Curso: ";
    cin >> codigo;
    cout << "Ingrese Nombre del Curso: ";
    cin >> nombre;
    cout << "Ingrese Maximo de Estudiantes del Curso: ";
    cin >> max_estudiantes;
    cout << "Ingrese Carrera del Curso: ";
    cin >> carrera;
    cout << "Ingrese Nombre del Profesor del Curso: ";
    cin >> nombre_profesor;

    sistema.crearCurso(codigo, nombre, max_estudiantes, carrera, nombre_profesor);
}

void App::buscarCurso() {
    int id;
    cout << "Ingrese ID del Curso a buscar: ";
    cin >> id;

    sistema.buscarCurso(id);
}

void App::eliminarCurso() {
    int id;
    cout << "Ingrese ID del Curso a eliminar: ";
    cin >> id;

    sistema.eliminarCurso(id);
}

void App::inscribirAlumno() {
    int idAlumno, idCurso;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;
    cout << "Ingrese ID del Curso: ";
    cin >> idCurso;

    sistema.inscribirAlumno(idAlumno, idCurso);
}

void App::desinscribirAlumno() {
    int idAlumno, idCurso;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;
    cout << "Ingrese ID del Curso: ";
    cin >> idCurso;

    sistema.desinscribirAlumno(idAlumno, idCurso);
}

void App::obtenerAlumnosPorCarrera() {
    string carrera;
    cout << "Ingrese Carrera: ";
    cin >> carrera;

    sistema.obtenerAlumnosPorCarrera(carrera);
}

void App::obtenerCursosPorAlumno() {
    int idAlumno;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;

    sistema.obtenerCursosPorAlumno(idAlumno);
}

void App::obtenerPromedioDeCursoDeUnAlumno() {
    int idAlumno, idCurso;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;
    cout << "Ingrese ID del Curso: ";
    cin >> idCurso;

    sistema.obtenerPromedioDeCursoDeUnAlumno(idAlumno, idCurso);
}

void App::obtenerPromedioGeneralDeUnAlumno() {
    int idAlumno;
    cout << "Ingrese ID del Alumno: ";
    cin >> idAlumno;

    sistema.obtenerPromedioGeneralDeUnAlumno(idAlumno);
}

