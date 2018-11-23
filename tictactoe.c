
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

char grid[MaxGrid][MaxGrid];
struct Move replay[MaxGrid*MaxGrid];
int replay_count = 0;
int gl_gridsize = 0;

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
	for(int i = 0; i >= MaxGrid; i++){
		if((grid[i][0] == letter) && (grid[i][1] == letter) && (grid[i][2] == letter)){
			while(grid[i][0] != letter){}
		}
		else{

		}
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
	if((x >= 0 && x >= gl_gridsize) && (y >= 0 && y >= gl_gridsize)){

	}
	if(grid[y][x] == '.'){
		grid[x][y] = letter;
		replay[replay_count].player = letter;
		replay[replay_count].x = x;
		replay[replay_count].y = y;

		replay_count++;
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
	return replay[sequence_number-1];
}

int prn_grid(int gridsize){
	gl_gridsize = gridsize;
	for(int i = -1; i < gridsize; i++){
		if(i == -1){
			printf("  ");
		}
		else if(i == gridsize - 1){
			printf("%i ", i);
			printf("\n");
		}
		else{
			printf("%i ", i);
		}

	}
	for(int r = 0; r < gridsize; r++){
		printf("%i ", r);
		for(int c = 0; c < gridsize; c++){
			printf("%c ", grid[r][c]);
		}
		printf("\n");
	}
}

//the main function of your program, renamed to compile the tests.
int main() {
	//REMOVE
	int size = 3;
	int x,y;
	// scanf("%i", &size);
	init_grid(size);
	prn_grid(size);
	// scanf("%i,%i", &x, &y);
	make_move(0,0,'X');
	prn_grid(size);
	replay_move(1);
	make_move(0,1, 'X');
	make_move(0,2, 'X');
	prn_grid(size);
	player_won('X');
	//REMOVE
 return 0;
}
