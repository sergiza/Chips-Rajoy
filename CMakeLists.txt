cmake_minimum_required(VERSION 3.14)
project(sdlgz)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sdlgz src/main.cpp)

target_compile_features(sdlgz PRIVATE cxx_std_20)
target_link_libraries(sdlgz ${SDL2_LIBRARIES})
