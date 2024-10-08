/*
 * EjercicioClase1.c
 *
 *  Created on: 13 ago. 2024
 *      Author: iker.contla
 */


#include <stdio.h>
int main() {

	// Crear una variable

	char c1 = 'C';

	// Crear apuntador

	char* pc1 = &c1;

	// podemos modificar la variable c1 a traves de el apuntador pc1

	// Imprimir (valor c1)

	printf("%c\n", c1);

	// Imprimir la direccion de la variable c1

	printf("%p\n", &c1);

	// Imprimir valor del apuntador pc1

	printf("%p\n", pc1);

	// Imprimir la direccion de memoria de pc1

	printf("%p\n", &pc1);

	// CAmbios a variable original (directa)

	c1 = 'Z';

	printf("%c\n", c1);

	// Cambio valor de variable a traves del apuntador

	*pc1 = 'D';

	printf("%c\n", c1);




	return 0;
}
