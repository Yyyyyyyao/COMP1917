#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
	int num1, sum;
	int num2 =0;
	int i = 1;
	printf("Enter number: ");
	scanf("%d", &num1);
	printf("The factors of %d are:\n", num1);
	while(i <= num1){
	 if(num1%i == 0){
	 printf("%d\n", i);
	 num2 = i + num2;
	 }

	i = i + 1;
	}
	sum = num2 - num1;
	 printf("Sum of factors = %d\n", sum);
	if(sum == num1){
	printf("%d is a perfect number.\n", num1);
	} else {
	printf("%d is not a perfect number.\n", num1);
	}







	return EXIT_SUCCESS;
}
