//
// Created by liwbh on 22/04/23.
//

#ifndef QUIZ_SO_MATRIZ_H
#define QUIZ_SO_MATRIZ_H
#include <stdio.h>
#include <stdbool.h>

struct Bloque {
    int disponible;
    int idProceso;

} Bloque;



void llenarMatriz(struct Bloque matriz[8][8]){

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j].disponible = 0;
            matriz[i][j].idProceso = 0;
        }
    }
}

void mostrarMatriz(struct Bloque matriz[8][8]){

    printf("\n\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("[ %d ]", matriz[i][j].disponible );

        }

        printf("\n");
    }
}

bool validarLlenado( struct Bloque matriz[8][8] ){
    int contador = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(matriz[i][j].disponible == 1){
                contador ++;
                if(contador >= 48){
                    return true;
                }
            }
        }
    }
    return false;
}


void liberarProceso(int idProceso, struct Bloque matriz[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matriz[i][j].idProceso == idProceso) {
                matriz[i][j].disponible = 0;
                matriz[i][j].idProceso = 0;
            }
        }
    }
}


#endif //QUIZ_SO_MATRIZ_H