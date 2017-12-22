/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/10/09
 Assignment: A3
 File name: V00873387A3P1.c
 Description: This program computes a table of circle, sphere and cone
 properties.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//(1) Computes the area of a circle with radius r
float circleArea(float r){
	return M_PI * (r * r);
}

//(2) Computes the perimeter of a circle with radius r
float circlePerimeter(float r){
	return M_PI * (r + r);
}

//(3) Computes the volume of a sphere with radius r
float sphereVolume(float r) {
	return (4.0/3.0) * M_PI * (r * r * r);
}

//(4) Computes the surface area of a sphere with radius r
float sphereSurfaceArea(float r) {
	return 4.0 * M_PI * (r * r);
}

//(5) Computes the volume of a cylinder with base radius r and height h
float cylinderVolume(float r, float h){
	float baseArea = circleArea(r);
	float volume = h * baseArea;
	return volume;
}

//(6) Computes the surface area of a cylinder with base radius r and height h
float cylinderSurfaceArea(float r, float h) {
	float basePerimeter = circlePerimeter(r);
	float baseTimesHeight = basePerimeter * h;
	float area = circleArea(r);
	float twiceTheArea = 2 * area;
	float surfaceArea = baseTimesHeight + twiceTheArea;
	return surfaceArea;
}

//(7) Computes the volume of a cone with base radius r and height h
float coneVolume(float r, float h) {
	float baseArea = circleArea(r);
	float volume = baseArea * (h/3);
	return volume;
}

//(8) Computes the surface area of a cone with base radius r and height h
float coneSurfaceArea(float r, float h) {
	float baseArea = circleArea(r);
	float surfaceArea = baseArea + (M_PI * r * (sqrt((h * h) + (r * r))));
	return surfaceArea;
}

//main: prints the returned values of previous functions
int main(void){
	float radius = 6.2;
	float height = 8.1;
	float circArea = circleArea(radius);
	float spVol = sphereVolume(radius);
	float spArea = sphereSurfaceArea(radius);
	float cylVol = cylinderVolume(radius, height);
	float cylArea = cylinderSurfaceArea(radius, height);
	float conVol = coneVolume(radius, height);
	float conArea = coneSurfaceArea(radius, height);
	float sumVolume = spVol + cylVol + conVol;
	float sumArea = circArea + spArea + cylArea + conArea;
	printf("Circle:   Radius = %3.1f  %36s   = %5.1f\n", radius, "Area", circArea);
	printf("Sphere:   Radius = %3.1f  %20s   = %5.1f  %4s   = %5.1f\n", radius, "Volume", spVol, "Area", spArea);
	printf("Cylinder: Radius = %3.1f  Height = %3.1f  Volume   = %5.1f  Area   = %5.1f\n", radius, height, cylVol, cylArea);
	printf("Cone:     Radius = %3.1f  Height = %3.1f  Volume   = %5.1f  Area   = %5.1f\n", radius, height, conVol, conArea);
	printf("Sum:      %35s = %6.1f  %5s = %6.1f\n", "Volumes", sumVolume, "Areas", sumArea);
	return EXIT_SUCCESS;
}




