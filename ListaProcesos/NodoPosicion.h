//
// Created by liwbh on 22/04/23.
//

#ifndef QUIZ_SO_NODOPOSICION_H
#define QUIZ_SO_NODOPOSICION_H
#include <malloc.h>
typedef struct NodoPosicion{
    int i;
    int j;
    struct NodoPosicion* siguiente;
}NodoPosicion;

NodoPosicion *crearNodoPosicion(int i, int j){
    NodoPosicion *nodo = (NodoPosicion*) malloc(sizeof(NodoPosicion));
    nodo->i = i;
    nodo->j = j;
    nodo->siguiente = NULL;
    return nodo;
}

void mostrarNodoPosicion(NodoPosicion *nodo){
    printf("[%d][%d] ",nodo->i, nodo->j);
}

#endif //QUIZ_SO_NODOPOSICION_H
