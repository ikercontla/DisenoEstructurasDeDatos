/*
 * EjercicioClase6.c
 *
 *  Created on: 3 sep. 2024
 *      Author: iker.contla
 */
#include <stdio.h>
#include <stdlib.h>

 //funcion para crear matriz con R lineas y C columnas
int ** createMatrix(int R, int C) {
    int ** matrix = (int **) malloc(R * sizeof(int*)); //creamos un espacio de tamaño R que tenga apuntadores a enteros
    for(int i = 0; i < R; i++){ //ciclo for para ir recorriendo cada espacio de R
    		*(matrix + i) = (int*) malloc(C * sizeof(int)); //asignamos un espacio con mallo de tamaño C a cada R
    	}

    for (int i = 0; i<R; i++) {
    	for (int j = 0; j<C; j++) {
    		*(*(matrix + i) + j) = i + j % C;
    	}
    }
    return matrix;
    }

//set para asignar valores
void setMatrixElements(int** matrix, int value, int R, int C) {
	//con corchetes matrix[R][C] = value;
	*(*(matrix + R) + C) = value;
}

//get para agarrar un valor de la matriz
int getMatrixElement(int ** matrix, int R, int C) {
	return *(*(matrix + R) + C);
}

//funcion para imprimir matriz
void printMatrix(int** m, int R, int C) { // funcion para imprimir matriz m con R lineas y C columnas
	for (int i = 0; i < R; i++) {
		printf("%p: [", m[i]); //*m + i
		for (int j = 0; j < C; j++)	{
			printf("%d ", m[i][j]);
		}
	printf("]\n");
	}
}

//funcion para liberar el espacio de matriz
void freeMatrix(int** m, int R, int C) { //funcion para liberar el espacio de memoria de matriz r con R filas y C columnas
	for (int i = 0; i < R; i++){
		free(m[i]);
	}
	free(m);
}

//una funcion que reciba una matriz y el numero de una fila e imprimima nada mas esa fila

void printRowMatrix(int ** matrix, int R, int C) {
	printf("[ ");
	for (int i = 0; i < C; i++) {
		printf("%d ", matrix[R][i]);
	}
	printf("]");
}

//imprimir transpuesta de l amatrix
void printRotateMatrix(int ** matrix, int R, int C) {
	for (int i = 0; i<C; i++) {
		printf("[ ");
		for (int j = 0; j<R; j++) {
			printf("%2d ", matrix[C - i - 1][j]);
		}
		printf("]\n");
	}
}

void printTransposedMatrix(int ** matrix, int R, int C) {
	for (int i = 0; i<C; i++) {
		printf("[ ");
		for (int j = 0; j<R; j++) {
			printf("%2d ", matrix[j][i]);
		}
		printf("]\n");
	}
}
int main() {

	int R, C;

    R = 7;
    C = 7;
    printf("R: %d\n", R);
    printf("C: %d\n", C);


    int **myIntMatrix = createMatrix(R, C);

    setMatrixElements(myIntMatrix, 7, 2, 4);
    printf("%d\n", getMatrixElement(myIntMatrix, 2, 4));
    printMatrix(myIntMatrix, R, C);
    printf("\n");
    printRowMatrix(myIntMatrix, 2, C);
    printf("\n");
    printf("\n");
    printRotateMatrix(myIntMatrix, R, C);
    printf("\n");
    printTransposedMatrix(myIntMatrix, R, C);
    freeMatrix(myIntMatrix, R, C);



    return 0;
}


