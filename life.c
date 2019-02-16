#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y) {
	// TO DO: REPLACE THIS LINE YOUR IMPLEMENTATION
	// an array size x, each each index points to an array size y
	// ex; x = 2, y = 3 (char)
	// x --> y y y
	// x --> y y y

	//allocating the num rows
	char **c = (char **)malloc(x*sizeof(char));
	
	//adding columns to the rows
	for(int i = 0; i < x; i++) {
		//(c[i*sizeof(char)] = (char *)malloc(y*sizeof(char));
		*(c+i) = (char *)malloc(y*sizeof(char));
	}
	
	return c;
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid) {
	// TO DO: IMPLEMENT THIS FUNCTION

	for(int i = 0; i < x; i++) {
		//printf("\n"); 
		for(int j = 0; j < y; j++) {
			*(*(grid+i)+j) = '-';
			printf("%c ", (*(*(grid+i)+j)));
		}
		printf("\n"); 
	}
	printf("\n"); 
}

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid) {
	// TO DO: REPLACE THIS LINE YOUR IMPLEMENTATION
	return NULL;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid) {
	// TO DO: REPLACE THIS LINE YOUR IMPLEMENTATION
	return 0;
}

// You are free to add other helper functions in this file

