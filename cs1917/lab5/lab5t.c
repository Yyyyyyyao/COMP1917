#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define SIZE 3

#define NONE -1
#define NOUGHTS 0
#define CROSSES 1
#define EMPTY 2

void scanboard(int board[SIZE][SIZE]);
void printboard(int board[SIZE][SIZE]);
void getWinner(int board[SIZE][SIZE]);

int main(int argc, char *argv[])
{
   int board[SIZE][SIZE];
   printf("Please enter the board:\n");
   scanboard(board);
    printf("Here is the board:\n");
   printboard(board);
   printf("che");
  getWinner(board);
   return EXIT_SUCCESS;
}
void scanboard(int board[SIZE][SIZE])
{
int i,j;
char ch;
j=0;
	for(i=0;i<SIZE;i++)
	{
		j=0;
		while((ch=getchar())!=10)
		{
			if(ch>=48 && ch<=50)
			{
				board[i][j]=ch-48;
				j++;
			}
		}
	}
	return;
}
void printboard(int board[SIZE][SIZE])
{
	int i,j;
	printf("Here is the board:\n");
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			if(board[i][j] == 2) printf(". ");
			if(board[i][j] == 1) printf("X ");
			if(board[i][j] == 0) printf("O "); 
		}
		printf("\n");
	}
	printf("\n");
}
/*void printboard(int aboard[SIZE][SIZE]){
    int row = 0;
    int col = 0;
    while(row < SIZE)
    {
	printf("row %d\n",row);
        col = 0;
        while(col < SIZE)
        {
            if(aboard[row][col] == NOUGHTS)
                printf("O ");
            if(aboard[row][col] == CROSSES)
                printf("X ");
            if(aboard[row][col] == EMPTY)
            	printf(". ");
            col++;
		printf("col %d\n",col);
        }
        printf("\n");
        row++;
    }
    printf("che");
    return;
}*/

void getWinner(int board[SIZE][SIZE]){
    int row = 0;
    int col = 0;
    int crosses = FALSE;
    int noughts = FALSE;  
    while(row < SIZE){
        int a = 0;
        int b = 0;
        col = 0;
        while(col < SIZE){
            if(board[col][row] == CROSSES){
               a++;
               col++;
            }else if(board[col][row] == NOUGHTS){
               b++;
               col++;
            }else{
               col++;
            }
        }
       if(a == SIZE){
          crosses = TRUE;
       }else if(b == SIZE){
          noughts = TRUE;
       }
        row++;
    }
    while(col < SIZE){
        int countC = 0;
        int countN = 0;
        row = 0;
        while(row < SIZE){
            if(board[col][row] == CROSSES){
               countC++;
               row++;
            }else if(board[col][row] == NOUGHTS){
               countN++;
               row++;
            }else{
               row++;
            }
        }
      if(countC == SIZE){
        crosses = TRUE;
      }else if(countN == SIZE){
        noughts = TRUE;
      }
     col++;
    }

    int CountC = 0;
    int CountN = 0;
    int countc = 0;
    int countn = 0;
    int i = 0;
    int k = 0;
    while(i < SIZE){
        if(board[i][i] == CROSSES){
            CountC++;
        }else if(board[i][i] == NOUGHTS){
            CountN++;
        }
      i++;
    }
    if(CountC == SIZE){
       crosses = TRUE;
    }else if(CountN == SIZE){
       noughts = TRUE;
    }
    while(k < SIZE){
        if(board[SIZE - 1 - k][SIZE-1 - k] == CROSSES){
            countc++;
        }else if(board[i][i] == NOUGHTS){
            countn++;
        }
      i++;
    }
    


    

    if(countc == SIZE){
        crosses = TRUE;
      }else if(countn == SIZE){
        noughts = TRUE;
      }





     if(crosses == TRUE){
        printf("Crosses Win");

     }else if(noughts == TRUE){
        printf("Noughts Win");
     }else{
        printf("No Winner");
     }



}
