/*
 * UseStack.c
 *
 *  Created on: 3 oct. 2024
 *      Author: iker.contla
 */
#include <stdio.h>
#include "Stack.h"

int main() {
//pondremos a prueba el Stack que creamos

	Stack myIntStack = stack_create();
	Stack myCharStack = stack_create();

	int myIntArray[] = { 1, 2, 3, 4, 5 };
	char myCharArray[] = { 'a', 'b', 'c', 'd', 'e' }

	for (int i = 0; i < 5;  i++ ) {
		stack_push(myIntArray + i, myIntStack);
	}

}
