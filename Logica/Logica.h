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

void pasarProcesoContenedor(ListaProcesos *listaEspera, ListaProcesos *listaContenedor){
    if(!listaVacia(listaEspera)){
        NodoProcesos *almacenarProceso = crearNodoProcesos(listaEspera->primero->nombre,listaEspera->primero->peso,listaEspera->primero->id, listaEspera->primero->listaPosicion);
        listaEspera->primero = listaEspera->primero->siguiente;
        insertarUnProceso(listaContenedor,almacenarProceso);
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

//void llenarMatriz( Nodo* cabeza, int** matriz, int num_filas, int num_columnas) {
//    int fila = 0, columna = 0;
//    while (cabeza != NULL) {
//        matriz[fila][columna] = cabeza->dato;
//        cabeza = cabeza->siguiente;
//        columna++;
//        if (columna == num_columnas) {
//            fila++;
//            columna = 0;
//        }
//    }
//}
//char nombre[50];
//int peso;
//int id;
//
//void llenarMatriz(ListaProcesos *listaProcesos, NodoProcesos** matriz, int num_filas, int num_columnas) {
//    int fila = 0, columna = 0;
//    NodoProcesos* actual = listaProcesos->primero;
//    while (actual != NULL) {
//        matriz[fila][columna] = actual;
//        actual = actual->siguiente;
//        columna++;
//        if (columna == num_columnas) {
//            fila++;
//            columna = 0;
//        }
//    }
//}
//matriz bits
//void recorrerMatriz(int FILAS, int COLUMNAS) {
//    unsigned char mapeo = 0b10101010; // Mapeo de ejemplo ob indica que es un valor binario
//    int matriz[FILAS][COLUMNAS];
//    int fila, columna;
//
//    for (fila = 0; fila < FILAS; fila++) {
//        for (columna = 0; columna < COLUMNAS; columna++) {
//            int bit = (mapeo >> (fila * COLUMNAS + columna)) & 1;
//            matriz[fila][columna] = bit;
//            printf("%d\t", matriz[fila][columna]);
//        }
//        printf("\n");
//    }
//}


#endif //QUIZ_SO_LOGICA_H
