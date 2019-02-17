#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y) {
	// an array size x, each each index points to an array size y
	// ex; x = 2, y = 3 (char)
	// x --> y y y
	// x --> y y y

	//checking for errors
	if(x > 30 || y > 30 || x < 3 || y < 3) {
		printf("The size of your grid must be between 3 and 30. Please retry. \n"); 
		exit(1); 
	}

	//allocating the num rows
	char **c = (char **)malloc(x*sizeof(char));
	
	//adding columns to the rows
	for(int i = 0; i < x; i++) {
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
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			if(*(*(grid+i)+j) == 0) {
				*(*(grid+i)+j) = '.';
			}
			else if(*(*(grid+i)+j) == 1) {
				*(*(grid+i)+j) = 'X'; 
			}
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
	/*
	1. A live cell with less than two live neighbors dies
	2. A live cell with two or three live neighbors lives
	3. A live cell with more than three neighbors dies
	4. A dead cell with three live neighbors becomes live
	*/
	char **temp = get_grid(x, y);
	for(int m = 0; m < x; m++) {
		for(int n = 0; n < y; n++) {
			temp[m][n] = grid[m][n]; 
		}
	} 

	int numNeighbors = 0; 
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			numNeighbors = get_neighbors(i, j, x, y, temp); 
			if(*(*(grid+i)+j) == 'X') {
				if(numNeighbors < 2) {
					//dying
					*(*(grid+i)+j) = '.';
				}
				else if(numNeighbors == 2 || numNeighbors == 3) {
					//lives
					*(*(grid+i)+j) = 'X';
				}
				else if(numNeighbors > 3) {
					//dying
					*(*(grid+i)+j) = '.';
				}
				//printf("%d \n", numNeighbors);
			}
			else{
				if(numNeighbors == 3) {
					//live
					*(*(grid+i)+j) = 'X';
				}
			}
		}
	}

	free(temp);
	return grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has. i and j are the coords
 */
int get_neighbors(int i, int j, int x, int y, char** grid) {
	int count = 0; 
	
	//up/left
	if(i > 0 && j > 0 && i < x && j < y) { //making sure i and j are in bounds
		if(*(*(grid+i-1)+j-1) == 'X') {
			count++; 
		}
	}

	//up
	if(i > 0 && j >= 0 && i <= x && j <= y) {
		if(*(*(grid+i-1)+j) == 'X') {
			count++; 
		}
	}

	//up/right
	if(i > 0 && j >= 0 && i < x && j < (y-1)) { 
		if(*(*(grid+i-1)+j+1) == 'X') {
			count++; 
		}
	}

	//left
	if(i >= 0 && j > 0 && i < x && j < y) { 
		if(*(*(grid+i)+j-1) == 'X') {
			count++; 
		}
	}

	//right
	if(i >= 0 && j >= 0 && i < x && j < (y-1)) { 
		if(*(*(grid+i)+j+1) == 'X') {
			count++; 
		}
	}

	//down/left
	if(i >= 0 && j > 0 && i < (x-1) && j < y) { 
		if(*(*(grid+i+1)+j-1) == 'X') {
			count++; 
		}
	}

	//down
	if(i >= 0 && j >= 0 && i < (x-1) && j < y) { 
		if(*(*(grid+i+1)+j) == 'X') {
			count++; 
		}
	}

	//down/right
	if(i >= 0 && j >= 0 && i < (x-1) && j < (y-1)) {
		if(*(*(grid+i+1)+j+1) == 'X') {
			count++; 
		}
	}

	//if i,j is out of bounds
	if(i > x || j > y || i < 0 || j < 0) {
		return -1; 
	}
	
	return count;
}