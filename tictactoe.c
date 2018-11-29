
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
struct Move moves[MaxGrid*MaxGrid];
int replay_count = 0;
int gridlimit = 0;
/* Initialises the grid with a certain size, and prepares for a new game.
 *
 * Sets all the cells of the gridsize x gridsize portion of the grid to '.'.
 * Resets any other data used to represent the game to the beginning of a new game.
 *
 * Returns true if the input is invalid, and false otherwise.
 */
int init_grid(int gridsize) {
	gridlimit = gridsize; //assign global variable

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

int columns(char letter) {
	for(int i = 0; i < gridlimit; i++){
		//if theres three in a row
//		if((grid[0][i] == letter) && (grid[1][i] == letter) && (grid[2][i] == letter)){
			for(int j = 0; j < gridlimit; j++){
				//if letter is a match and it is last playable square
				if(grid[i][j] == letter && j+1 == gridlimit){
					return 1;
				}
				//else if grid does not equal letter
				else if(grid[i][j] != letter){
					break;
				}
//				else{
					//loop
				}
			}
			return 0;
		}

int rows(char letter) {
	//Loop through rows
	for(int i = 0; i <= gridlimit; i++){
			for(int j = 0; j <= gridlimit; j++){
				if(grid[j][i] == letter && j+1 == gridlimit){
					return 1;
				}
				//else if grid does not equal letter
				else if(grid[j][i] != letter){
					break;
				}
				else{
					//loop
				}
			}
		}
	}

int diagonal_lt(char letter) {
	//if theres three in a row
	if((grid[0][0] == letter) && (grid[1][1] == letter) && (grid[2][2] == letter)){
		// printf("theres three in a row...");
		//loop till end of grid
		for(int j = 2; j <= gridlimit; j++){
			// printf("last loop...");
			//if letter is a match and it is last playable square
			if(grid[j][j] == letter && j+1 == gridlimit){
				return 1;
			}
			//else if grid does not equal letter
			else if(grid[j][j] != letter){
				break;
			}
			else{
				//loop
			}
		}
	}
else {
	return 0;
	}
}

int diagonal_rt(char letter) {
	//if theres three in a row
	if((grid[0][gridlimit-1] == letter) && (grid[1][gridlimit-2] == letter) && (grid[2][gridlimit-3] == letter)){
		//loop till end of grid
		for(int j = 0; j <= gridlimit; ++j){
			//if letter is a match and it is last playable square
			if(grid[j][gridlimit-j-1] == letter && j+1 == gridlimit){
				return 1;
			}
			//else if grid does not equal letter
			else if(grid[j][gridlimit-j-1] != letter){
				break;
			}
			else{
				//loop
			}
		}
	}
else {
	return 0;
	}
}

int player_won(char letter) {

	if(columns(letter) == 1 || rows(letter) == 1 || diagonal_lt(letter) == 1 || diagonal_rt(letter) == 1){
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
	if(((x >= 0 && x < gridlimit) && (y >= 0 && y < gridlimit) && (grid[x][y] == '.'))){
		grid[x][y] = letter;
		moves[replay_count].x = x;
		moves[replay_count].y = y;
		moves[replay_count].player = letter;
		// printf("%i, %i, %c\n", moves[replay_count].x,moves[replay_count].y,moves[replay_count].player);
		return 0;
	}
	else{
		return 1;
	}
}


/* Returns the move performed at the "sequence_number"-th step during the current game, where the
 * first move is number 1 (not 0).
 *
 * If no such move exists (because sequence_number is not a valid move number in the
 * current game), the function returns an empty move.
 * An empty move is an object of struct Move that has both x and y set to -1.
 */
struct Move replay_move(int sequence_number) {
	// printf("SN: %i, SN-1: %i", sequence_number, sequence_number -1);
	return moves[sequence_number-1];
}

int prn_grid(int gridsize){
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

int grid_full(){
	for(int a = 0; a < gridlimit; a++){
		for(int b = 0; b < gridlimit; b++){
			if(grid[a][b] == '.'){
				return 0;
			}
			else{
				//pass
			}
		}
	}
	return 1;
}

//the main function of your program, renamed to compile the tests.
int mymain() {
	char end = 0;
	while(end == 0){
		int won = 0;
		int full = 0;
		char player = 'O';
		int x, y, v;
		do{
			printf("TicTacToe Grid Size (3 to 10): ");
			scanf("%i", &gridlimit);
			if((gridlimit < 3) || (gridlimit > MaxGrid)){
				printf("Input Invalid: Grid Limit Out of Range\n");
			}
		}while((gridlimit < 3) || (gridlimit > MaxGrid));

		init_grid(gridlimit);

		do{
			if(player == 'O'){
				player = 'X';
			}
			else{
				player = 'O';
			}

			prn_grid(gridlimit);


			do{
				printf("Player %c, Choose Location (x,y): ", player);
				scanf("%i,%i", &y, &x);

				if(make_move(x, y, player) == 1){
					v = 0;
					if(x > gridlimit-1 || y > gridlimit-1){
						printf("Input Invalid: Grid Location Out of Range\n");
					}
					else if (grid[x][y] != '.'){
						printf("Input Invalid: Space Taken\n");
					}
				}//if end
				else{
					v = 1;
				}
			}while(v != 1);
			replay_count++;
			printf("\nreplay_count: %i\n", replay_count);
			won = player_won(player);
			if(won == 1){
				prn_grid(gridlimit);
				printf("\n+--------------+\n| Player %c Won |\n+--------------+\n", player);
			}
			full = grid_full();
			if(full == 1){
				prn_grid(gridlimit);
				printf("\n+--------------+\n| No One Won :( |\n+--------------+\n", player);
			}
		}
		while(won == 0 && full == 0);
		printf("\nPress 0 to Continue and 1 to Exit: ");
		scanf("%i", &end);
		printf("\n");
	}
 return 0;
}
