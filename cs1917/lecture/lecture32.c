#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int num1, num2;
	char letter;
	printf("Enter two numbers:\n");
	scanf("%d %d", &num1, &num2);
	printf("Choose one letter to enter: a, s, m, d\n");
	getchar();
	scanf("%c", &letter);
	if(letter == 'a'){
	  int result;
	  result = num1 + num2;
	  printf("the result is %d\n", result);
	} else if(letter == 's'){
	  int result2;
	  result2 = num1 - num2;
	  printf("the result is %d\n", result2);
	} else if(letter == 'm'){
	  int result3;
	  result3 = num1 * num2;
	  printf("the result is %d\n", result3);
	} else if(letter == 'd'){
	  double result4;
	  result4 = num1 / num2;
	  printf("the result is %.3lf\n", result4);
	}



	return 0;
}
