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
	Node n = (Node) malloc(sizeof(struct strNode));
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
	if (l->size <= p) {
	    return NULL;
	  } else {
	    Node n = l->first;
	    for (int i = 0; i < p; i ++) {
	      printf(":( ");
	      n = n->next;
	    }
	    printf("\n");
	    return n->data;
	  }
}

//list_set sobreescribe el indice
void list_set(List l, Type e, int p) {
	if (l->size <= p) {
	    return;
	  } else {
	    Node n = l->first;
	    for (int i = 0; i < p; i ++) {
	      n = n->next;
	    }
	    n->data = e;
	  }
}

Type list_remove(List l, int p) {
	if (l->size <= p) {
	    return NULL;
	  } else {
	    Node n = l->first;
	    for (int i = 0; i < p; i ++) {
	      n = n->next;
	    }
	    if (n == l->first && n == l->last) {
	      l->first = NULL;
	      l->last = NULL;
	    } else if (n == l->first) {
	      l->first = l->first->next;
	      l->first->prior = NULL;
	    } else if (n == l->last) {
	      l->last = l->last->prior;
	      l->last->next = NULL;
	    } else {
	      n->prior->next = n->next;
	      n->next->prior = n->prior;
	    }
	    // 0               1          2           3
	    // data: 23        data: 17   data: 3     data: 67
	    // next: 1         next: 2    next: 3     next: NULL
	    // prior: NULL     prior: 0   prior: 1    prior: 2
	    Type toReturn = n->data;
	    free(n);
	    l->size --;
	    return toReturn;
	  }
}

void list_insert(List l, Type e, int p) {
	if (l->size <= p) {
		    return;
		  } else {
		    Node n = l->first;
		    for (int i = 0; i < p; i ++) {
		      n = n->next;
		    }
		    Node newN = (Node) malloc(sizeof(struct strNode));
		    newN->data = e;
		  if (n == l->first) {
		    	l->first->prior = newN;
		    	newN->next =l->first;
		    	newN->prior = NULL;
		    	l->first = newN;
		    } else {
		    	newN->next = n;
		    	newN->prior = n ->prior;
		    	newN->prior->next = newN;
		    	n->prior = newN;
		    }
		  l->size++;
		  }

}





