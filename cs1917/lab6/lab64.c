#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float average(int n, int a[]);

int main(int argc, char *argv[]){
	float value;
	int n;
	int a[100];
	printf("enter n :");
	scanf("%d", &n);
	value = average(n, a);
	printf("%.2lf\n", value);
	return EXIT_SUCCESS;
}
float average(int n, int a[]){
	int i = 0;
	int j = 0;
	float  sum = 0;
	float value;
	printf("enter the number\n");
	while(i < n){
		scanf("%d", &a[i]);

		i++;
	}
	while(j < n){
		sum = sum + a[j];
		j++;
	}
	value = sum / n;
	return value;
}
