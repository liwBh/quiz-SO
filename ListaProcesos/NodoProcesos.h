//
// Created by jurguen on 18/04/23.
//

#ifndef QUIZ_SO_NODOPROCESOS_H
#define QUIZ_SO_NODOPROCESOS_H
#include "malloc.h"
#include "ListaPosiciones.h"
#include <string.h>

typedef struct NodoProcesos{
    char nombre[50];
    int peso;
    int id;
    ListaPosicion *listaPosicion;
    struct NodoProcesos* siguiente;
    struct NodoProcesos* anterior;
}NodoProcesos;

NodoProcesos *crearNodoProcesos(char *nombre, int peso, int id, ListaPosicion *listaPosicion){
    NodoProcesos *nodo = malloc(sizeof(NodoProcesos));
    strcpy(nodo->nombre,nombre);
    nodo->peso = peso;
    nodo->id = id;
    nodo->listaPosicion = listaPosicion;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}

void mostrarNodoProceso(NodoProcesos *nodo){
    printf("Nombre: %s, Peso: %d, id: %d\n",nodo->nombre,nodo->peso,nodo->id);
}

#endif //QUIZ_SO_NODOPROCESOS_H
