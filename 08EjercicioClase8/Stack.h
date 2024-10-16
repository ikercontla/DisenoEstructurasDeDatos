/*
 * Stack.h
 *
 *  Created on: 3 oct. 2024
 *      Author: iker.contla
 */

#ifndef STACK_H_
#define STACK_H_

//Ejercicios lamina "23 Pilas"
//definimimos la estructura Stack
typedef struct strStack* Stack;

typedef void* Type;

typedef enum { False, True } Bool;

//metodos a implementar
Stack stack_create();
int stack_size(Stack);
Bool stack_isEmpty(Stack);
Type stack_top(Stack);
void stack_push(Type, Stack);
Type stack_pop(Stack);
void stack_destroy(Stack);

#endif /* STACK_H_ */
