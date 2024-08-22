/*
 * EjercicioClase3.c
 *
 *  Created on: 20 ago. 2024
 *      Author: iker.contla
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Ejercicio 1
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

//Ejercicio 2

//La funcion swap recibe 2 apuntadores
void swap(int* a, int* b)
{
	int temp = *a; //Almacenamos en una variable temporal el apuntador a
	*a = *b; //En el apuntador a almacenamos el apuntar b
	*b = temp; //Ahora en el apuntador b almacenamos lo que estaba en la variable temp
}

//Ejercicio 3

typedef struct {
	float x;
	float y;
}Vec2D;

void toUnit(Vec2D* v){

	float magnitud = sqrt(pow(v->x, 2) + pow(v->y, 2));
	v->x = v->x/magnitud;
	v->y = v->y/magnitud;


}

int main() {


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

	//Ejercicio 1

	// char miCadena = "Hola Mundo";
	// printf("la longitud de la cadena es: ". length(miCadena));

	// Ejercicio 2

	int x = 35;
	int y = 40;

	swap(&x, &y);

	printf("x: %d, y: %d\n,", x, y);

	//Ejercicio 3

	Vec2D miVector = {3.0, 4.0};
	Vec2D miVectorApuntador = &miVector;
	toUnit(&miVectorApuntador);

	printf("Vector Unitario: %.2f, %.2f\n", miVector.x, miVector.y);

}





