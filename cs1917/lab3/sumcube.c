#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
	
	 
	  int k = 1;
	  int sum = 0;
	  while(k <= 15){
	  sum =sum + pow(k,3);
	  printf("%3d %5d\n", k, sum);

	  k = k+1;
	  }




	return EXIT_SUCCESS;
}
