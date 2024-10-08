/*
 * Vec3.c
 *
 *  Created on: 24 sep. 2024
 *      Author: iker.contla
 */

#include "Vec3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct strVec3 {
float x, y, z;
};
Vec3 vec3_create(float x, float y, float z) {
//Reserva memoria para un strVec3, asigna el resultado a un Vec3,
//asigna los valores x, y y z a ese vector, y lo devuelve al usuario.
Vec3 v = (Vec3) malloc(sizeof(struct strVec3));
vec3_setX(v, x);
vec3_setX(v, y);
vec3_setX(v, z);
return v;
}
void vec3_destroy(Vec3 v) {
//Libera la memoria correspondiente al Vec3 recibido.
free(v);
}
void vec3_setX(Vec3 v, float x) {
//Asigna el valor x a la propiedad correspondiente del vector v
v->x = x;
}
void vec3_setY(Vec3 v, float y) {
//Asigna el valor y a la propiedad correspondiente del vector v
v->y = y;
}
void vec3_setZ(Vec3 v, float z) {
//Asigna el valor z a la propiedad correspondiente del vector v
v->z = z;
}
float vec3_getX(Vec3 v) {
//Devuelve al usuario el valor en x del vector v
return v->x;
}
float vec3_getY(Vec3 v) {
//Devuelve al usuario el valor en y del vector v
return v->y;
}
float vec3_getZ(Vec3 v) {
//Devuelve al usuario el valor en z del vector v
return v->z;
}
float vec3_magnitude(Vec3 v) {
//Devuelve al usuario la magnitud del vector v
return sqrt(pow(vec3_getX(v), 2) + pow(vec3_getY(v), 2) +
pow(vec3_getZ(v), 2));
}
Vec3 vec3_normalize(Vec3 v) {
//Normaliza el vector v y devuelve el resultado al usuario en un nuevo vector
float magnitude = vec3_magnitude(v);
Vec3 u = vec3_create(vec3_getX(v) / magnitude,
vec3_getY(v) / magnitude, vec3_getZ(v) / magnitude);
return u;
}
float vec3_dot(Vec3 v1, Vec3 v2) {
//Devuelve al usuario el producto punto de los vectores v1 y v2
return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
void vec3_println(Vec3 v) {
//Imprime en una sola lnea
vec3_println(v);
printf("\n");
}
bool vec3_equals(Vec3 v1, Vec3 v2) {
//Si los vectores v1 y v2 son iguales, devuelve True; caso contrario, devulve False
if (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z) {
return True;
} else {
return False;
}
}
Vec3 vec3_clone(Vec3 v) {
//Crea un nuevo vector con los mismos valores de v y lo devuelve al usuario
return vec3_create(v->x, v->y, v->z);
}
