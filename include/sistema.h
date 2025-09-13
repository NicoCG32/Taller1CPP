#pragma once

#include <string>

#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

#include "LinkedLists/LinkedListAlumno.h"
#include "LinkedLists/LinkedListCurso.h"
#include "LinkedLists/LinkedListInscripcion.h"

using namespace std;

class Sistema {
    
private:
    LinkedListAlumno* listaAlumnos;
    LinkedListCurso* listaCursos;

    Alumno* BuscarAlumno(int id);
    Curso* BuscarCurso(int codigo);

public:
    bool iniciar();
    void crearAlumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);
    void buscarAlumno(int id);
    void eliminarAlumno(int id);

    void crearCurso(int codigo, string nombre, int max_estudiantes, string carrera, string nombre_profesor);
    void buscarCurso(int codigo);
    void eliminarCurso(int codigo);

    bool inscribirAlumno(int idAlumno, int idCurso);
    bool desinscribirAlumno(int idAlumno, int idCurso);

    bool registrarNota(int idAlumno, int idCurso, float nota);

    void obtenerAlumnosPorCarrera(string carrera);
    void obtenerCursosPorAlumno(int idAlumno);
    float obtenerPromedioDeCursoDeUnAlumno(int idAlumno, int idCurso);
    float obtenerPromedioGeneralDeUnAlumno(int idAlumno);
};