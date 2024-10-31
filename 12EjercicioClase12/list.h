/*
 * list.h
 *
 *  Created on: 22 oct. 2024
 *      Author: iker.contla
 */

#ifndef LIST_H_
#define LIST_H_

typedef void* Type;
typedef struct strList* List;

List list_create();
void list_destroy(List l);
int list_size(List l);
void list_add(List l, Type e);
Type list_get(List l, int p);
void list_set(List l, Type e, int p);
Type list_remove(List l, int p);
void list_insert(List l, Type e, int p);

#endif /* LIST_H_ */
