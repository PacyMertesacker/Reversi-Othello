#include <stdio.h>
#include <stdlib.h>
#include "library.h"
void placePiece(player current)
{
	int i,j;
	printf("\nPlease enter x and y co-ordinate\n");
	scanf("%i %i",&i,&j);
	if(board[i-1][j-1].type!=OPTION)// (i<0 || i>8) || (j<0 || j>8) || board[i-1][j-1].type==BLACK || board[i-1][j-1].type==WHITE)
	{	
		printf("Error");
		placePiece(current);
	}
	else
	{
		board[i-1][j-1].type=current.type;
		flipper(i-1,j-1,current);
		printBoard();
	}	
}
void optionRemover()
{
	int i,j;
	for(i=0; i<SIZE; i++)
	{
		for(j=0; j<SIZE; j++)
		{
			if(board[i][j].type!=BLACK && board[i][j].type!=WHITE && board[i][j].type!=NONE)
			{
				board[i][j].type=NONE;
			}
		}
	}
}
void validMoves(player current)
{
	int i,j;
	
	for(i=0; i<SIZE; i++) //Check  right k+1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l][k+1].type!=current.type && board[l][k+1].type!=NONE && board[l][k+1].type!=OPTION)
				{
					while((board[l][k+1].type!=current.type && board[l][k+1].type!=NONE && board[l][k+1].type!=OPTION || board[l][k+1].type==NONE) && l<SIZE)
					{
						if(board[l][k+1].type==NONE)
						{
							board[l][k+1].type=OPTION;
							break;
							}
						k++;
					}
				}
			}
		}
	}
	for(i=0; i<SIZE; i++) //Check up l-1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l-1][k].type!=current.type && board[l-1][k].type!=NONE && board[l-1][k].type!=OPTION)
				{
					while((board[l][k+1].type!=current.type && board[l][k+1].type!=NONE && board[l-1][k].type!=OPTION || board[l-1][k].type==NONE) && l<SIZE)
					{
						if(board[l-1][k].type==NONE)
						{
							board[l-1][k].type=OPTION;
							break;
						}
						l--;
					}
				}
			}
		}
	}
	for(i=0; i<SIZE; i++) //Check  left k-1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l][k-1].type!=current.type && board[l][k-1].type!=NONE  && board[l][k-1].type!=OPTION)
				{
					while((board[l][k-1].type!=current.type && board[l][k-1].type!=NONE && board[l][k-1].type!=OPTION || board[l][k-1].type==NONE) && l<SIZE)
					{
						if(board[l][k-1].type==NONE)
						{
							board[l][k-1].type=OPTION;
							break;
						}
						k--;
					}
				}
			}
		}
	}
	for(i=0; i<SIZE; i++) //Check down l+1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l+1][k].type!=current.type && board[l+1][k].type!=NONE && board[l+1][k].type!=OPTION)
				{
					while((board[l+1][k].type!=current.type && board[l+1][k].type!=NONE && board[l+1][k].type!=OPTION || board[l+1][k].type==NONE) && l<SIZE)
					{
						if(board[l+1][k].type==NONE)
						{
							board[l+1][k].type=OPTION;
							break;
						}
						l++;
					}
				}
			}
		}
	}
	//UP DOWN LEFT RIGHT
	//--------------------------
	//UP-RIGHT UP-LEFT DOWN-RIGHT DOWN-LEFT
	
	for(i=0; i<SIZE; i++) //Check top left  l-1 k-1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l-1][k-1].type!=current.type && board[l-1][k-1].type!=NONE && board[l-1][k-1].type!=OPTION)
				{
					while((board[l-1][k-1].type!=current.type && board[l-1][k-1].type!=NONE && board[l-1][k-1].type!=OPTION || board[l-1][k-1].type==NONE) && l<SIZE)
					{
						if(board[l-1][k-1].type==NONE)
						{
							board[l-1][k-1].type=OPTION;
							break;
						}
						l--;
						k--;
					}
				}
			}
		}
	}
	for(i=0; i<SIZE; i++) //Check  top-right l-1 k+1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l-1][k+1].type!=current.type && board[l-1][k+1].type!=NONE && board[l-1][k+1].type!=OPTION)
				{
					while((board[l-1][k+1].type!=current.type && board[l-1][k+1].type!=NONE && board[l-1][k+1].type!=OPTION || board[l-1][k+1].type==NONE) && l<SIZE)
					{
						if(board[l-1][k+1].type==NONE)
						{
							board[l-1][k+1].type=OPTION;
							break;
						}
						l--;
						k++;
					}
				}
			}
		}
	}
	for(i=0; i<SIZE; i++) //Check  down-left l+1 k-1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l+1][k-1].type!=current.type && board[l+1][k-1].type!=NONE && board[l+1][k-1].type!=OPTION)
				{
					while((board[l+1][k-1].type!=current.type && board[l+1][k-1].type!=NONE && board[l+1][k-1].type!=OPTION || board[l+1][k-1].type==NONE) && l<SIZE)
					{
					if(board[l+1][k-1].type==NONE)
					{
						board[l+1][k-1].type=OPTION;
						break;
					}
						l++;
						k--;	
					}
				}
			}	
		}
	}
	for(i=0; i<SIZE; i++) //Check down-right l+1 k+1
	{
		for(j=0; j<SIZE; j++) //Checks all of the board
		{
			if(board[i][j].type==current.type)
			{
				int k=j;
				int l=i;
				if(board[l+1][k+1].type!=current.type && board[l+1][k+1].type!=NONE && board[l+1][k+1].type!=OPTION)
				{
					while((board[l+1][k+1].type!=current.type && board[l+1][k+1].type!=NONE && board[l+1][k+1].type!=OPTION || board[l+1][k+1].type==NONE) && l<SIZE)
					{
						if(board[l+1][k+1].type==NONE)
						{
							board[l+1][k+1].type=OPTION;
							break;
						}
						l++;
						k++;
					}
				}
			}
		}
	}	
}