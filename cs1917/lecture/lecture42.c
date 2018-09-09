#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(int argc, char *argv[]){
	int min, max, guessnumber;
	printf("enter two number as a min and a max value: ");
	scanf("%d %d", &min, &max);
	srandom(time(NULL));
	int secretnumber = rand()%(max-min+1)+min;
	printf("guess a number: ");
	scanf("%d", &guessnumber);
	while(guessnumber != secretnumber){
	if(guessnumber > secretnumber){
	printf("lower\n");
	}else {
	printf("higher\n");
	}
	printf("try again:");
	scanf("%d", &guessnumber);
	}
	printf("you are right!\n");






	return EXIT_SUCCESS;
}
