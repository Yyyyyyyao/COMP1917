#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){



	return EXIT_SUCCESS;
}




int non_decreasing(int a[],int N){
	int check = 0;
	int i = 0;
	while(i < N){
		if(a[i] < a[i+1]){
			check = 1;
		}
		i++;
	}

	return check;

}