/*
 * queue.h
 *
 *  Created on: 8 oct. 2024
 *      Author: iker.contla
 */

#ifndef QUEUE_H_
#define QUEUE_H_


typedef struct strQueue* Queue;
typedef void* Type;
typedef enum { False, True } Bool;
typedef void (*print)(Type);

//metodos a definir

//Queue queue_create(); Crea un ejemplar Stack con memoria dinámica
//y asigna NULL, NULL y 0 a sus elementos.
//int queue_size(Queue); Extrae el tamaño de la cola
//Bool queue_isEmpty(Queue); ¿El primero es nulo?
//Type queue_peek (Queue); Consulta quién está al frente (no elimina)
//void queue_offer(Queue, Type); Se forma uno nuevo (colocarlo al final)
//Type queue_poll(Queue); Atiende al que está al frente (elimina)
//void queue_destroy(Queue); Elimina a todos los nodos y a la cola misma


Queue queue_create(print);
int queue_size(Queue);
Bool queue_isEmpty(Queue);
Type queue_peek (Queue);
void queue_offer(Type, Queue);
Type queue_poll(Queue);
void queue_destroy(Queue);
void queue_print(Queue);

#endif /* QUEUE_H_ */
