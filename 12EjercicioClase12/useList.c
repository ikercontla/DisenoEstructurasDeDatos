/*
 * useList.c
 *
 *  Created on: 31 oct. 2024
 *      Author: iker.contla
 */

#include <stdio.h>
#include "List.h"

int main() {

  List myList = list_create();

  int myInt1 = 1;
  int myInt2 = 2;
  int myInt3 = 3;
  int myInt4 = 4;
  int myInt5 = 5;

  list_add(myList, &myInt1);
  list_add(myList, &myInt2);
  list_add(myList, &myInt3);
  list_add(myList, &myInt4);
  list_add(myList, &myInt5);

  int toPrint;

  for (int i = 0; i < 5; i ++) {
    toPrint = *((int*) list_get(myList, i));
    printf("%d ", toPrint);
  }
  // 0, 1, 2, 3, 4
  // 1, 2, 3, 4, 5

  printf("\n");

  int myInt6 = 7;

  list_set(myList, &myInt6, 2);

  for (int i = 0; i < 5; i++) {
	toPrint = *((int*) list_get(myList, i));
	printf("%d ", toPrint);
  }

  toPrint = *((int*) list_remove(myList, 3));

  printf("\n");
  printf("%d\n", toPrint);

  toPrint = *((int*) list_remove(myList, 0));

  printf("%d\n", toPrint);

  toPrint = *((int*) list_remove(myList, 2));

  printf("%d\n", toPrint);

  for (int i = 0; i < 2; i ++) {
    toPrint = *((int*) list_get(myList, i));
    printf("%d ", toPrint);
  }

  list_insert(myList, &myInt5, 0);
  list_insert(myList, &myInt4, 2);

  printf("\n");

  for (int i = 0; i < 4; i ++) {
    toPrint = *((int*) list_get(myList, i));
    printf("%d ", toPrint);
  }

  return 0;
}
