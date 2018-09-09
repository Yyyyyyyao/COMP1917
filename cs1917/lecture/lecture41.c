#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(int argc, char *argv[]){
	srandom(time(NULL));
	int i = 0;
	while(i < 6){
	int num = rand()%6+1;
	printf("%d ", num);
	i++;
	}
	printf("\n");


	return EXIT_SUCCESS;
}
