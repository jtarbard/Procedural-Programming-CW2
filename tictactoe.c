
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
int gridlimit = 0;
int iter = 0;//temp
/* Initialises the grid with a certain size, and prepares for a new game.
 *
 * Sets all the cells of the gridsize x gridsize portion of the grid to '.'.
 * Resets any other data used to represent the game to the beginning of a new game.
 *
 * Returns true if the input is invalid, and false otherwise.
 */
int init_grid(int gridsize) {
	// gridlimit = gridsize; //assign global variable

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

int player_won(char letter) {
	iter = 0;
	// printf("%i", iter);

	//HORIZONTAL
	//Loop through rows
	for(int i = 0; i <= gridlimit; i++){
		iter++;
		if((grid[i][0] == letter) && (grid[i][1] == letter) && (grid[i][2] == letter)){

			for(int j = 2; j <= gridlimit; j++){
				iter++;

				if(grid[i][j] == letter && j+1 == gridlimit){
					return 1;
				}
				//else if grid does not equal letter
				else if(grid[i][j] != letter){
					break;
				}
				else{
					//loop
				}
			}
		}
		else{
		}
	}

	//VERTICAL
	for(int i = 0; i <= gridlimit; i++){
		iter++;
		//if theres three in a row
		if((grid[0][i] == letter) && (grid[1][i] == letter) && (grid[2][i] == letter)){
			//loop till end of grid
			for(int j = 2; j <= gridlimit; j++){
				iter++;
				// printf("last loop...");
				//if letter is a match and it is last playable square
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
		else{
		}
	}

	//DIAGONAL
		//tl to br
		//if theres three in a row
		if((grid[0][0] == letter) && (grid[1][1] == letter) && (grid[2][2] == letter)){
			// printf("theres three in a row...");
			//loop till end of grid
			for(int j = 2; j <= gridlimit; j++){
				iter++;
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

		}
	//DIAGONAL
		//tr to bl
		//if theres three in a row
		if((grid[gridlimit-1][0] == letter) && (grid[gridlimit-2][1] == letter) && (grid[gridlimit-3][2] == letter)){
			// printf("theres three in a row...");
			// loop till end of grid
			for(int j = gridlimit-3; j >= 0; j++){
				// printf("%i,%i...", j, gridlimit-j-1);
				// printf("last loop...");
				//if letter is a match and it is last playable square
				if(grid[j][gridlimit-j-1] == letter && j-1 == 0){
					// printf("%i,D2:WINNER", gridlimit);
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
	else{
	}

	return 0;
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
		replay[replay_count].player = letter;
		replay[replay_count].x = x;
		replay[replay_count].y = y;

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
	return replay[sequence_number-1];
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

//the main function of your program, renamed to compile the tests.
int main() {
	int won = 0;
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

		won = player_won(player);
		if(won == 1){
			prn_grid(gridlimit);
			printf("\n+--------------+\n| Player %c Won |\n+--------------+\n\n", player);
		}
	}
	while(won == 0);
 return 0;
}
