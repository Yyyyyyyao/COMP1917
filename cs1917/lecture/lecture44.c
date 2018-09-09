#include <stdio.h>
#include <stdlib.h>
int changenumber(int num);
int main(int argc, char *argv[]){
	int num = 15;
	printf("in main: num is %d\n", num);
	num = changenumber(num);
	printf("int main, after calling change: num is %d\n", num);
	return EXIT_SUCCESS;
}
int changenumber(int num){
	printf("in change: num is %d\n", num);
	num = num+1;
	printf("in change: num is %d\n", num);
	return num;
}
