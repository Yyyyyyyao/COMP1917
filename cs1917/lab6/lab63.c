#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power_of_two(int k);

int main(int argc, char *argv[]){
	int check;
	int k;
	printf("enter a number : ");
	scanf("%d", &k);
	check = power_of_two(k);
	printf("return value is %d\n", check);
	return EXIT_SUCCESS;
}
int power_of_two(int k){
	int check;
	if(k % 2 == 0){
		check = 1;
	}else{
		check = 0;
	}
	

	return check;
}