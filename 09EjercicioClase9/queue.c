/*
 * queue.c
 *
 *  Created on: 8 oct. 2024
 *      Author: iker.contla
 */
#include <stdlib.h>
#include "queue.h"

typedef void* Type;

//estructura que define un nodo
struct strNode {
	Type data;
	struct strNode *next;
};

typedef struct strNode* Node;

//estructura que define una pila
struct strQueue {
	struct strNode *first, *last;
	int size;
};

Queue queue_create() {
	Queue q = (struct strQueue*) malloc(sizeof(struct strQueue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return q;
}

int queue_size(Queue q) {
	return q->size;
}

Bool queue_isEmpty(Queue q) {
	if (q->size == 0) {
		return True;
	} else {
		return False;
	}

}

Type queue_peek(Queue q) {
	return q->first->data;
}

void queue_offer(Type e, Queue q) {
	//primero creamos un nuevo nodo y lo inicializamos
	Node n = (Node) malloc(sizeof(struct strNode));
	n->data = e;
	n->next = NULL;
	//verificaremos si esta vacio
	if (queue_isEmpty(q)){
		//asignamos el valor de n a first
		q->first = n;
	} else {
	q->last->next = n;
	}

	//asignamos el nodo nuevo a last
	q->last = n;
	//sumamos en 1 el size
	q->size++;
}

Type queue_poll(Queue q) {
	if(queue_isEmpty(q)) {
		return NULL;
	} else {
		//asignare el valor data de first en un pivote
		Type e = q->first->data;
		//lo mismo para el nodo
		Node n = q->first;
		//asignamos el valor de q->first->next (es decir el que esta despues del mas viejito) a q->first (para que ahora sea el mas viejito)
		q->first = q->first->next;
		//liberamos la memoria de n
		free(n);
		//actualizamos el tamano
		q->size--;
		//regresamos el dato
		return(e);
	}
}

void queue_destroy(Queue q) {
	//creamos un nodo de pivote
	Node n;
	//ciclo para verificar que el valor de last o first no sea nulo
	while(q->first != NULL) {
		//asignamos el valor de first a nodo
		n = q->first;
		//y ahora first va a ser next de first
		q->first = q->first->next;
		//y luego lo liberamos
		free(n);
	}
	free(q);
}

