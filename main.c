#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListaProcesos/ListaProcesos.h"
#include "Logica/Logica.h"
#include "MatrizMemoria/Matriz.h"

/*
 * Politica correspondiente: Particiones variables, Mapa Bits.
 * Grupo#1 - Wilfredo Barquero, Elmer Mejias, Jurguen Monge.
 
 */

struct Bloque matriz[8][8];

pthread_t proceso;
pthread_t administrador; //hilo maestro que inicia el programa
bool estadoEjecucion = true;

//Listas y Nodos
ListaProcesos *listaContenedor;//procesos en Memoria
ListaProcesos *listaEsperando;//procesos en espera
ListaPosicion *listaPosicion;//Lista posicion



//Funciones
void crearListas();
void llenarListaProcesosEsperando();
void *iniciarProceso(void * args);
void *empezarSimulacion(void *args);


int main() {

    printf("------------- Simulacion de Mapeo de Bits ------------\n");

    printf("\nTamaño de memoria = 256kb\n");
    printf("Tamaño del bloque = 4kb\n");

    sleep(2); //con esto pueden alterar la velocidad con que muestran las cosas

    //crear la matriz
    llenarMatriz( matriz);

    //Imprimir matriz
    mostrarMatriz( matriz );

    sleep(2); //con esto pueden alterar la velocidad con que muestran las cosas

    //crear lista de almacenamiento procesos
    crearListas();

    //llenar lista procesos
    llenarListaProcesosEsperando();

    //imprimir lista procesos
    mostrarListaProcesos(listaEsperando);

    printf("\n--------- Iniciando Simulacion de Mapeo de bits ---------\n");

    //Hilo maestro de la simulacion
    pthread_create(&(administrador), NULL, &empezarSimulacion, NULL);

    //inicia la simulaicon del hilo
    pthread_join(administrador, NULL); //se sincroniza

    return 0;
}



void crearListas(){
    //inicializa las listas

    listaContenedor = crearListaProcesos();
    listaEsperando = crearListaProcesos();


}

void llenarListaProcesosEsperando(){

    printf("\n---------Creando procesos ---------\n");

    srand(time(NULL));
    int nProcesos = rand() % (30 - 25 + 1) + 25;

    for (int i = 0; i < nProcesos; ++i) {
        char str[10];
        char nombre[10] = "P-";
        int peso = 0;

        do {
            peso = rand() % 40 + 1 ;
        } while (peso % 4 != 0);

        sprintf(str, "%d",(i+1));

        strcat(nombre,  str);

        //lista de posiciones en memoria
        listaPosicion  = crearListaPosicion();
        NodoProcesos *nodo = crearNodoProcesos( nombre,peso,(i+1), listaPosicion);
        insertarUnProceso(listaEsperando,nodo);
    }

}


void *iniciarProceso(void * args){

    //recibir parametro de nodo
    NodoProcesos *nodoProcesos = (NodoProcesos *) args;

    //se agrega el proceso a la lista de memoria
    printf("\nInsertando un proceso en la memoria");
    //agregar el primer proceso en espera y se pasa a memoria
    pasarProcesoContenedor(listaEsperando,listaContenedor);
    //mostrarListaProcesos(listaContenedor);
    printf("\n");

    //asignar bloques
    asignarEspacioDisponible(matriz,nodoProcesos, listaContenedor);

    //Imprimir matriz
    mostrarMatriz( matriz );

}

void *empezarSimulacion(void *args){

    while(estadoEjecucion){

        //identificar el proceso entrante
        NodoProcesos *nodoProcesos = listaEsperando->primero;

        if (pthread_create( &(proceso), NULL, &iniciarProceso,(void *)nodoProcesos) != 0){
            printf("Error al crear hilos\n");
        }

        pthread_join(proceso, NULL);

        //verificar si el llenado es igual o mayor al 75%, 1 = Si, 0 = No

        if( validarLlenado(matriz) ) {
            printf("\nLa memoria ha llegado aun 3/4 de su capacidad\n");

            NodoProcesos *nodoEliminar = seleccionarNodoAleatorio(listaContenedor); // Almacenar nodo a eliminar
            printf("\nLiberando de memoria %d bloques del proceso: %d",(nodoEliminar->peso/4), nodoEliminar->id);
           //liberarProceso(nodoEliminar->id, matriz); // Liberar memoria
            liberarMemoria(nodoEliminar,matriz); //Libera la memoria por medio de la lista de posiciones que tiene el proceso
            eliminarProcesoEsperando(listaContenedor, nodoEliminar); // Eliminar proceso de la lista
            mostrarMatriz(matriz); // Imprimir matriz

        }

        //cuando la lista de esperando se quede vacia
        if(listaEsperando->primero ==NULL){
            estadoEjecucion = false;

            printf("\n{---- Simulacion Finalizada -----}\n");
        }

        sleep(2); //con esto pueden alterar la velocidad con que muestran las cosas
    }

}


