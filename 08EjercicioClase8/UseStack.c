#include <stdio.h>
#include "Stack.h"

int main() {

  Stack myIntStack = stack_create();
  Stack myCharStack = stack_create();

  int myIntArray[] = { 1, 2, 3, 4, 5 };
  char myCharArray[] = { 'a', 'b', 'c', 'd', 'e' };

  for (int i = 0; i < 5; i ++) {
    stack_push(myIntArray + i, myIntStack);
  }

  for (int i = 0; i < 5; i ++) {
    stack_push(myCharArray + i, myCharStack);
  }

  printf("Tamano de mi stackInt: %d\n", stack_size(myIntStack));

  printf("Elemento de hasta arriba stackInt: %d\n", *((int*) stack_top(myIntStack)));

  for (int i = 0; i < 5; i ++) {
    printf("Elemento numero %d en mi stackINt: %d\n", i, *((int*) stack_pop(myIntStack)));
  }

  printf("Elemento de hasta arriba stackChar: %c\n", *((char*) stack_top(myCharStack)));

  for (int i = 0; i < 5; i ++) {
    printf("Elemento numero %d en mi stackChar: %c\n", i, *((char*) stack_pop(myCharStack)));
  }

  printf("Tamano de mi stackInt depues de hacer pop: %d\n", stack_size(myIntStack));

  stack_destroy(myIntStack);
  stack_destroy(myCharStack);

  return 0;
}
