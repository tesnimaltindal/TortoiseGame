#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
//200030306
//TESNÝM ALTINDAL
int main()
{
	int n;
	int test=1;
	int energy=20;
	srand(time(NULL));
	printf("\t...WELCOME...\n \tTortoise Game");
	printf("\nPlease specify the size of the board: ");
	scanf("%d",&n);
	printf("Time:%d     ",test);
	test++;
	printf("Energy Level:%d\n",energy);
	energy--;

	
	char board[n][n];
	
	int mulberry=ceil(0.15*n*n);
	
	int pit=ceil(0.05*n*n);
	

	int mx;//mulberry x
	int my;//mulberry y;
	int tx;//tortoise x
	int ty ;//tortoise y
	int k;//pit loop
	int px;//pit x
	int py;//pit y
	int i;//tortoise loop
	int j;//mulberry loop
	int a ;//main loop row
	int b;//main loop column
	
	int c;//inside loop table
	int d;//inside loop table
	
	
	char action;//action 
	char direction;//direction 
	
	for(a=0;a<n;a++)//Table printed
					
	{
		for(b=0;b<n;b++)
		{
				board[a][b]='_';
		}
	}
	
	for(i=0;i<1;i++)//tortoise loop
	{
	tx=rand()%n;
	ty=rand()%n;
	
	board[tx][ty]='@';
	}
	
	for(j=0;j<mulberry;j++)//mulberry loop
	{
	mx=rand()%n;
	my=rand()%n;

   	if(board[mx][my]=='@')
	{
       j--;      //if mx=tx
	}
    else
	board[mx][my]='*';

	}
	
	for(k=0;k<pit;k++)//pit loop
	{
	px=rand()%n;
	py=rand()%n;

   	if((board[px][py]=='@')||(board[px][py]=='*'))
	{
       k--;        //if px=mx||px=tx
	}
    else
	board[px][py]='O';

	}
	
	
	for(c=0;c<n;c++)//Table printed
					
	{
		for(d=0;d<n;d++)
		{
			printf("%c ",board[c][d]);
			
		}
		printf("\n");
	}
	
	
	while((energy>0)&&(mulberry>0))  //main loop start
	{
	
	printf("Please enter an action:");
	scanf(" %c %c",&action,&direction);
	printf("\n");
	printf("==================================");
	printf("\n");
	printf("Time:%d     ",test);
	printf("Energy Level:%d\n",energy);
	
	if(action=='E')       //eat situations
	{
		if((direction=='S')&& board[tx+1][ty]=='*')
		{
			board[tx+1][ty]='_';
			energy+=10;
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
				}
		printf("\n");
			}
	
		}			
		if((direction=='N')&& board[tx-1][ty]=='*')
	{
			board[tx-1][ty]='_';
			energy+=10;
			
		for(c=0;c<n;c++)
		{
			for(d=0;d<n;d++)
			{
				printf("%c ",board[c][d]);
			}
		printf("\n");
		}
	}
		if((direction=='W')&& (board[tx][ty-1]=='*'))
	{
		
			board[tx][ty-1]='_';
			energy+=10;	
		
		for(c=0;c<n;c++)
		{
			for(d=0;d<n;d++)
			{
			printf("%c ",board[c][d]);
			
			}
		printf("\n");
		}
	}
		if((direction=='E')&& (board[tx][ty+1]=='*'))
			{
		
			board[tx][ty+1]='_';
			energy+=10;
		
		for(c=0;c<n;c++)
				{
			for(d=0;d<n;d++)
					{
						printf("%c ",board[c][d]);
					}		
		printf("\n");
				}
				
			}
			mulberry--;
			
				if(mulberry==0)//won cause of mulberry finish
				{
				
			printf("\n");
			printf("CONGRAGULATIONS, YOU WON :-)");
			return 0;
				}
				
		
		}//eat situations done
		
			if(action=='M')   //move situations start
	{
		if((direction=='S'))
		{
			if(board[tx+1][ty]=='_')
	{
			board[tx][ty]='_';
			board[tx+1][ty]='@';
			tx++;
			energy--;
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
				}
		printf("\n");
			}
	
	}
		else if(board[tx+1][ty]=='O')
		{
			board[tx][ty]='_';
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
				}
		printf("\n");
			}
			printf("\nYOU LOST :-( \n THE GAME IS OVER!\n");
			return 0;
		}
		
	}
		if((direction=='N'))
	{
		if(board[tx-1][ty]=='_')
		{
			board[tx][ty]='_';
			board[tx-1][ty]='@';
			tx--;
			energy--;
		for(c=0;c<n;c++)
		{
			for(d=0;d<n;d++)
			{
				printf("%c ",board[c][d]);
			
			}
		printf("\n");
		}
		}
		else if(board[tx-1][ty]=='O')
		{
			board[tx][ty]='_';
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
			
				}
		printf("\n");
			}
			printf("\nYOU LOST :-( \n THE GAME IS OVER!\n");
			return 0;
		}
		
	}
		if((direction=='W') )
	{
		if((board[tx][ty-1]=='_'))
		{
			
			board[tx][ty]='_';
			board[tx][ty-1]='@';
			ty--;
			energy--;
			
		for(c=0;c<n;c++)
		{
			for(d=0;d<n;d++)
			{
			printf("%c ",board[c][d]);
			}
		printf("\n");
		}
	}
	else if(board[tx][ty-1]=='O')
		{
			board[tx][ty]='_';
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
				}
		printf("\n");
			}
			printf("\nYOU LOST :-( \n THE GAME IS OVER!\n");
			return 0;
		}
	
	}
		if((direction=='E') )
			{
		if((board[tx][ty+1]=='_'))
		{
			
		
			board[tx][ty]='_';
			board[tx][ty+1]='@';
			ty++;
			energy--;
		for(c=0;c<n;c++)
				{
			for(d=0;d<n;d++)
					{
						printf("%c ",board[c][d]);
					}		
		printf("\n");
				}
				
			}
			else if(board[tx][ty+1]=='O')
		{
			board[tx][ty]='_';
			
		for(c=0;c<n;c++)
			{
			for(d=0;d<n;d++)
				{
					printf("%c ",board[c][d]);
				}
		printf("\n");
			}
			printf("\nYOU LOST :-( \n THE GAME IS OVER!\n");
			return 0;
		}

	}
		
}//move situations done

	test++;
	
	}//while energy>0&&mulberry>0
	
	if(energy<=0)//lost cause of energy
	printf("\nYOU LOST :-( \n THE GAME IS OVER!\n");

	return 0;
}	
	
	
