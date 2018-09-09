#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsDigit(int ch);
int value(int ch);

int main(int argc, char *argv[]){
	printf("enter the number: \n");
	char ch;
	int check;
	int val;
	int count[10] = {0};
	while((ch = getchar()) != EOF){
		check = IsDigit(ch);
		if(check == 1){
			val = value(ch);
			count[val]++;
		}	
	}
	int i = 0;
	while(i < 10){
		printf("%d  %d\n", i, count[i]);
		i++;
	}


	return EXIT_SUCCESS;
}

int IsDigit(int ch){
	int check = 0;
	if(ch >= '0' && ch <= '9'){
		check = 1;
	}

	return check;
}

int value(int ch){
	int value;
	value = ch - '0';

	return value;
}

