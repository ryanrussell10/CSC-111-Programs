/*
 ============================================================================
 Name: Ryan Russell
 UVicID: V00873387
 Date: 2016/11/19
 Assignment: A6
 File name: V00873387A6P2.c
 Description: This program produces various shapes of
 random colours and sizes in SVG format.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME    ("random_shapes.txt")
#define OUTPUT_FILENAME   ("shapes_output.html")

/* Size of the canvas - Do not change */
#define CANVAS_SIZE 800
#define CANVAS_SIZE_X CANVAS_SIZE
#define CANVAS_SIZE_Y CANVAS_SIZE

#define MAX_LINE_LENGTH 1000

void process_shapes(FILE* ifp, FILE* ofp) {
	char line[MAX_LINE_LENGTH];

	//SVG prologue code section begins

	if (!ofp) {
		printf("Error: Output File == NULL\n");
		exit(1);
	}
	fputs("<!DOCTYPE html>\n", ofp);
	fputs("<html>\n", ofp);
	fputs("<head>\n", ofp);
	fputs("<title>CSC 111 Fall 2016 -  Assignment 6 Part 2</title>\n", ofp);
	fputs("</head>\n", ofp);
	fputs("<body>\n", ofp);
	fprintf(ofp, "CSC 111 Art: <br />\n");
	fprintf(ofp, "<svg width=\"800px\" height=\"800px\">\n");

	//SVG prologue code section ends

	/* Read each line from the input file with fgets */
	while(fgets(line, MAX_LINE_LENGTH, ifp) != NULL){

		//Reading and converting section begins

		char shape[100];
		int rectX;
		int rectY;
		int rectWidth;
		int rectHeight;
		int rectSideLength;
		int colourR;
		int colourG;
		int colourB;
		int circX;
		int circY;
		int circRad;
		int ellRadX;
		int ellRadY;
		float opacity;

		fflush stdout;
		sscanf(line, "%s", shape);

		if (strcmp(shape, "SQUARE") == 0) {
			fflush stdout;
			sscanf(line, "%s %d %d %d %d %d %d %f", shape, &rectX, &rectY, &rectSideLength, &colourR, &colourG, &colourB, &opacity);
			printf("%s %d %d %d %d %d %d %f\n", shape, rectX, rectY, rectSideLength, colourR, colourG, colourB, opacity);
			fprintf(ofp,"<rect x = %d y = %d width = %d height = %d style = fill:rgb(%d,%d,%d); fill-opacity:%f\n/>", rectX, rectY, rectSideLength, rectSideLength, colourR, colourG, colourB, opacity);
		}
		else if (strcmp(shape, "RECTANGLE") == 0) {
			fflush stdout;
			sscanf(line, "%s %d %d %d %d %d %d %d %f", shape, &rectX, &rectY, &rectWidth, &rectHeight, &colourR, &colourG, &colourB, &opacity);
			printf("%s %d %d %d %d %d %d %d %f\n", shape, rectX, rectY, rectWidth, rectHeight, colourR, colourG, colourB, opacity);
			fprintf(ofp,"<rect x = %d y = %d width = %d height = %d style = fill:rgb(%d,%d,%d); fill-opacity:%f\n/>", rectX, rectY, rectWidth, rectHeight, colourR, colourG, colourB, opacity);
		}
		else if (strcmp(shape, "CIRCLE") == 0) {
			fflush stdout;
			sscanf(line, "%s %d %d %d %d %d %d %f", shape, &circX, &circY, &circRad, &colourR, &colourG, &colourB, &opacity);
			printf("%s %d %d %d %d %d %d %f\n", shape, circX, circY, circRad, colourR, colourG, colourB, opacity);
			fprintf(ofp,"<circle cx = %d cy = %d r = %d style = fill:rgb(%d,%d,%d); fill-opacity:%f\n/>", circX, circY, circRad, colourR, colourG, colourB, opacity);
		}
		else if (strcmp(shape, "ELLIPSE") == 0) {
			fflush stdout;
			sscanf(line, "%s %d %d %d %d %d %d %d %f", shape, &circX, &circY, &ellRadX, &ellRadY, &colourR, &colourG, &colourB, &opacity);
			printf("%s %d %d %d %d %d %d %d %f\n", shape, circX, circY, ellRadX, ellRadY, colourR, colourG, colourB, opacity);
			fprintf(ofp,"<ellipse cx = %d cy = %d rx = %d ry = %d style = fill:rgb(%d,%d,%d); fill-opacity:%f\n/>", circX, circY, ellRadX, ellRadY, colourR, colourG, colourB, opacity);
		}

		//Reading and converting section ends

	}

	//SVG epilogue section begins

	fputs("</svg>\n", ofp);
	fputs("</body>\n", ofp);
	fputs("</html>\n", ofp);

	//SVG epilogue section ends

} /* process_shapes */

int main(void) {
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

	process_shapes(ifp, ofp);

	fclose(ofp);
	fclose(ifp);
	return EXIT_SUCCESS;
} /*main*/
