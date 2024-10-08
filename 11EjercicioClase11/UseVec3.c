/*
 * UseVec3.c
 *
 *  Created on: 24 sep. 2024
 *      Author: iker.contla
 */

#include "Vec3.h"
#include <stdio.h>

int main() {

Vec3 myVector = vec3_create(4, 5, 7);
vec3_println(myVector);
Vec3 myNormalizedVector = vec3_normalize(myVector);
vec3_println(myNormalizedVector);
Vec3 myVector2 = vec3_create(1, 2, 3);
printf("producto punto de myVector y myVector 2: %.2f\n", vec3_dot(myVector, myVector2));
Vec3 myClonedVector = vec3_clone(myVector);
if (vec3_equals(myVector, myClonedVector)) {
	printf("myVector y myClonedVector apuntan a vectores con los mismo valores\n");
}
if (myVector != myClonedVector) {
	printf("pero myVector y myClonedVector no son lo mismo(contienen diferentes direcciones) \n");
}
return 0;
}
