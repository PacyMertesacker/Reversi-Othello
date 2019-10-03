#include <stdio.h>
#include <stdlib.h>
#include "library.h"


int main()
{
	initializePlayers(); /* Initialises Player Name, Disk type and Pieces */
    initializeBoard(); /*Creates the Board using a 2D Array and fills it with empty spaces besides the center pieces*/
    
    int i,j;
	int playerTurn=-1;

	for(int i=0; i<SIZE; i++) /* Runs through rows */
	{
		for(int j=0; j<SIZE; j++) /* Runs through columns */
		{
			while(board[i][j].type==OPTION || board[i][j].type==NONE) /* While the game can be played */
			{
				
				if(playerTurn==-1)
				{
					printf("\n%s's turn - disk type: 0",player1.name); /* Player 1's move */
					validMoves(player1);
					printBoard();
					placePiece(player1);
					optionRemover();
				}
				else
				{
					printf("\n%s's turn - disk type: 1",player2.name); /* PLayer 2's move */
					validMoves(player2);
					printBoard();
					placePiece(player2);
					optionRemover();
				}
				 
				playerTurn= playerTurn*-1; /* Alternates turns */
				system("cls");
			}

			printBoard(); /* Prints all endgame data to console and file */
			endgame();
			return 0;
		}
	}
}
