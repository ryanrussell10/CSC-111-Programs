/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/10/10
 Assignment: A3
 File name: V00873387A3P3.c
 Description: This program produces a table of the volumes of cones with
 radius in the range 1 through 9 and height in the range 1 through 10.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1) Computes the area of a circle with radius r
float circleArea(float r){
	return M_PI * (r * r);
}

//(2) Computes the volume of a cone with base radius r and height h
float coneVolume(float r, float h) {
	float baseArea = circleArea(r);
	float volume = baseArea * (h/3);
	return volume;
}

int main(void) {
	int x, y, z;
	printf("%-6s", "h");
	for(z = 1; z < 10; z++) {
		printf("r = %d  ", z);
	}
	printf("\n");
	for(y = 1; y < 11; y++) {
		printf("%-6d", y);
		for(x = 1; x < 10; x++) {
			float volumeOfCone = coneVolume(x,y);
			printf("%-7.2f", volumeOfCone);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
