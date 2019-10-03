#include <stdio.h>
#include <stdlib.h>
#include "library.h"
void flipper(int i, int j, player current)
{
	if(board[i][j].type==current.type) //Check right k+1
	{
		int k=j;
		int l=i;
		if(board[l][k+1].type!=current.type && board[l][k+1].type!=NONE && board[l][k+1].type!=OPTION)
		{
			k++;
			while((board[l][k+1].type==current.type || board[l][k+1].type!=current.type && board[l][k+1].type!=NONE && board[l][k+1].type!=OPTION) && k<SIZE)
			{
				if(board[l][k+1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						k--;
					}
					break;
				}
				k++;
			}
		}
	}
	if(board[i][j].type==current.type) //Check down l+1
	{
		int k=j;
		int l=i;
		if(board[l+1][k].type!=current.type && board[l+1][k].type!=NONE && board[l+1][k].type!=OPTION)
		{
			l++;
			while((board[l+1][k].type==current.type ||board[l+1][k].type!=current.type && board[l+1][k].type!=NONE && board[l+1][k].type!=OPTION) && l<SIZE)
			{
				if(board[l+1][k].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l--;
					}
					break;
				}
				l++;
			}
		}
	}
	if(board[i][j].type==current.type) //Check left k-1
	{
		int k=j;
		int l=i;
		if(board[l][k-1].type!=current.type && board[l][k-1].type!=NONE  && board[l][k-1].type!=OPTION)
		{
			k--;
			while((board[l][k-1].type==current.type || board[l][k-1].type!=current.type && board[l][k-1].type!=NONE && board[l][k-1].type!=OPTION) && k<SIZE)
			{
				if(board[l][k-1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						k--;
					}
					break;
				}
				k++;
			}
		}
	}
	if(board[i][j].type==current.type) //Check up l-1
	{
		int k=j;
		int l=i;
		if(board[l-1][k].type!=current.type && board[l-1][k].type!=NONE && board[l-1][k].type!=OPTION)
		{
			l--;
			while((board[l-1][k].type==current.type || board[l-1][k].type!=current.type && board[l-1][k].type!=NONE && board[l-1][k].type!=OPTION) && l<SIZE)
			{
				if(board[l-1][k].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l++;
					}
					break;
				}
				l--;
			}
		}
	}
	//--------------------------------- UP DOWN LEFT RIGHT
	//----------------------------------------------------------------------------------
	//-----------------------------------UP LEFT - DOWN LEFT - UP RIGHT - DOWN RIGHT
	
	
	if(board[i][j].type==current.type) //Check UP LEFT l-1 k-1
	{
		int k=j;
		int l=i;
		if(board[l-1][k-1].type!=current.type && board[l-1][k-1].type!=NONE && board[l-1][k-1].type!=OPTION)
		{
			l--;
			k--;
			while((board[l-1][k-1].type==current.type || board[l-1][k-1].type!=current.type && board[l-1][k-1].type!=NONE && board[l-1][k-1].type!=OPTION) && (l<SIZE && k<SIZE))
			{
				if(board[l-1][k-1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l--;
						k--;
					}
					break;
				}
				l++;
				k++;
			}
		}
	}
	if(board[i][j].type==current.type) //Check UP RIGHT l-1 k+1
	{
		int k=j;
		int l=i;
		if(board[l-1][k+1].type!=current.type && board[l-1][k+1].type!=NONE && board[l-1][k+1].type!=OPTION)
		{
			l--;
			k++;
			while((board[l-1][k+1].type==current.type || board[l-1][k+1].type!=current.type && board[l-1][k+1].type!=NONE && board[l-1][k+1].type!=OPTION) && (l<SIZE && k<SIZE))
			{
				if(board[l-1][k+1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l--;
						k++;
					}
					break;
				}
				l++;
				k--;
			}
		}
	}
	if(board[i][j].type==current.type) //Check DOWN LEFT l+1 k-1
	{
		int k=j;
		int l=i;
		if(board[l+1][k-1].type!=current.type && board[l+1][k-1].type!=NONE && board[l+1][k-1].type!=OPTION)
		{
			l++;
			k--;
			while((board[l+1][k-1].type==current.type || board[l+1][k-1].type!=current.type && board[l+1][k-1].type!=NONE && board[l+1][k-1].type!=OPTION) && (l<SIZE && k<SIZE))
			{
				if(board[l+1][k-1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l++;
						k--;
					}
					break;
				}
				l--;
				k++;
			}
		}
	}
	if(board[i][j].type==current.type) //Check DOWN RIGHT l+1 k+1
	{
		int k=j;
		int l=i;
		if(board[l+1][k+1].type!=current.type && board[l+1][k+1].type!=NONE && board[l+1][k+1].type!=OPTION)
		{
			l++;
			k++;
			while((board[l+1][k+1].type==current.type || board[l+1][k+1].type!=current.type && board[l+1][k+1].type!=NONE && board[l+1][k+1].type!=OPTION) && (l<SIZE && k<SIZE))
			{
				if(board[l+1][k+1].type==current.type)
				{
					while(board[l][k].type!=current.type && board[l][k].type!=NONE && board[l][k].type!=OPTION)
					{
						board[l][k].type=current.type;
						l++;
						k++;
					}
					break;
				}
				l--;
				k--;
			}
		}
	}
}
	