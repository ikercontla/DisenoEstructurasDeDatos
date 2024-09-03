/*
 * EjercicioClase6.c
 *
 *  Created on: 3 sep. 2024
 *      Author: iker.contla
 */
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** m, int R, int C) { // funcion para imprimir matriz m con R lineas y C columnas
	for (int i = 0; i < R; i++) {
		printf("%p: [", m[i]); //*m + i
		for (int j = 0; j < C; j++)	{
			printf("%d", m[i][j]);
		}
	printf("]\n");
	}
}

void freeMatrix(int** m, int R, int C) { //funcion para liberar el espacio de memoria de matriz r con R filas y C columnas
	for (int i = 0; i < R; i++){
		free(m[i]);
	}
	free(m);
}
int main() {

	int R, C;
	//solicite el numero de filas R y columnas C que tendra una matriz
	printf("R: \n");
    scanf("%d", &R);

    printf("C: \n");
    scanf("%d", &C);

    int** myIntMatrix = (int**) malloc(R * sizeof(int*));

    for (int i = 0; i < R; i++) {
    	*(myIntMatrix + i) = (int*)malloc(C * sizeof(int));
    }
    for (int i = 0; i < R; i++) {
    		for (int j = 0; j < C; j++)	{
    			*(*(myIntMatrix + i) + j) = i*10 + j;
    		}
    }

    printMatrix(myIntMatrix, R, C);

    freeMatrix(myIntMatrix, R, C);



    return 0;
}


