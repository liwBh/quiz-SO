cmake_minimum_required(VERSION 3.25)
project(quiz_SO C)

set(CMAKE_C_STANDARD 11)

add_executable(quiz_SO main.c ListaProcesos/NodoProcesos.h ListaProcesos/ListaProcesos.h Logica/Logica.h  MatrizMemoria/Matriz.h ListaProcesos/NodoPosicion.h ListaProcesos/ListaPosiciones.h)
