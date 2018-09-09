#include <stdio.h>
int main(int argc, char * argv[]){

	int num1 = 0;
	int num2 = 0;
	char operation = 'a';
	printf("enter two numbers\n");
	scanf("%d %d", &num1, &num2);
	getchar();
	printf("please enter a, s, m , d\n");
	scanf("%c", &operation);
	printf("%d %c %d\n", num1, operation, num2);



	return 0;
}
