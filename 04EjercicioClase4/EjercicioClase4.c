/*
 * EjercicioClase4.c
 *
 *  Created on: 22 ago. 2024
 *      Author: iker.contla
 */

#include <stdio.h>
#include <stdlib.h>

//Ejercicio 1
// Dado el siguiente tipo: typedef enum {False, True} bool;
// Crea una funcion equals que reciba dos cadenas de texto y devuelva True si ambas cadenas son iguales
// en caso contrario devuelva False

//primero definimos tipo
typedef enum {False, True} Bool;

//creamos la funcion

Bool equals (char* string1, char* string2){

	//creamos un ciclo while que comprobara todos los elementos hasta llegar al caracter final \0
	while (*string1 != '\0') {
		if (*string1 == *string2) {
			string1++;
			string2++;
		} else {
			return False;
		}
	}
	if (*string2 == '\0'){
		return True;
	} else {
		return False;
	}
}

int main()                                                                                                                                                                                           {

	char myString1 = "Hola Mundo";
	char myString2 = "Hola Mundo";

	printf("%c", equals(myString1, myString2));


	return 0;
} //Fin de main
