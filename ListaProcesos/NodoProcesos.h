//
// Created by jurguen on 18/04/23.
//

#ifndef QUIZ_SO_NODOPROCESOS_H
#define QUIZ_SO_NODOPROCESOS_H
#include "malloc.h"
#include "ListaPosiciones.h"
#include <string.h>

//Nodo que contiene la informacion del proceso
typedef struct NodoProcesos{
    char nombre[50]; //Nombre del proceso
    int peso; //Peso o tamano que tiene
    int id; //Id del proceso
    ListaPosicion *listaPosicion; //Las pocisiones en las que se encuentra en memoria el proceso
    struct NodoProcesos* siguiente; //Puntero siguiente
    struct NodoProcesos* anterior; //Puntero anterior
}NodoProcesos;

//Se reserva espacio en memoria y crea el nodo proceso.
NodoProcesos *crearNodoProcesos(char *nombre, int peso, int id, ListaPosicion *listaPosicion){
    NodoProcesos *nodo = malloc(sizeof(NodoProcesos)); //Reserva espacio en memoria
    strcpy(nodo->nombre,nombre); //Se copia el nombre
    nodo->peso = peso; //Peso que tiene el proceso
    nodo->id = id; //EL id del proceso
    nodo->listaPosicion = listaPosicion; //Pasamos la lista de posiciones
    nodo->siguiente = NULL; //puntero siguiente
    nodo->anterior = NULL; //puntero anterior
    return nodo; //Retorna el puntero
}

void mostrarNodoProceso(NodoProcesos *nodo){
    printf("Nombre: %s, Peso: %d, id: %d\n",nodo->nombre,nodo->peso,nodo->id); //Muestra la informacion del proceso
}

#endif //QUIZ_SO_NODOPROCESOS_H
