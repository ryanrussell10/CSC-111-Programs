/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/10/21
 Assignment: A4
 File name: V00873387A4P1.c
 Description: This program reads integers from the user and
 converts each value to Roman numerals.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x;
	for(x = 1; x >= 1 && x <= 4999 ; x++) {
		int num;
		printf("Enter a number between 1 and 4999: "); //tells user what to enter
		fflush(stdout);
		scanf("%d", &num); //reads user input
		printf("The value of %d in Roman numerals is ", num);
		if(num < 1 || num > 4999) {
			printf("invalid for the purpose of this program. Program will exit.");
			break;
		} //if statement ends loop if the number is invalid
		while(num >= 1 && num <= 4999) {
			if(num >= 1000) {
				printf("M");
				num = num - 1000;
			}
			else if(num >= 900 && num < 1000) {
				printf("CM");
				num = num - 900;
			}
			else if(num >= 500) {
				printf("D");
				num = num - 500;
			}
			else if(num >= 400 && num < 500) {
				printf("CD");
				num = num - 400;
			}
			else if(num >= 100) {
				printf("C");
				num = num - 100;
			}
			else if(num >= 90 && num < 100) {
				printf("XC");
				num = num - 90;
			}
			else if(num >= 50) {
				printf("L");
				num = num - 50;
			}
			else if(num >= 40 && num < 50) {
				printf("XL");
				num = num - 40;
			}
			else if(num >= 10) {
				printf("X");
				num = num - 10;
			}
			else if(num == 9) {
				printf("IX");
				num = num - 9;
			}
			else if(num >= 5) {
				printf("V");
				num = num - 5;
			}
			else if(num == 4) {
				printf("IV");
				num = num - 4;
		    }
			else if(num >= 1) {
				printf("I");
				num = num - 1;
			}
		} // while loop outlines requirements for printing each number to Roman numerals
		printf("\n\n"); //prints two newlines
	}

	return EXIT_SUCCESS;
}
