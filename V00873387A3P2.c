/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/10/10
 Assignment: A3
 File name: V00873387A3P2.c
 Description: This program prints six lines, with each line containing 11
 characters, which are a combination of “.“ and “X”.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printDot(){
	printf(".");
}/* printDot */

void printX(){
	printf("X");
}/* printX */

void printNewline(){
	printf("\n");
}/* printNewline */




int main(){
	int x, y;
	for(x = 1; x <= 6; x++) {
		for(y = 1; y <= 11; y++) {
		if(x == 6 ||
		(x == 5 && (y > 1 && y < 11)) ||
		(x == 4 && (y > 2 && y < 10)) ||
		(x == 3 && (y > 3 && y < 9)) ||
		(x == 2 && (y > 4 && y < 8)) ||
		(x == 1 && (y > 5 && y < 7)))
		printX();
		else if(x <= 5) printDot();
		}
		printNewline();
	}
	return EXIT_SUCCESS;
}/* main */
