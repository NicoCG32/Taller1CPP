@echo off
setlocal

REM === Ir al directorio del script (raiz del proyecto) ===
cd /d "%~dp0"

REM === Verificar g++ en PATH ===
where g++ >nul 2>nul
if errorlevel 1 (
  echo ❌ No se encontro g++ en PATH. Instala MinGW-w64 y vuelve a intentar.
  pause
  exit /b 1
)

REM === Crear carpeta build si no existe ===
if not exist "build" mkdir "build"

REM === Compilar (usa comodines para src/, LinkedLists/ y Nodos/) ===
echo === Compilando proyecto ===
g++ -std=gnu++17 -O2 -Wall -Wextra -Iinclude ^
  src\*.cpp src\LinkedLists\*.cpp src\Nodos\*.cpp ^
  -o build\taller.exe

if %errorlevel% neq 0 (
  echo ❌ Error de compilacion.
  pause
  exit /b
)

REM === Ejecutar el programa si la compilacion fue exitosa ===
if exist "build\taller.exe" (
  echo ✅ Compilacion exitosa. Ejecutando...
  echo.
  build\taller.exe
) else (
  echo ❌ Error: No se pudo compilar el programa.
)

echo.
pause
