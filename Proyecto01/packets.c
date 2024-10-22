/*
 * packets.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ikerb
 */

#include <stdio.h>

typedef enum { IN_IN, IN_OUT, OUT_IN} Direction;
typedef enum { IGMP, TCP, UDP} Protocol;
typedef unsigned int Count;

typedef struct {
    long long timestamp;
    Direction direction;
    char sourceIP[16];
    char destIP[16];
    Protocol protocol;
    unsigned int port;
    Count bytes;
} Packet;

//Reto 1
//Funcion que recibe un arreglo de paquetes, numero de elementos en el arrego, y 3 enteros
void countDirections(Packet* packets, int N, int* c1, int* c2, int* c3 ){
    *c1 = 0;
    *c2 = 0;
    *c3 = 0;

    Packet* currentPacket = packets;

    //para cada entero sumar 1 dependiendo si del tipo de direccion del paquete
    for (int i = 0; i<N; i++){
        switch (currentPacket->direction){
            case IN_IN:
                (*c1)++;
                break;
            case IN_OUT:
                (*c2)++;
                break;
            case OUT_IN:
                (*c3)++;
                break;
        }
        currentPacket++;
    }

    Direction maxDirection = IN_IN;
    int maxCount = *c1;
    if (*c2 > maxCount) {
        maxCount = *c2;
        maxDirection = IN_OUT;
    }
    if (*c3 > maxCount) {
        maxCount = *c3;
        maxDirection = OUT_IN;
    } else if (*c3 == maxCount) {
    }

    printf("Max direction: ");
    switch (maxDirection) {
        case IN_IN:
            printf("IN_IN\n");
            break;
        case IN_OUT:
            printf("IN_OUT\n");
            break;
        case OUT_IN:
            printf("OUT_IN\n");
            break;
    }
}//fin countDirections


//Reto 3
// Definimos el tipo de dato CompareFunc como un apuntador a una función
// que recibe dos apuntadores a Packet y devuelve un entero
typedef int (*CompareFunc)(Packet *p1, Packet *p2);

int compareBytes (Packet *p1, Packet *p2) {
return p1->bytes - p2->bytes;
}
int compareIP (Packet *p1, Packet *p2) {
return strcmp(p1->sourceIP, p2->sourceIP);
}

//Reto 4
//funcion insertionSort
void insertionSort(Packet packets[], int N, CompareFunc compare1, CompareFunc compare2) {
    for (int i = 1; i < N; i++) { //comienza en indice 1, ya que el algoritmo de insercion considera que el primer elemento ya esta ordenado
        Packet estePacket = packets[i];
        int j = i - 1; //indice j para poder comparar j con i

        // usamos el criterio compare1, y si es empate (compare1 devuelve 0), usamos compare2
        while (j >= 0 && (compare1(&packets[j], &estePacket) > 0 ||
                          (compare1(&packets[j], &estePacket) == 0 && compare2(&packets[j], &estePacket) > 0))) {
            packets[j + 1] = packets[j];
            j--;
        }
        packets[j + 1] = estePacket; //insertamos el packete en el indice j + 1
    }
}

//Retor 5
//funcion insertionSort1 (sin corchetes)
void insertionSort1(Packet *packets, int N, CompareFunc compare1, CompareFunc compare2) {
    for (int i = 1; i < N; i++) {
        // Apuntamos a la posición actual usando aritmética de apuntadores
        Packet estePacket = *(packets + i);
        int j = i - 1;

        // Usamos aritmética de apuntadores para comparar elementos
        while (j >= 0 && (compare1(packets + j, &estePacket) > 0 ||
                          (compare1(packets + j, &estePacket) == 0 && compare2(packets + j, &estePacket) > 0))) {
            // Mover el paquete en j hacia adelante
            *(packets + j + 1) = *(packets + j);
            j--;
        }
        // Insertar el paquete estePacket en su posición correcta
        *(packets + j + 1) = estePacket;
    }
}
int main(){

	//Reto 2
    Packet packetsArray[8] = {
        {1, IN_IN, "192.168.1.1", "8.8.8.8", IGMP, 123, 650},
        {2, IN_OUT, "192.168.1.2", "8.8.8.4", TCP, 80, 200},
        {3, OUT_IN, "192.168.1.3", "8.8.8.8", UDP, 53, 300},
        {4, IN_IN, "192.168.1.4", "8.8.8.8", IGMP, 123, 700},
        {5, OUT_IN, "192.168.1.5", "8.8.8.4", TCP, 80, 500},
        {6, IN_IN, "192.168.1.6", "8.8.8.8", UDP, 890, 600},
        {7, OUT_IN, "192.168.1.7", "8.8.8.4", UDP, 560, 400},
        {8, IN_OUT, "192.168.1.8", "8.8.8.8", IGMP, 130, 800}
    };

    int c1, c2, c3;

    countDirections(packetsArray, 8, &c1, &c2, &c3);

    printf("c1[IN_IN]: %d, c2[IN_OUT]: %d, c3[OUT_IN]: %d\n", c1, c2, c3);

    //Reto 4 (impresion)
    //primero ordenamos el arreglo
    insertionSort(packetsArray, 8, compareBytes, compareIP);

    // Imprimimos el arreglo ordenado
    for (int i = 0; i < 8; i++) {
    	printf("Packet %d: IP = %s, Bytes = %d\n", i, packetsArray[i].sourceIP, packetsArray[i].bytes);
    }

    printf("\n");

    //Reto 5 (impresion)
    Packet packetsArray1[8] = {
           {1, IN_IN, "192.168.1.1", "8.8.8.8", IGMP, 123, 100},
           {2, IN_OUT, "192.168.1.2", "8.8.8.4", TCP, 80, 200},
           {3, OUT_IN, "192.168.1.3", "8.8.8.8", UDP, 53, 300},
           {4, IN_IN, "192.168.1.4", "8.8.8.8", IGMP, 123, 700},
           {5, OUT_IN, "192.168.1.5", "8.8.8.4", TCP, 80, 500},
           {6, IN_IN, "192.168.1.6", "8.8.8.8", UDP, 890, 600},
           {7, OUT_IN, "192.168.1.7", "8.8.8.4", UDP, 560, 400},
           {8, IN_OUT, "192.168.1.8", "8.8.8.8", IGMP, 130, 800}
       };


       insertionSort1(packetsArray1, 8, compareBytes, compareIP);

       for (int i = 0; i < 8; i++) {
           	printf("Packet %d: IP = %s, Bytes = %d\n", i, packetsArray1[i].sourceIP, packetsArray1[i].bytes);
           }


    return 0;
}
