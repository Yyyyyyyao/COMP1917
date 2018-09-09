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

#define ENTER 10

void scanboard(int board[SIZE][SIZE]);
void printboard(int board[SIZE][SIZE]);
int getWinner(int board[SIZE][SIZE]);

int main(int argc, char *argv[])
{
   int board[SIZE][SIZE];
   printf("Please enter the board:\n");
   scanboard(board);
   printf("Here is the board:\n");
   printboard(board);
   int check;
   check = getWinner(board);
    if(check == CROSSES){
        printf("Crosses Win\n");

     }else if(check == NOUGHTS){
        printf("Noughts Win\n");
     }else{
        printf("No Winner\n");
     }
  
   return EXIT_SUCCESS;
}


void scanboard(int board[SIZE][SIZE]){
int i,j;
char ch;
j=0;
	for(i=0;i<SIZE;i++){
          j=0;
        while(j < SIZE){
	           ch = getchar();
	      if(ch == 10){
	         ch = EOF;
	      }
          if(ch>='0' && ch<=50){
		       board[i][j]=ch-48;
		       j++;
	      } 
        }
	}
}

void printboard(int board[SIZE][SIZE]){
    int row = 0;
    int col = 0;
    while(row < SIZE)
    {
        col = 0;
        while(col < SIZE)
        {
            if(board[row][col] == NOUGHTS)
                printf(" O");
            if(board[row][col] == CROSSES)
                printf(" X");
            if(board[row][col] == EMPTY)
            	printf(" .");
            col++;
        }
	row++;
        printf("\n");
    }
    return;
}

int getWinner(int board[SIZE][SIZE]){
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
        if(board[k][(SIZE - 1 - k)] == CROSSES){
            countc++;
        }else if(board[(k)][(SIZE - 1 - k)] == NOUGHTS){
            countn++;
        }
      k++;
    }

    if(countc == SIZE){
        crosses = TRUE;
      }else if(countn == SIZE){
        noughts = TRUE;
      }


    int check = 0;


     if(crosses == TRUE){
            check = CROSSES;

     }else if(noughts == TRUE){
            check = NOUGHTS;
     }else{
            check = NONE;
     }


   return check;



}
