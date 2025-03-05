cmake_minimum_required(VERSION 3.30)
project(event_horizon C)

set(CMAKE_C_STANDARD 23)

#2.30.12
include_directories("${CMAKE_SOURCE_DIR}/include/sdl2/include")
link_directories("${CMAKE_SOURCE_DIR}/include/sdl2/lib")

add_executable(event_horizon main.c)

target_link_libraries(event_horizon -lSDL2main -lSDL2)