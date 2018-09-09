#include <stdio.h>

int main(int argc, char *argv[]){
	printf("Enter a number:");
	int num;
	scanf("%d", &num);
	int j = 0;
	while(j < num){
	 int i = 0;
	 while(i < num){

	 printf("x");
	 i = i+1;
	 }
	 printf("\n");
	j = j+1;
	}

	return 0;

}

