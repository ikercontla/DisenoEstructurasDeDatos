/*
 * list.c
 *
 *  Created on: 22 oct. 2024
 *      Author: iker.contla
 */
#include <stdlib.h>
#include "List.h"

struct strNode {
  Type data;
  struct strNode *prior, *next;
};

typedef struct strNode* Node;

struct strList {
  Node first, last;
  int size;

};

List list_create() {
  List l = (List) malloc(sizeof(struct strList));
  l->first = NULL;
  l->last = NULL;
  l->size = 0;
  return l;
}

void list_destroy(List l) {
	Node n;
	while(l->first != NULL) {
		n = l->first;
		l->first = l->first->next;
		free(n);
	}
	free(l);
}

int list_size(List l) {
	return l->size;
}

//list_add agrega un nodo al final de la lista
void list_add(List l, Type e) {
	//creamos el nuevo nodo
	Node n = (Node) mallo(sizeof(struct strNode));
	n->data = e;
	n->next = NULL;
	n->prior = l->last;

	if (l->size == 0) {
		l->first = n;
	} else {
		l->last->next = n;
	}

	l->last = n;
	l->size++;
}
Type list_get(List l, int p) {
	//primero comprobamos que el tamano de la lista sea mayor a la posicion que nos den
	if (l->size <= p) {
		return NULL;
	} else {
		Node n = l->first;
		for (int i = 0; i < p; i++) {
			n = n->next;
		}
	}
}
void list_set(List l, Type e, int p);
Type list_remove(List l, int p);



