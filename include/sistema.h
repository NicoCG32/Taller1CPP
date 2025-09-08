#pragma once

#include "LinkedList.h"
#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

class Sistema {

private:
    LinkedList<Alumno> alumnos;
    LinkedList<Curso> cursos;

public:
    Sistema();
    ~Sistema();

    Alumno registrarAlumno(int id, std::string nombre, std::string apellido, std::string carrera, Fecha fechaIngreso);
    Curso crearCurso(int codigo, std::string nombre, int max_estudiantes, std::string carrera, std::string nombre_profesor);
    Inscripcion inscribirAlumno(int id_alumno, int codigo_curso);
    void registrarNota(int id_alumno, int codigo_curso, float nota);
    void reportes();
    Alumno buscarAlumno(int id);
    Curso buscarCurso(int codigo);
    void eliminarInscripcion(int id_alumno, int codigo_curso);
    void eliminarAlumno(int id_alumno);
    void eliminarCurso(int codigo_curso);

    
    

};
