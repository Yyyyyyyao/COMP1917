#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (int argc, char *argv[]) {
	
	int i, b, k = 0;
	for(i=1; i<=5; i++){
		b =i %2;
		printf("%d\n", b);
		while((b--)>=0){
			k++;
		}  
	}
	
	
	printf("%d %d\n", k , b);

	return EXIT_SUCCESS;
}

