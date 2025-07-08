#!/bin/bash
PROJECT_DIR="$(pwd)"
cd "$PROJECT_DIR/build"

cmake "$PROJECT_DIR"        # Configure (generate CMake stuff in /build from CMakeLists.txt info)
cmake --build .             # Compile   (use /build stuff to compile)
