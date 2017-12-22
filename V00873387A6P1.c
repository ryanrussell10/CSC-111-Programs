/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/11/19
 Assignment: A6
 File name: V00873387A6P1.c
 Description: This program reads and scrambles the words in a text file.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME    ("A6P1_2016_Sherlock.txt")
#define OUTPUT_FILENAME   ("A6P1_2016_SherlockEncoded.txt")

void process_file(FILE* ifp, FILE* ofp) {
	printf("Begin file processing\n\n");
	char characters[5000];
	int word_counter = 0;
	while (fscanf(ifp, "%s", characters) != EOF) {
		int x = 0;
		char c;
		int line = strlen(characters);
		c = characters[1];
		if (line > 0) {
			for (x = 1; x < line; x++) {
				if (x == line - 2) {
					characters[x] = c;
				} else if (x == line - 1) {
				} else {
					characters[x] = characters[x + 1];
				}
			}
		}
		printf("%s ", characters);
		fprintf(ofp, "%s ", characters);
		word_counter++;
		if (word_counter == 45) {
			word_counter = 0;
			printf("\n");
			fprintf(ofp, "\n");
		}
	}
	printf("\n\nEnd file processing\n");
} /* process_file */

int main(void) {
	printf("Starting text encoding...\n\n");
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	FILE* ifp = fopen(INPUT_FILENAME, "r");
	if (ifp == NULL) {
		printf("Cannot open input file %s\n", INPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /* if */

	FILE* ofp = fopen(OUTPUT_FILENAME, "w");
	if (ofp == NULL) {
		printf("Cannot create output file %s\n", OUTPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /* if */

	process_file(ifp, ofp);

	fclose(ofp);
	fclose(ifp);
	printf("\nEncoding finished.\n");
	return EXIT_SUCCESS;
} /*main*/
