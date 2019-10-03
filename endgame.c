#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void endgame() /* Prints the endgame status to console and to a file */
{
	int i,j; /* Indexes for board rows and columns */
	int c=0; /* Counter to keep track of pieces */
	int d=0; /* Counter to keep track of pieces */

	for(i=0;i<SIZE;i++) /* Runs through rows */
	{
		for(j=0;j<SIZE;j++) /* Runs through columns */
		{
			if(board[i][j].type==WHITE) /* If pieces for player 2 are found the counter is incremented */
			{
				c++;
			}
			else if(board[i][j].type== BLACK) /* If pieces for player 1 are found the counter is incremented */
			{
				d++;
			}
		}
	}
	printf("\nNumber of tiles for %s = %d\n",player1.name,d); /* Prints number of tiles at the end of the game for player 1 */
	printf("Number for tiles for %s = %d\n",player2.name,c); /* Prints number of tiles at the end of the game for player 2 */

	if(c>d) /* Prints endgame scenario if player 2 wins */
	{
		printf("\n%s wins\n",player2.name);
	}
	else if(d>c) /* Prints endgame scenario if player 1 wins */
	{
		printf("\n%s wins\n",player1.name);
	}
	else if(d==c) /* Prints endgame scenario if its a tie */
	{
		printf("\nTie\n");
	}
	
    /* The following code writes the endgame info to a text file */
	FILE *flPtr;  /* Pointer to text file */

	if((flPtr = fopen("endgame.txt","w")) == NULL)  /* If there is no file then it prints the error message */
	{
		printf("File could not be opened");
	}
	else
	{
		fprintf(flPtr,"Number of tiles for %s = %d\n",player1.name,d); /* Writes number of tiles at the end of the game for player 1 */
		fprintf(flPtr,"Number of tiles for %s = %d\n",player2.name,c); /* Writes number of tiles at the end of the game for player 2 */
		
		if(c>d) /* Writes endgame scenario if player 2 wins */
		{
			fprintf(flPtr,"%s wins\n",player2.name);
		}
		else if(d>c) /* Writes endgame scenario if player 1 wins */
		{
			fprintf(flPtr,"%s wins\n",player1.name);
		}
		else if(d==c) /* Writes endgame scenario if its a tie */
		{
			fprintf(flPtr,"Tie between %s and %s\n",player1.name,player2.name);
		}
		fclose(flPtr); /* Closes file */
	}

}
