#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"


void initializePlayers() /* Initialises player properties */
{
  	printf("Player 1 please insert your name:\n");
	scanf("%s", player1.name);
    printf("\n");
	player1.type = BLACK; /* Assign colour to player 1 */
	
	printf("Player 2 please insert your name:\n");
	scanf("%s", player2.name);
    printf("\n");
	player2.type = WHITE; /* Assign colour to player 1 */
}

void initializeBoard() /* Initialises board */
{
    int i,j; 
    for(i=0; i< SIZE; i++)
    {
        for(j=0;j<SIZE; j++)
	    {
            if(i==3)
		    {
                if(j==3)
			    {
                    board[i][j].type = WHITE; /* Places starting piece */
			    }
                else
			    {
                    if(j==4)
				    {
                        board[i][j].type = BLACK; /* Places starting piece */
				    }
                    else
				    {
                        board[i][j].type = NONE;
                    }
                }
		    }
            else
		    {
                if(i==4)
			    {
                    if(j == 3)
				    {
                        board[i][j].type = BLACK; /* Places starting piece */
				    }
                    else
				    {
                        if(j == 4)
					    {
						    board[i][j].type = WHITE; /* Places starting piece */
					    }
                        else
					    {
                            board[i][j].type = NONE;                        
                        }
                    }
				}
                else
			    {
                    board[i][j].type = NONE;
			    }
            }
        board[i][j].pos.row = i;
        board[i][j].pos.col = j;
        }
    }
}
void printBoard() /* Prints board */
{
    int i,j;
    j = 0;

    printf("\n    ");
    for(i=0; i< SIZE; i++)
    {
        printf("%d   ",i+1);
    }
    for(i=0; i< SIZE; i++)
    {
        printf("\n%d | ", i+1);
        for(j=0;j<SIZE; j++)
        {
            switch(board[i][j].type)
            {
                case WHITE:
                    printf("1 | "); /* Assigns the character 1 on the board to white/player2 */
                    break;
                case BLACK:
                    printf("0 | "); /* Assigns the character 0 on the board to black/player1 */
                    break;
                case NONE:
                    printf("x | "); /* Assigns the character x on the board to empty spaces */
                    break;
				case OPTION:
					printf("/ | "); /* Assigns the character / to possible valid moves */
                default:
                    break;
            }
        }
    }

}
