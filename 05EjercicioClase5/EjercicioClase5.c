/*
 * EjercicioClase5.c
 *
 *  Created on: 29 ago. 2024
 *      Author: iker.contla
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

//	// Ejercicio 1 Diapositivas "Memoria Dinamica"
//
//	//Crea dos variables globales, una con valor inicial y la otra no
//	//En main, crea dos variables estaticas, una con valor inicial y la otra no
//	static int myGlobal1 = 5;
//	static int myGlobal2;
//	//En main, crea una variable entero corto y un apuntador a enteros cortos
//	short int myShortInt; //variable entero corto
//	short int* myShortIntPointer; //apuntador a enteros cortos
//
//	myShortIntPointer = (short int*) malloc(20 * sizeof(short int)); //Reserva espacio para 20 enteros cortos en memoria dinamica
//
//	//Imprime la direccion de memoria de todas las variables creadas, asi como de los primeros 3 enteros cortos en memoria dinamica
//	printf("myGlobal1: %p\n", &myGlobal1);
//	printf("myGlobal2: %p\n", &myGlobal2);
//	printf("myShortInt: %p\n", &myShortInt);
//	printf("myShortIntPointer: %p\n", &myShortIntPointer);
//	printf("myShortIntPointer(valor): %p\n", myShortIntPointer);
//	printf("myShortIntPointer[0]: %p\n", &myShortIntPointer[0]);
//	printf("myShortIntPointer[1]: %p\n", &myShortIntPointer[1]);
//	printf("myShortIntPointer[2]: %p\n", &myShortIntPointer[2]);
//
	//Ejercicio 2a

	int* myIntPointer; // apuntador enteros ptr, inicialmente nulo

	for (int i=0; i<10; i++) { // estructura repetitiva, ejecuta 10 veces lo siguiente

		//myIntPointer = (int*) malloc(64 * sizeof(int)); //Reserva un espacion en memoria dinamica para 64 numeros enteros y guarda la direccion de memoria inicial en ptr

		//Ejercicio2d
		int* myIntPointer = (int*) calloc(64, sizeof(int)); //Utilice calloc para reservar espacio en lugar de malloc

		myIntPointer[9] = 5000; // asigna 5000 a la posicion 10
		//printf("myIntPointer:  %p\n", myIntPointer); //imprime la direccion de memoria inicial

		printf("myIntPointer[9] antes de liberar: %d\n", myIntPointer[9]); //imprime el valor del elemento 10 antes de liberar memoria
		//Ejercicio 2b
		free(myIntPointer); // libera el espacio

		//Ejercicio 2c
		printf("myIntPointer[9] despues de liberar: %d\n", myIntPointer[9]); //imprime el valor del elemento 10 despues de liberar


	}

}


