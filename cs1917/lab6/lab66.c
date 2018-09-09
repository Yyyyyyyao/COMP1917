#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printDiamond(int size);

int main(int argc, char *argv[]){
	int size = 0;
	printf("enter an number between 1 and 15: ");
	scanf("%d", &size);
	printDiamond(size);
 

	return EXIT_SUCCESS;
}

void printDiamond(int size){
	int i = 0;
	int num = (size - 1) / 2;
	int j = 0;
	int m = 0;
	int n = 0;
	while((num + i) < size){
		j = 0;
		while(j < size){
			if(j >= num - i && j <= num + i){
				printf("*");
			}else{
				printf(" ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
	m = num - 1;
	while(m >= 0){
		n = 0;
		while(n < size){
			if(n >= num - m && n <= num + m){
				printf("*");
			}else{
				printf(" ");
			}
			n++;
		}
		printf("\n");
		m--;
	}

	

 
}