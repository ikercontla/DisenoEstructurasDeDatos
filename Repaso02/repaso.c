/*
 * repaso.c
 *
 *  Created on: Oct 15, 2024
 *      Author: ikerb
 */

#include <stdlib.h>
#include <stdio.h>

//Reserven memoria para un arreglo de enteros de 10 x 20 (arreglo bidimensional o matriz)

int** myIntMatrix = (int**) malloc(10 * sizeof(int*));

for (int i = 0; i < 10; i ++) {
  myIntMatrix[i] = (int*) malloc(20 * sizeof(int));
}

//Redimensionen las filas de su matriz de modo que cada fila i ahora pueda almacenar su capacidad más i elementos

for (int i = 0; i < 10; i ++) {
  myIntMatrix[i] = (int*) realloc(myIntMatrix[i], (20 + i + 1) * sizeof(int));
}

//Liberen toda la memoria reservada para nuestra matriz
for (int i = 0; i < 10; i ++) free(myIntMatrix[i]);
free(myIntMatrix);


//Reserven memoria para un arreglo de caracteres de 10 x 10 x 10 (arreglo tridimensional)

char*** myCharCube = (char***) malloc(10 * sizeof(char**));

for (int i = 0; i < 10; i ++) {
  myCharCube[i] = (char**) malloc(10 * sizeof(char*));
  for (int j = 0; j < 10; j ++) {
    myCharCube[i][j] = (char*) malloc(10 * sizeof(char));
  }
}

for (int x = 0; x < 10; x ++) {
  for (int y = 0; y < 10; y ++) {
    for (int z = 0; z < 10; z ++) {
      myCharCube[x][y][z] = (x + y + z) % 255;
    }
  }
}

for (int x = 0; x < 10; x ++) {
  printf("\n\n");
  for (int y = 0; y < 10; y ++) {
    printf("\n");
    for (int z = 0; z < 10; z ++) {
      printf("%c ", myCharCube[x][y][z]);
    }
  }
}

for (int x = 0; x < 10; x ++) {
  for (int y = 0; y < 10; y ++) {
    free(myCharCube[x][y]);
  }
  free(myCharCube[x]);
}

free(myCharCube);

//Considere las siguientes estructuras:


struct strNode {
  char data;
  struct strNode* next;
};

typedef struct strNode* Node;

struct strQueue {
  Node first, last;
  int size;
  print pf;
};

typedef struct strQueue* Queue;


//Implemente el método queue_poll

char queue_poll(Queue q) {
  if (q->size == 0) {
    return NULL;
  }
  char toReturn = q->first->data;
  Node n = q->first;
  q->first = q->first->next;
  free(n);
  q->size --;
  return toReturn;
}

int main() {
	return 0;
}
//Repase las operaciones para insertar y remover elementos en pila y cola






