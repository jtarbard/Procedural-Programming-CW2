
/* This is a template with the functions you must implement for this assignment.
 *
 * Note that you are free to implement any additional function you consider appropriate.
 *
 */
#include <stdio.h>

//the maximum size of the grid
#define MaxGrid 10

struct Move
{
	//the symbol played by the player
	char player;
	//the coordinates of the move
	int x,y;
};

int movjjj = 0;


char grid[MaxGrid][MaxGrid];
struct Move replay[MaxGrid*MaxGrid];
int move_count = 0;

/* Initialises the grid with a certain size, and prepares for a new game.
 *
 * Sets all the cells of the gridsize x gridsize portion of the grid to '.'.
 * Resets any other data used to represent the game to the beginning of a new game.
 *
 * Returns true if the input is invalid, and false otherwise.
 */
int init_grid(int gridsize) {
	if((gridsize >= 3) && (gridsize <= MaxGrid)){
		for(int r = 0; r < gridsize; ++r){
			for(int c = 0; c < gridsize; ++c){
				grid[r][c] = '.';
			}
		}
		return 0;
}
	else{
		return 1;
	}

	}
	//RESET ALL OTHER VALUES

/* Returns true if the player playing "letter" has formed a horizontal, vertical, or
 * diagonal line, and false otherwise.
 *
 * Note: this function can be implemented so that the total number of iterations of
 * all the loops in the function is exactly gridsize x gridsize.
 *
 * Any less efficient implementation will be marked down (as per the Structure
 * Clarity and *Efficiency* section of the marking scheme).
 *
 */
int player_won (char letter) {
		int count = 1;
		for(int i = 0; i <= MaxGrid; i++){
			if(grid[i][0] == letter){
				for(int e = 1; e <= MaxGrid; e++){
					if(grid[i][e] == letter){
						count++;
					}
					else{
						count = 1;
						break;
					}
				}
			}
		}
	//
	for (int i = 0; i <= MaxGrid; i++){
		if(grid[0][i] == letter){
			for(int e = 1; e <= MaxGrid; e++){
				if(grid[i][e] == letter){
					count++;
				}
				else{
					count = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i <= MaxGrid; i++){
		if(grid[i][i] == letter){
			for(int e = 1; e <= MaxGrid; e++){
				if(grid[e][e] == letter){
					count++;
				}
				else{
					count = 1;
					break;
				}
			}
		}
	}
		if(count >= movjjj){
			return 1;
		}
		else{
			return 0;
		}

}

/* Attempts to modify the grid at coordinates "x" and "y" by adding the move by the player
 * using character "letter".
 *
 * If the move is successful, it records the move so that it can be replayed afterwards.
 *
 * Returns true if it encountered an error and could not perform the move (because the
 * coordinates were out of range, or the position was already occupied), and false otherwise.
 */
int make_move(int x, int y, char letter) {
		if(grid[y][x] == '.'){
			grid[x][y] = letter;
			struct Move replay[x][y];
			replay[move_count]->player = letter;
			replay[move_count]->x = x;
			replay[move_count]->y = y;
			return 0;
		}
		else{
			return 1;
		}
	return 1;
}


/* Returns the move performed at the "sequence_number"-th step during the current game, where the
 * first move is number 1 (not 0).
 *
 * If no such move exists (because sequence_number is not a valid move number in the
 * current game), the function returns an empty move.
 * An empty move is an object of struct Move that has both x and y set to -1.
 */
struct Move replay_move(int sequence_number) {
	if((sequence_number > 0) && (sequence_number >= movjjj)){
		return replay[sequence_number-1];
	}
	else{
		struct Move empty;
		empty.x = -1;
		empty.y = -1;
		return empty;
	}

}

int prn_grid(int gridsize){

	movjjj = gridsize;
	for(int r = 0; r < gridsize; r++){
		for(int c = 0; c < gridsize; c++){
			printf(" %c ", grid[r][c]);
		}
		printf("\n");
	}
}

//the main function of your program, renamed to compile the tests.
int mymain() {

 return 0;
}
