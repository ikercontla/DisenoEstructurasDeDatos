/*
 * EjercicioClase3.c
 *
 *  Created on: 20 ago. 2024
 *      Author: iker.contla
 */


#include <stdio.h>
#include <stdlib.h>

int length(char* myString) {
		/*
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
		*/
		int count = 0;
		while (*myString != '\0') {
			count ++;
			myString ++;
		}

		return count;
	}
int main() {


	char miCadena = "Hola Mundo";
	printf("la longitud de la cadena es: ". length(miCadena));

	// Crea una variable p1 que apunte a un numero real de 64 bits r1 cuyo valor inicial es -7.528

	double r1 = -7.528;
	double* p1 = &r1;

	// Imprime en consola el valor de p1 y su direccion de memoria

	printf("%p\n", p1);
	printf("%p\n", &p1);

	//Divida entre dos el valor apuntado por p1

	*p1 = *p1/2;

	//crea un arreglo a1 con capacidad para 100 enteros de 16 bits y con valor inicial de 0 para cada uno

	short int a1[100] = { 0 };

	// Crea una variable p3 que apunte al 3er elemento de a1 y asignale 8

	short int* p3 = a1 + 2; //accedemos al 3 elemento del arreglo a1
	*p3 = 8; // Asignamos 8 al elemento 3
	p3 ++; // Accedemos al 4 elemento
	*p3 = 9; // Cambiamos a 9 el elemento 4

	printf("%hi %hi\n", a1[2], a1[3]);

<<<<<<< HEAD

	// Ejercicio de verdad

int length(char* myString) {

	int count = 0;
	while (*myString != '\0'){
		count++;
		myString++;

	}

	return count;

	/* int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
		*/

=======
>>>>>>> fda50336f9fd0793b154eabe607c2f76b321a6a4
	}

	return 0;



