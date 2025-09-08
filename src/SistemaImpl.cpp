#include "sistema.h"
#include "LinkedList.h"
#include "Alumno.h"
#include "Curso.h"
#include "Node.h"

#include <iostream>


Sistema::Sistema() {}
Sistema::~Sistema() {}

Alumno Sistema::registrarAlumno(int id, std::string nombre, std::string apellido, std::string carrera, Fecha fechaIngreso) {
    Alumno nuevoAlumno = Alumno(id, nombre, apellido, carrera, fechaIngreso);
    alumnos.add(nuevoAlumno);
    return nuevoAlumno;
}
Curso Sistema::crearCurso(int codigo, std::string nombre, int max_estudiantes, std::string carrera, std::string nombre_profesor) {
    Curso nuevoCurso = Curso(codigo, nombre, max_estudiantes, carrera, nombre_profesor);
    cursos.add(nuevoCurso);
    return nuevoCurso;
}

Inscripcion Sistema::inscribirAlumno(int id_alumno, int codigo_curso) {

    Nodo<Alumno>* nodoAlumno = buscarAlumno(id_alumno);
    Nodo<Curso>* nodoCurso = buscarCurso(codigo_curso);
    
    if (nodoAlumno != nullptr && nodoCurso != nullptr) {
        
        if (nodoCurso->getValue().getCarrera() != nodoAlumno->getValue().getCarrera()) {
            std::cout << "Error: El alumno no pertenece a la carrera del curso." << std::endl;
            return Inscripcion();
        } else if (nodoCurso->getValue().getMaxEstudiantes() <= nodoCurso->getValue().getAlumnosInscritos().getSize()) {
            std::cout << "Error: El curso ha alcanzado su capacidad máxima de estudiantes." << std::endl;
            return Inscripcion();
        } else {
            Inscripcion nuevaInscripcion(nodoAlumno->getValue(), nodoCurso->getValue());
            nodoAlumno->getValue().getCursosInscritos().add(nuevaInscripcion);
            nodoCurso->getValue().getAlumnosInscritos().add(nuevaInscripcion);
            std::cout << "Alumno con ID " << id_alumno << " inscrito en el curso con codigo " << codigo_curso << ".\n";
            return nuevaInscripcion;
        }

    } else if (nodoAlumno == nullptr) {
        std::cout << "Error: Alumno con ID " << id_alumno << " no encontrado.\n";
    } else if (nodoCurso == nullptr) {
        std::cout << "Error: Curso con codigo " << codigo_curso << " no encontrado.\n";
    }

    return Inscripcion();
}

void Sistema::registrarNota(int id_alumno, int codigo_curso, float nota) {
    
    Nodo<Alumno>* nodoAlumno = buscarAlumno(id_alumno);
    Nodo<Curso>* nodoCurso = buscarCurso(codigo_curso);


}

Alumno Sistema::buscarAlumno(int id) {
   
}

Curso Sistema::buscarCurso(int codigo) {
   
}

