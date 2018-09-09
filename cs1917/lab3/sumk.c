#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
	
	int k = 1;
	int sum = 0;
	while(k <= 15){
	 sum = sum + k;
	 printf("%3d %4d\n", k, sum);
	k = k+1;
	      }
	


	return EXIT_SUCCESS;
}
