#pragma once

#include "Sistema.h"

class App {

private:
    Sistema sistema;

public:
    int main();
    
    void menuAlumno();
    void menuCurso();
    void menuInscripcion();
    void registrarNota();
    void menuReporte();
    
    void crearAlumno();
    void buscarAlumno();
    void eliminarAlumno();
    
    void crearCurso();
    void buscarCurso();
    void eliminarCurso();
    
    void inscribirAlumno();
    void desinscribirAlumno();
    
    void obtenerAlumnosPorCarrera();
    void obtenerCursosPorAlumno();
    void obtenerPromedioDeCursoDeUnAlumno();
    void obtenerPromedioGeneralDeUnAlumno();
};