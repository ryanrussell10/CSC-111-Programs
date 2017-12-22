/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/10/22
 Assignment: A4
 File name: V00873387A4P2.c
 Description: This program reads a line of text from the user
 and prints out the text (in one line) with the first letter of each word capitalized
 and extra spaces between words removed.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void read_and_capitalize(){
	char c;
	//Get the first character from the user
	c = getchar();

	//Loop to read characters until a newline (\n) is encountered
	while(c != '\n'){
		//Print out the current character
		while(isspace(c)){
			c = getchar();
			if(!(isspace(c))){
				printf(" ");
			}
		}
		if(isalpha(c)){
			printf("%c", toupper(c));
			c = getchar();
		}
		while(!(isspace(c))){
			printf("%c", tolower(c));
			c = getchar();
		}
	}
	printf("\n");
} /* read_and_capitalize */


int main(void){

	printf("Enter a line of text: ");
	fflush(stdout);
	read_and_capitalize();
	return EXIT_SUCCESS;
} /*main*/
