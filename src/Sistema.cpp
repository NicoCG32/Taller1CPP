#include <iostream>

#include "Sistema.h"
#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

using namespace std;

// Métodos de apoyo
Alumno* Sistema::BuscarAlumno(int id) {
    for (int i = 0; i < listaAlumnos->getSize(); i++) {
        Alumno* alumno = listaAlumnos->get(i);
        if (alumno->getId() == id) {
            return alumno;
        }
    }
    return nullptr;
}
Curso* Sistema::BuscarCurso(int codigo) {
    for (int i = 0; i < listaCursos->getSize(); i++) {
        Curso* curso = listaCursos->get(i);
        if (curso->getCodigo() == codigo) {
            return curso;
        }
    }
    return nullptr;
}

// Métodos para APP

bool Sistema::iniciar() {
    listaAlumnos = new LinkedListAlumno();
    listaCursos = new LinkedListCurso();

    // Datos de prueba
    crearAlumno(1, "Mateo", "Godoy", "ICCI", "01/03/2020");
    crearAlumno(2, "Maria", "Gomez", "Medicina", "15/08/2019");
    crearAlumno(3, "Luis", "Martinez", "Derecho", "10/01/2021");

    crearCurso(101, "Estructura de Datos", 30, "ICCI", "José Veas");
    crearCurso(102, "Nefrología", 25, "Medicina", "Dr House");
    crearCurso(103, "Derecho Penal", 20, "Derecho", "Saul Goodman");

    cout << "Sistema iniciado." << endl;
    bool inscripcion1 = inscribirAlumno(1, 101);
    bool inscripcion2 = inscribirAlumno(2, 102);
    bool inscripcion3 = inscribirAlumno(3, 103);
    
    return inscripcion1 && inscripcion2 && inscripcion3;
}

void Sistema::crearAlumno(int id, string nombre, string apellido, string carrera, string fechaIngreso) {
    Alumno* nuevo_alumno = new Alumno(id, nombre, apellido, carrera, fechaIngreso);
    cout << "Alumno creado: " << nuevo_alumno->toString() << endl;
    listaAlumnos->add(*nuevo_alumno);
}

void Sistema::buscarAlumno(int id) {
    cout << "Buscando Alumno con ID: " << id << endl;

    for (int i = 0; i < listaAlumnos->getSize(); i++) {
        Alumno* alumno = listaAlumnos->get(i);
        if (alumno->getId() == id) {
            cout << "Alumno encontrado: " << alumno->toString() << endl;
            return;
        }
    }
}

void Sistema::eliminarAlumno(int id) {
    cout << "Eliminando Alumno con ID: " << id << endl;

    for (int i = 0; i < listaAlumnos->getSize(); i++) {
        Alumno* alumno = listaAlumnos->get(i);
        if (alumno->getId() == id) {
            listaAlumnos->remove(i);
            cout << "Alumno eliminado." << endl;
            return;
        }
    }
    cout << "Alumno no encontrado." << endl;
}

void Sistema::crearCurso(int codigo, string nombre, int max_estudiantes, string carrera, string nombre_profesor) {
    Curso* nuevo_curso = new Curso(codigo, nombre, max_estudiantes, carrera, nombre_profesor);
    cout << "Curso creado: " << nuevo_curso->toString() << endl;
    listaCursos->add(nuevo_curso);
}

void Sistema::buscarCurso(int codigo) {
    cout << "Buscando Curso con Codigo: " << codigo << endl;

    for (int i = 0; i < listaCursos->getSize(); i++) {
        Curso* curso = listaCursos->get(i);
        if (curso->getCodigo() == codigo) {
            cout << "Curso encontrado: " << curso->toString() << endl;
            return;
        }
    }
}

void Sistema::eliminarCurso(int codigo) {
    cout << "Eliminando Curso con Codigo: " << codigo << endl;

    for (int i = 0; i < listaCursos->getSize(); i++) {
        Curso* curso = listaCursos->get(i);
        if (curso->getCodigo() == codigo) {
            listaCursos->remove(i);
            cout << "Curso eliminado." << endl;
            return;
        }
    }
    cout << "Curso no encontrado." << endl;
}

bool Sistema::inscribirAlumno(int idAlumno, int idCurso) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    Curso* curso = BuscarCurso(idCurso);
    
    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return false;
    }
    if (curso == nullptr) {
        cout << "Curso con Codigo " << idCurso << " no encontrado." << endl;
        return false;
    }
    
    if (curso->getAlumnosInscritos()->getSize() >= curso->getMaxEstudiantes()) {
        cout << "Curso " << curso->getNombre() << " ya ha alcanzado el maximo de estudiantes." << endl;
        return false;
    }
    
    Inscripcion* nueva_inscripcion = new Inscripcion(alumno, curso);
    alumno->getCursosInscritos()->add(nueva_inscripcion);
    curso->getAlumnosInscritos()->add(nueva_inscripcion);

    cout << "Inscribiendo Alumno " << alumno->getNombre() << " en el Curso " << curso->getNombre() << endl;
    return true;
}

bool Sistema::desinscribirAlumno(int idAlumno, int idCurso) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    Curso* curso = BuscarCurso(idCurso);

    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return false;
    }
    if (curso == nullptr) {
        cout << "Curso con Codigo " << idCurso << " no encontrado." << endl;
        return false;
    }

    LinkedListInscripcion* inscripcionesAlumno = alumno->getCursosInscritos();
    LinkedListInscripcion* inscripcionesCurso = curso->getAlumnosInscritos();

    for (int i = 0; i < inscripcionesAlumno->getSize(); i++) {
        Inscripcion* inscripcion = inscripcionesAlumno->get(i);
        if (inscripcion->getCurso()->getCodigo() == idCurso) {
            inscripcionesAlumno->remove(i);
            break;
        }
    }

    for (int i = 0; i < inscripcionesCurso->getSize(); i++) {
        Inscripcion* inscripcion = inscripcionesCurso->get(i);
        if (inscripcion->getAlumno()->getId() == idAlumno) {
            inscripcionesCurso->remove(i);
            break;
        }
    }

    cout << "Desinscribiendo Alumno " << alumno->getNombre() << " del Curso " << curso->getNombre() << endl;
    return true;
}

bool Sistema::registrarNota(int idAlumno, int idCurso, float nota) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    Curso* curso = BuscarCurso(idCurso);

    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return false;
    }
    if (curso == nullptr) {
        cout << "Curso con Codigo " << idCurso << " no encontrado." << endl;
        return false;
    }

    LinkedListInscripcion* inscripciones = alumno->getCursosInscritos();
    for (int i = 0; i < inscripciones->getSize(); i++) {
        Inscripcion* inscripcion = inscripciones->get(i);
        if (inscripcion->getCurso()->getCodigo() == idCurso) {
            inscripcion->agregarNota(nota);
            cout << "Registrando Nota " << nota << " para Alumno " << alumno->getNombre() << " en el Curso " << curso->getNombre() << endl;
            return true;
        }
    }

    cout << "El Alumno " << alumno->getNombre() << " no esta inscrito en el Curso " << curso->getNombre() << endl;
    return false;
}

void Sistema::obtenerAlumnosPorCarrera(string carrera) {
    cout << "Obteniendo Alumnos de la Carrera: " << carrera << endl;
    for (int i = 0; i < listaAlumnos->getSize(); i++) {
        Alumno* alumno = listaAlumnos->get(i);
        if (alumno->getCarrera() == carrera) {
            cout << alumno->toString() << endl;
        }
    }
}

void Sistema::obtenerCursosPorAlumno(int idAlumno) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return;
    }

    cout << "Obteniendo Cursos para el Alumno: " << alumno->getNombre() << endl;
    LinkedListInscripcion* inscripciones = alumno->getCursosInscritos();
    for (int i = 0; i < inscripciones->getSize(); i++) {
        Inscripcion* inscripcion = inscripciones->get(i);
        cout << inscripcion->getCurso()->toString() << endl;
    }
}

float Sistema::obtenerPromedioDeCursoDeUnAlumno(int idAlumno, int idCurso) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    Curso* curso = BuscarCurso(idCurso);

    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return -1;
    }
    if (curso == nullptr) {
        cout << "Curso con Codigo " << idCurso << " no encontrado." << endl;
        return -1;
    }

    LinkedListInscripcion* inscripciones = alumno->getCursosInscritos();
    for (int i = 0; i < inscripciones->getSize(); i++) {
        Inscripcion* inscripcion = inscripciones->get(i);
        if (inscripcion->getCurso()->getCodigo() == idCurso) {
            cout << "Promedio de " << alumno->getNombre() << " en el Curso " << curso->getNombre() << " es: " << inscripcion->getPromedio() << endl;
            return inscripcion->getPromedio();
        }
    }

    cout << "El Alumno " << alumno->getNombre() << " no esta inscrito en el Curso " << curso->getNombre() << endl;
    return -1;
}

float Sistema::obtenerPromedioGeneralDeUnAlumno(int idAlumno) {
    Alumno* alumno = BuscarAlumno(idAlumno);
    if (alumno == nullptr) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return -1;
    }

    LinkedListInscripcion* inscripciones = alumno->getCursosInscritos();
    float sumaPromedios = 0;
    int contadorCursos = 0;

    for (int i = 0; i < inscripciones->getSize(); i++) {
        Inscripcion* inscripcion = inscripciones->get(i);
        sumaPromedios += inscripcion->getPromedio();
        contadorCursos++;
    }

    if (contadorCursos == 0) {
        cout << "El Alumno " << alumno->getNombre() << " no esta inscrito en ningun curso." << endl;
        return 0;
    }

    float promedioGeneral = sumaPromedios / contadorCursos;
    cout << "Promedio General de " << alumno->getNombre() << " es: " << promedioGeneral << endl;
    return promedioGeneral;
}
