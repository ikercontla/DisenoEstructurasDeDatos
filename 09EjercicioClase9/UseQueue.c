/*
 * UseQueue.c
 *
 *  Created on: 10 oct. 2024
 *      Author: iker.contla
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void printInt(Type e) {
	printf("%d ", *(int*)(e));
}
int main() {

	  //creamos la queue
	  Queue myQ = queue_create(printInt);

	  //5 enteros y los inicializamos
	  int myInt1 = 1;
	  int myInt2 = 2;
	  int myInt3 = 3;
	  int myInt4 = 4;

	  //Metemos los elementos con queue_offer
	  queue_offer(&myInt1, myQ);
	  queue_offer(&myInt2, myQ);
	  queue_offer(&myInt3, myQ);
	  queue_offer(&myInt4, myQ);

	  queue_print(myQ);

	  //imprimos el elemento regresado de queue_peek(()
	  printf("El primer elemento es: %d\n", *(int*)(queue_peek(myQ)));

	  for (int i = 0; i<4; i++) {
		  printf("El elemento: %d\n", *(int*)(queue_poll(myQ)));
	  }

	  int* nextElement = (int*) queue_peek(myQ);

	  if (nextElement == NULL) {
		  printf("La cola esta vacia");
	  }
	return 0;
}
