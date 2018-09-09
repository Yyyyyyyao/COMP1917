#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	int num;
	char s[20];
	strcpy(s, "1111hello");
	num = atoi(s);

	printf("%s     %d\n", s, num);

	return EXIT_SUCCESS;
}
