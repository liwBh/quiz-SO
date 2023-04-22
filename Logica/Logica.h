//
// Created by jurguen on 18/04/23.
//

#ifndef QUIZ_SO_LOGICA_H
#define QUIZ_SO_LOGICA_H

#include <ctype.h>
#include "../ListaProcesos/ListaProcesos.h"
#include "../MatrizMemoria/Matriz.h"



void insertarUnProceso(ListaProcesos *lista, NodoProcesos *nodo){
    insertar(lista, nodo);
}

//Pasa un proceso de la lista de espera a la lista que ya fueron atendidos en memoria
void pasarProcesoContenedor(ListaProcesos *listaEspera, ListaProcesos *listaContenedor){
    if(!listaVacia(listaEspera)){
        //Crea un nodo con el primero de la lista de espera
        NodoProcesos *almacenarProceso = crearNodoProcesos(listaEspera->primero->nombre,listaEspera->primero->peso,listaEspera->primero->id, listaEspera->primero->listaPosicion);
        //Cambia la referencia del primero de lista
        listaEspera->primero = listaEspera->primero->siguiente;
        //Inserta el nodo en la lista contenedor
        insertarUnProceso(listaContenedor,almacenarProceso);
        //Elimina el nodo de la lista de espera
        eliminarProcesoEsperando(listaEspera,almacenarProceso);
    }else{
        printf("Ya no hay mas procesos");
    }
}

//Metodo que recorra matriz y busque el primer espacio disponible, devuelve i y j
void asignarEspacioDisponible(struct Bloque matriz[8][8], NodoProcesos *nodo){

    // determinar el numero de bloques del proceso
    int nBloques = (nodo->peso / 4);

    printf("El numero de bloques: %d para el proceso: %d", nBloques, nodo->id);


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if(matriz[i][j].disponible == 0){
                //insertar i,j en un nodo posicion
                NodoPosicion *nodoPosicion = crearNodoPosicion(i,j);

                matriz[i][j].disponible = 1;
                matriz[i][j].idProceso = nodo->id;

                //agregar la posicion en la lista del proceso
                insertarNodoPosicion(nodo->listaPosicion, nodoPosicion);

                nBloques--;

                if(nBloques == 0){
                    i = 8;
                    break;
                }
            }
        }
    }
}

//Metodo para liberar memoria de la matriz segun las posiciones en que se ubica el proceso, con la lista de posiciones
void liberarMemoria(NodoProcesos *nodo, struct Bloque matriz[8][8]){
    NodoPosicion *aux = nodo->listaPosicion->primero;
    while (aux != NULL){ //Se recorre la lista de posiciones del proceso

        matriz[aux->i][aux->j].disponible = 0; //Y se libera la disponibilidad en memoria
        matriz[aux->i][aux->j].idProceso = 0; //Se libera el id del proceso en memoria

        //printf("Eliminando pos i:%d j:%d ",);

        aux = aux->siguiente;
    }
}

#endif //QUIZ_SO_LOGICA_H
