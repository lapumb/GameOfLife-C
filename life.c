#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//helper functions used within the file
void initialize_grid(int x, int y, char** grid); 
bool is_alive(int c);  

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y) {
	// an array size x, each each index points to an array size y
	// ex; x = 2, y = 3 (char)
	// x --> y y y
	// x --> y y y

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
	//initializing the grid to be all '-' 
	//initialize_grid(x, y, grid);

	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			//mutate(x, y, grid); 
			/*if(is_alive((*(*(grid+i)+j)))) {
				(*(*(grid+i)+j)) = '.';
			}
			else {
				(*(*(grid+i)+j)) = 'X';
			} */
			printf("%d ", (*(*(grid+i)+j)));
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
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			int numNeighbors = get_neighbors(i, j, x, y, grid); 
			if(numNeighbors < 2) {
				//dying
				*(*(grid+i)+j) = 0;
			}
			else if(numNeighbors > 2 && numNeighbors < 4) {
				//lives
				*(*(grid+i)+j) = 1;
			}
			else if(numNeighbors > 3) {
				//dying
				*(*(grid+i)+j) = 0;
			}
			else if(!is_alive(*(*(grid+i)+j)) && numNeighbors == 3) {
				//live
				*(*(grid+i)+j) = 1;
			}
		}
	}

	print_grid(x, y, grid);
	return grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has. i and j are the coords
 */
int get_neighbors(int i, int j, int x, int y, char** grid) {
	int count = 0; 
	int ul, u, ur, l, r, dl, d, dr; 
	
	//up/left
	if(i > 0 && j > 0 && i <= x && j <= y) { //making sure i and j are in bounds
		ul = *(*(grid+i-1)+j-1); 
		if(is_alive(ul)) {
			count++; 
		}
	}

	//up
	if(i > 0 && j >= 0 && i <= x && j <= y) {
		u = *(*(grid+i-1)+j); 
		if(is_alive(u)) {
			count++; 
		}
	}

	//up/right
	if(i > 0 && j >= 0 && i <= x && j < y) {
		ur = *(*(grid+i-1)+j+1); 
		if(is_alive(ur)) {
			count++; 
		}
	}

	//left
	if(i >= 0 && j > 0 && i <= x && j <= y) {
		l = *(*(grid+i)+j-1); 
		if(is_alive(l)) {
			count++; 
		}
	}

	//right
	if(i >= 0 && j >= 0 && i <= x && j < y) {
		r = *(*(grid+i)+j+1); 
		if(is_alive(r)) {
			count++; 
		}
	}

	//down/left
	if(i >= 0 && j > 0 && i < x && j <= y) {
		dl = *(*(grid+i+1)+j-1); 
		if(is_alive(dl)) {
			count++; 
		}
	}

	//down
	if(i >= 0 && j >= 0 && i < x && j <= y) {
		d = *(*(grid+i+1)+j); 
		if(is_alive(d)) {
			count++; 
		}
	}

	//down/right
	if(i >= 0 && j >= 0 && i < x && j < y) {
		dr = *(*(grid+i+1)+j+1); 
		if(is_alive(dr)) {
			count++; 
		}
	}

	//if i,j is out of bounds
	if(i > x || j > y || i < 0 || j < 0) {
		return -1; 
	}
	
	return count;
}


/*
* Helper function to initialize the grid to all '.'
* Only used within this file. 
*/
void initialize_grid(int x, int y, char** grid) {
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			*(*(grid+i)+j) = '.';
		}
	}
}

/*
* Helper function to see if the selected character is 'alive' or not. 
* Only used weithin this file. Improted bool. 
*/
bool is_alive(int c) {
	if(c == 1) {
		return true; 
	}

	return false; 
}