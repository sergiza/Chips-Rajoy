cmake_minimum_required(VERSION 3.14)
project(Chips-Rajoy VERSION 0.1.0)

# cpp20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED) 
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(Chips-Rajoy
    src/main.cpp
    src/Game.cpp
    src/Graphics.cpp
    src/Audio.cpp
    src/Font.cpp
)
target_link_libraries(Chips-Rajoy
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_mixer::SDL2_mixer
    SDL2_ttf::SDL2_ttf
)
