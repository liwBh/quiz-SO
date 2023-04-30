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

void desfragmentarMemoria(struct Bloque matriz[8][8], ListaProcesos *listaContenedor){

    //limpiar posicion en matriz
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            matriz[i][j].disponible = 0;
            matriz[i][j].idProceso = 0;
        }
    }

    //recorrer lista
    NodoProcesos *aux = listaContenedor->primero;
    while (aux != NULL){
        //resetea la lista de posiciones de cada proceso
        aux->listaPosicion = crearListaPosicion();

        //determinar el numero de bloques
        int nBloques = (aux->peso / 4);

        printf("\nMoviendo el numero de bloques: %d del proceso: %d", nBloques, aux->id);

        //colocar el numero de posciones desde la ultima posicion
        for(int i = 7; i >= 0; i--) {

            for(int j = 7; j >= 0; j--) {
                if(matriz[i][j].disponible == 0) {
                    NodoPosicion *nodoPosicion = crearNodoPosicion(i, j);

                    matriz[i][j].disponible = 1;
                    matriz[i][j].idProceso = aux->id;

                    //agregar la posicion en la lista del proceso
                    insertarNodoPosicion(aux->listaPosicion, nodoPosicion);

                    nBloques--;

                    if (nBloques == 0) {
                        i = 0;
                        break;
                    }
                }
            }


        }
        aux = aux->siguiente;
    }

    printf("\n\nLa memoria termino de ser desfragmentada\n");
   // mostrarMatriz(matriz);
}

//Metodo que recorra matriz y busque el primer espacio disponible, devuelve i y j
ListaPosicion *asignarEspacioDisponible(struct Bloque matriz[8][8], NodoProcesos *nodo, ListaProcesos *listaContenedor){

    int nBloques = (nodo->peso / 4);

    printf("El numero de bloques: %d para el proceso: %d", nBloques, nodo->id);

    //crear una lista
    ListaPosicion *listaPosiciones = crearListaPosicion();

    //insertar en la lista las posciones, si en algun momento no puede insertar se resetea la lista
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            NodoPosicion *almacena = crearNodoPosicion(0,0);
            if(matriz[i][j].disponible == 0 ) {
                almacena->i = i;
                almacena->j = j;
                insertarNodoPosicion(listaPosiciones, almacena);
                nBloques--;
            }else{
                //resetear la lista
                listaPosiciones->primero = NULL;
                listaPosiciones->ultimo = NULL;
                nBloques = (nodo->peso / 4);
            }

            if (nBloques == 0) {
                i = 8;
                break;
            }
        }
    }

    if(!estaVacia(listaPosiciones)){
        //recorer la lista y asinar bloques
        NodoPosicion *aux = listaPosiciones->primero;
        while (aux != NULL) {
            //Asignado en matriz
            matriz[aux->i][aux->j].disponible = 1;
            matriz[aux->i][aux->j].idProceso = nodo->id;
            //Agregando direccion al metodo de los bloques en memoria
            insertarNodoPosicion(nodo->listaPosicion, aux);
            aux = aux->siguiente;
        }
    }else{
        //defragmentar

        printf("\n\n*****Es necesario desfragmentar memoria*****\n");
        desfragmentarMemoria(matriz,listaContenedor);
    }

}

/*
void asignarEspacioDisponible(struct Bloque matriz[8][8], NodoProcesos *nodo){

    // determinar el numero de bloques del proceso
    int nBloques = (nodo->peso / 4);

    printf("El numero de bloques: %d para el proceso: %d", nBloques, nodo->id);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if(matriz[i][j].disponible == 0 ) {
                //insertar i,j en un nodo posicion
                NodoPosicion *nodoPosicion = crearNodoPosicion(i, j);

                matriz[i][j].disponible = 1;
                matriz[i][j].idProceso = nodo->id;

                //agregar la posicion en la lista del proceso
                insertarNodoPosicion(nodo->listaPosicion, nodoPosicion);

                nBloques--;

                if (nBloques == 0) {
                    i = 8;
                    break;
                }

            }
        }

    }
}

*/

NodoProcesos* seleccionarNodoAleatorio(ListaProcesos *listaContenedor) {
    // Obtener el número de nodos de la lista
    int nNodos = 0;
    NodoProcesos *actual = listaContenedor->primero;
    while (actual != NULL) {
        nNodos++;
        actual = actual->siguiente;
    }

    // Generar un número aleatorio en el rango de 0 a n-1
    int indiceAleatorio = rand() % nNodos;

    // Recorrer la lista y detenerse en el nodo correspondiente al número aleatorio generado
    actual = listaContenedor->primero;
    for (int i = 0; i < indiceAleatorio; i++) {
        actual = actual->siguiente;
    }

    return actual;
}
//void moverUnosAlFinal(int matriz[8][8]) {
//    int ultimoCero = 7;
//    for (int i = 7; i >= 0; i--) {
//        for (int j = 7; j >= 0; j--) {
//            if (matriz[i][j] == 1) {
//                while (ultimoCero >= 0 && matriz[ultimoCero][j] == 1) {
//                    ultimoCero--;
//                }
//                if (ultimoCero >= 0) {
//                    matriz[ultimoCero][j] = 1;
//                    matriz[i][j] = 0;
//                    ultimoCero--;
//                }
//            }
//        }
//    }
//}


//Metodo para liberar memoria de la matriz segun las posiciones en que se ubica el proceso, con la lista de posiciones
void liberarMemoria(NodoProcesos *nodo, struct Bloque matriz[8][8]){
    NodoPosicion *aux = nodo->listaPosicion->primero;

    //liberar bloques de matriz
    while (aux != NULL){ //Se recorre la lista de posiciones del proceso

        matriz[aux->i][aux->j].disponible = 0; //Y se libera la disponibilidad en memoria
        matriz[aux->i][aux->j].idProceso = 0; //Se libera el id del proceso en memoria

        //printf("Eliminando pos i:%d j:%d ",);

        aux = aux->siguiente;
    }

}

#endif //QUIZ_SO_LOGICA_H
