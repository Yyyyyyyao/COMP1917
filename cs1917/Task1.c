#include <stdio.h>
#include <math.h>
int main(int argc, char * argv[]) {

	int num = 0;
	scanf("%d", &num);
	double result = sqrt(num);
	printf("The square root is: %.3lf\n", result);
	return 0;

}
