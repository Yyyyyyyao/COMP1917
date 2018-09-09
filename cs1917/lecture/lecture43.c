#include <stdio.h>
#include <stdlib.h>
int addnumber(int num1, int num2);
int main(int argc, char *argv[]){
	int a = 5;
	int b = 7;
	int c = 6;
	printf("a is %d, b is %d\n", a, b);
	int total = addnumber(a, b);
	total = addnumber(total, c);
	printf("total is %d\n", total);
	return EXIT_SUCCESS;
}
int addnumber(int num1, int num2){
	printf("num1 is %d, num2 is %d\n", num1, num2);
	int sum = num1+num2;
	return sum;
}
