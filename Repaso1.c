/*
 * repaso1.c
 *
 *  Created on: 10 sep. 2024
 *      Author: iker.contla
 */
#include <stdio.h>
#include <math.h>

typedef struct {
	float i, j;
}Vec2D;

int main() {

	/*Apuntadores
Declare tres flotantes (myFloat1, myFloat2, myFloat3) y tres apuntadores a flotante
(myFloatPointer1, myFloatPointer2, myFloatPointer3). Guarde las direcciones de los
flotantes en los apuntadores. Asigne, a través de los apuntadores, los valores 2 y
3 a los primeros dos flotantes. Asigne, a través de los apuntadores, el resultado
de la suma de los primeros dos flotantes al tercero. */

	//declaramos los tres flotantes
	float myFloat1_1, myFloat2_1, myFloat3_1;

	//apuntadores a flotante que guarde las direcciones de los flotantes en los apuntadores
	float * myFloatPointer1 = &myFloat1;
	float * myFloatPointer2 = &myFloat2;
	float * myFloatPointer3 = &myFloat3;

	//asignamos a travez de los apuntadores los valores 2 y 3 a los primeros dos flotantes

	*myFloatPointer1 = 2;
	*myFloatPointer2 = 3;

	//asignamos a traves de los apuntadores el resultado de la suma de los primeros dos flotantes al tercero

	*myFloatPointer3 = *myFloatPointer1 + *myFloatPointer2;

	//imprimimos para verificar que este bien
	printf("Ejercicio 1\n myFloat1: %.1f\n myFloat2: %.2f\n myFloat3: %.2f\n", myFloat1, myFloat2, myFloat3);

	/*Aritmética de apuntadores
	Desarrolle una función incrementArray que reciba un arreglo de enteros y un entero
	N que indique su tamaño. La función deberá incrementar en 1 el valor de cada
	elemento del arreglo. No emplee notación de corchetes para resolver este problema
	(use aritmética de apuntadores para acceder a los elementos). */

	//funcion incrementArray que no regresa nada
	void incrementArray(int array[], int n){ //la funcion recibe un arreglo de enteros y un entero n que determina el tamano del arreglo
		for (int i = 0; i<n; i++){ //hacemos un ciclo for que vaya recorriendo el arreglo n veces (ya que n es el tamano del arreglo)
			*(array + i) =+ 1; //accedemos al elemento con el * en array + i (en la primera iteracion entrara a array + 0,
							   //es decir al primer elemento, segunda iteracion array + 1, es decir al segundo elemento)
							   //despues de acceder al elemento le sumamos 1
		}
	}//fin funcion incrementArray

	//crearemos una funcion para imprimir el arreglo para verificar que estemos bien
	void printArray(int array[], int n) {
		for (int i = 0; i<n; i++) {
			printf("Ejercicio2\n %d ", array[i]);
		}
	}//fin funcion printArray

	/*Apuntadores a funciones
	Dada la siguiente función,
	int add(int x, int y) {
	return x + y;
	}
	Cree un apuntador myFunctionPointer capaz de apuntar a una función como add y
	almacene en él la dirección de dicha función. Declare una variable de tipo entero
	mySum y asígnele el resultado de una llamada a la función con los parámetros 5 y 7.
	Llame a la función a través del apuntador myFunctionPointer, no directamente.*/


	//creamos la funcion
	int add(int x, int y) { //esta funcion regresa un entero y recibe 2 enteros (x y)
		return x + y;
	}

	//creamos un apuntador myFunctionPointer capaz de apuntar a una funcion como add
	int (*myFunctionPointer)(int, int) = add; //estructura del apuntdaor a funcion
											//primer int se refiere al tipo de dato que devuelve la funcion
											//(*myFunctionPointer) nombre del apuntador no olvidar el asterisco
											//(int, int) tipos de datos que recibe la funcion
											//= add; guarda la funcion en el apuntador a funcion

	//declaramos una variable de tipo entero mySum y le asignamos el resultado de una llamada a la funcion con los parametros 5 y 7
	//tenemos que llamar la funcion a traves del apuntador
	int mySum = myFunctionPointer(5, 7);
	printf("Ejercicio 3\n la suma es: %d", mySum); //imprimimos la suma para verificar que lo hicimos bien

	/*Apuntadores a estructuras
	Defina una estructura Vec2D que tenga dos atributos de tipo float: i y j.
	Implemente una función printVec2D que reciba un apuntador a Vec2D e imprima el
	vector con el formato { i, j }. Cree un vector myVector, asígnele valores y llame a
	la función printVec2D para él. */

	//primero definimos la estructura (la definimos afuera del main)

	//implementamos una funcion printVec2D que reciba un apuntador a Vec2D e imprima el vector con el formato { i, j }
	void printVec2D(Vec2D * v) {
		printf( "{ %.2f, %.2f }\n", v->i, v->j); //accedemos a los atributos de la forma v->i y v->j
	}

	Vec2D myVector = {2,3}; //definimos un vector
	Vec2D * myVectorPointer = &myVector; //declaramos un apuntador al vector (recordar &)
	printVec2D(myVectorPointer); //imprimimos el vector a traves del apuntador

	/*Pase por valor y por referencia
	Implemente una función powInPlace reciba dos argumentos: un apuntador a entero y un
	entero. El apuntador referirá un entero que desee elevarse a una potencia, y el
	entero la potencia a la que se desea que sea elevado. Declare un entero, asígnele
	un valor y llame a la función powInPlace para él, elevándolo a la potencia 5.*/

	//funcion powInPlace
	void powInPlace(int * x, int y){ //el apuntador a i sera un entero que desea elevarse a una potencia
									// el entero j sera la potencia a la que sera elevado

		int numeroGuardado = *x; //guardamos el valor de x en una variable aparte para que podamos ir multiplicando x por esa variable guardada
		for (int i = 0; i<y-1; i++){
			*x = *x * numeroGuardado;
		}
	}

	int myNum = 6;
	int * myPointerNum = &myNum;
	powInPlace(myPointerNum, 3);
	printf("%d\n", myNum);

	/*Arreglos de apuntadores
	Declare cuatro variables de tipo Vec2D y cuatro variables de tipo flotante. Asigne
	valores a las variables de tipo Vec2D. Cree dos arreglos de apuntadores para
	almacenar las direcciones de las variables Vec2D y float. Implemente una función
	que reciba un arreglo de apuntadores a Vec2D, un arreglo de apuntadores a float, y
	un entero N que indique el tamaño de los arreglos. La función deberá calcular la
	magnitud de cada vector y almacenarlo en la posición correspondiente en el arreglo
	de flotantes.*/

	//declaramos cuatro variables de tipo Vec2D y les asignamos valores
	Vec2D myVector1 = {1,2};
	Vec2D myVector2 = {3,4};
	Vec2D myVector3 = {5,6};
	Vec2D myVector4 = {7,8};
	//declaramos cuatro variables de tipo flotante
	float myFloat1, myFloat2, myFloat3, myFloat4;

	//creamos dos arreglos de apuntadores para almacenar las direcciones d elas variables Vec2D y float
	Vec2D * myVectorPointerArray[] = { &myVector1, &myVector2, &myVector3, myVector4 };
	float * myFloatPointerArray[] = { &myFloat1, &myFloat2, &myFloat3, &myFloat4 };

	//implementamos una funcion que reciba un arreglo de apuntadores Vec2D
	//un arreglo de apuntadores a float y un entero N que indique el tamano de los arreglos
	void magnitudVector(Vec2D ** myVectorPointerArray[4], float ** myFloatPointer[4], int n) {
		//la funcion debe calcular la magnitud de cada vector y almacenarlo en la posicion correspondiente en el arreglo de flotantes
		for (int i = 0; i<n; i++) {
			*myFloatPointer[i] = sqrt((pow(*myVectorPointer[i]->i, 2) + (pow(*myVectorPointer[i]->j, 2))));
		}
	}

	magnitudVector(myVectorPointerArray, myFloatPointerArray, 4);

	for (int i= 0; i<4; i++) {
		print("%.2f", *myFloatPointerArray[i]);
	}


}
