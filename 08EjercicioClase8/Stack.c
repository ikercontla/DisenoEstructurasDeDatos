/*
 * Stack.c
 *
 *  Created on: 3 oct. 2024
 *      Author: iker.contla
 */
#include <stdlib.h>
#include "Stack.h"

struct strNode {
  Type data;
  struct strNode* prior;
};

typedef struct strNode* Node;

struct strStack {
  int size;
  Node top;
};

Stack stack_create() {
	Stack s = (struct strStack*) malloc(sizeof(struct strStack));
	s->top = NULL;
	s->size = 0;
	return s;
}

int stack_size(Stack s) {
	return s->size;
}

Bool stack_isEmpty(Stack s){
	if(s->size == 0) {
		return True;
	} else {
	return False;
	}
}

Type stack_top(Stack s) {
	return s->top->data; //accedemos a top (es un nodo) y luego accedemos a data(valor que tiene el nodo)
}

void stack_push(Type e, Stack s) {
	//creamos un nuevo nodo
	Node n = (Node) malloc(sizeof(struct strNode));
	//asignamos el dato "e" al nodo
	n->data = e;
	//asignamos al prior del nodo creado el nodo que antes era top
	n->prior = s->top;
	//ahora a top le asignamos el nuevo nodo
	s->top = n;
	//actualizamos size
	s->size++;
}

Type stack_pop(Stack s) {
	if(stack_isEmpty(s)) {
		return NULL;//creamos int para respaldar el dato de top
	} else {
	Type e = s->top->data;
	//creamos un Node para respaldar la referencia del node en top
	Node n = s->top;
	//Asignamos al valor de top el que esta abajo
	s->top = s->top->prior;
	//liberamos los respaldos
	free(n);
	//actualizamos el tamano
	s->size--;
	return e;
	}
}

void stack_destroy(Stack s) {
	Node n;
	while (s->top != NULL) {
		n = s->top;
		s->top = s->top->prior;
		free(n);
	}
	free(s);
}




