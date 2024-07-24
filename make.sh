#!/bin/bash
PROJECT_DIR="/home/sergiza/Documents/Chips-Rajoy"
cd "$PROJECT_DIR/build"

cmake "$PROJECT_DIR"        # Configurar el proyecto (genera toda la basura de CMake en /build a partir de CMakeLists.txt)
cmake --build .             # Compilar el proyecto   (utiliza la basura de /build para compilar y generar un ejecutable)
