@echo off
REM Compila el proyecto antes de ejecutar
g++ -std=gnu++17 -O2 -Wall -Wextra -Iinclude -o build\taller.exe src\App.cpp src\Alumno.cpp src\Curso.cpp src\Inscripcion.cpp src\Sistema.cpp src\LinkedLists\LinkedListAlumno.cpp src\LinkedLists\LinkedListCurso.cpp src\LinkedLists\LinkedListInscripcion.cpp src\LinkedLists\LinkedListNotas.cpp src\Nodos\NodeAlumno.cpp src\Nodos\NodeCurso.cpp src\Nodos\NodeInscripcion.cpp src\Nodos\NodeNota.cpp
if %errorlevel% neq 0 (
	echo Error de compilacion.
	pause
	exit /b
)
REM Ejecutar el programa si la compilación fue exitosa
if exist build\taller.exe (
	build\taller.exe
) else (
	echo Error: No se pudo compilar el programa.
)
pause