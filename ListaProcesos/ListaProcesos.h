//
// Created by jurguen on 18/04/23.
//

#ifndef QUIZ_SO_LISTAPROCESOS_H
#define QUIZ_SO_LISTAPROCESOS_H
#include "NodoProcesos.h"
#include "stdbool.h"

typedef struct ListaProcesos{
    NodoProcesos *primero;
    NodoProcesos *ultimo;
}ListaProcesos;

ListaProcesos *crearListaProcesos(){
    ListaProcesos *lista = (ListaProcesos*) malloc(sizeof(ListaProcesos));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

bool listaVacia(ListaProcesos *lista){
    if(lista->primero == NULL){
        return true;
    }else{
        return false;
    }
}

//Inserta un NodoProceso dentro de la lista de procesos
void insertar(ListaProcesos *lista, NodoProcesos *nodo){
    if(listaVacia(lista)){
        lista->primero = nodo;
        lista->ultimo = nodo;
    }else{
        lista->ultimo->siguiente = nodo;
        nodo->anterior = lista->ultimo;
        lista->ultimo = nodo;
    }
}

void eliminarProcesoEsperando(ListaProcesos *lista, NodoProcesos *nodoEliminar){ //ELimina un nodo (ficha) de una lista de fichas

    if(listaVacia(lista)){ //Primero se verifica que la lista no este vacia
    }else{ //En caso de no estar vacia
        NodoProcesos *aux1 = lista->primero; //Un nodo que recorre la lista
        NodoProcesos *aux2 = crearNodoProcesos(nodoEliminar->nombre,nodoEliminar->peso,nodoEliminar->id,nodoEliminar->listaPosicion);

        while (aux1 != NULL){
            //Si la ficha a eliminar es la ultima igualamos las variables de la lista a NULL
            if(aux2->id == lista->ultimo->id){
                lista->primero = NULL;
                lista->ultimo = NULL;
                //si elimina la ultima ficha y solo hay 2 fichas
            }else if(  (aux2->id == lista->ultimo->id) && (lista->primero->siguiente == lista->ultimo) && (lista->ultimo->anterior == lista->primero)){
                lista->ultimo = lista->primero;
                lista->primero->siguiente = NULL;
                lista->primero->anterior = NULL;

                //si elimina la primera ficha y solo hay 2 fichas
            }else if( (aux2->id == lista->primero->id) && (lista->ultimo->anterior == lista->primero) && (lista->primero->siguiente == lista->ultimo) ){
                lista->primero = lista->ultimo;
                lista->ultimo->anterior = NULL;
                lista->ultimo->siguiente = NULL;

                //elimina el último de la lista, si hay más 2 fichas
            }else if((aux2->id == aux1->id) && (aux1->id == lista->ultimo->id)) {
                lista->ultimo = aux1->anterior;
                aux1->anterior->siguiente = NULL;
                aux1->anterior = NULL;

                //elimina el primero de la lista, si hay más 2 fichas
            }else if((aux2->id == aux1->id) && (aux1->id == lista->primero->id)) {
                lista->primero = aux1->siguiente;
                aux1->siguiente = NULL;
                aux1->anterior = NULL;

                //Elimina en el medio de la lista
            }else if(aux2->id == aux1->id){
                aux1->anterior->siguiente = aux1->siguiente;
                aux1->siguiente->anterior = aux1->anterior;
                aux1->anterior = NULL;
                aux1->siguiente = NULL;
            }

            aux1 = aux1->siguiente;
        }
    }
}

//Se recorre la lista para mostrar los procesos
void mostrarListaProcesos(ListaProcesos *lista){

    NodoProcesos *aux = lista->primero;
    printf("\n\n");
    while(aux != NULL){
        mostrarNodoProceso(aux);
        sleep(1);
        aux = aux->siguiente;
    }
}



#endif //QUIZ_SO_LISTAPROCESOS_H
