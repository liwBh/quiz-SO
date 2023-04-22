//
// Created by liwbh on 22/04/23.
//

#ifndef QUIZ_SO_NODOPOSICION_H
#define QUIZ_SO_NODOPOSICION_H
#include <malloc.h>

//Nodo que almacena la posicion en la cual esta almacenado el proceso
typedef struct NodoPosicion{
    int i; //Almacena la posicion i de la matriz
    int j; //Almacena la posicion j de la matriz
    struct NodoPosicion* siguiente; //puntero siguiente
}NodoPosicion;

//Crea y reserva la memoria del nodo
NodoPosicion *crearNodoPosicion(int i, int j){
    NodoPosicion *nodo = (NodoPosicion*) malloc(sizeof(NodoPosicion));
    nodo->i = i;
    nodo->j = j;
    nodo->siguiente = NULL;
    return nodo;
}

void mostrarNodoPosicion(NodoPosicion *nodo){
    printf("[%d][%d] ",nodo->i, nodo->j); //Muestra el i y j donde esta almacenado
}

#endif //QUIZ_SO_NODOPOSICION_H
