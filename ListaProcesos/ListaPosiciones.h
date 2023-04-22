//
// Created by liwbh on 22/04/23.
//

#ifndef QUIZ_SO_LISTAPOSICIONES_H
#define QUIZ_SO_LISTAPOSICIONES_H
#include "NodoPosicion.h"
#include "stdbool.h"

//Lista que almacena la posicion de memoria que se encuentra el proceso
typedef struct ListaPosicion{
    NodoPosicion *primero;
    NodoPosicion *ultimo;
}ListaPosicion;

//Crea y reserva espacio en memoria de la lista
ListaPosicion *crearListaPosicion(){
    ListaPosicion *lista = (ListaPosicion*) malloc(sizeof(ListaPosicion));
    lista->primero = lista->ultimo = NULL;
    return lista;
}

//Verifica si la lista esta vacia
bool estaVacia(ListaPosicion *lista){
    if(lista->primero == NULL){
        return true;
    }else{
        return false;
    }
}

//Inserta un nodo en la lista
void insertarNodoPosicion(ListaPosicion *lista,NodoPosicion *nodo){
    if(estaVacia(lista)){
        lista->primero = nodo;
        lista->ultimo = nodo;
    }else{
        lista->ultimo->siguiente = nodo;
        lista->ultimo = nodo;
    }
}

//Muestra la lista de posiciones
void mostrarListaPosiciones(ListaPosicion *lista){
    NodoPosicion *aux = lista->primero;
    while(aux != NULL){
        mostrarNodoPosicion(aux);
        aux = aux->siguiente;
    }
}


#endif //QUIZ_SO_LISTAPOSICIONES_H
