#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128

char* reverse_string(char s[]);

int main(int argc, char *argv[]){
	char s[MAXLEN];
  	strcpy(s, "hello world");
  	printf("%s\n", s);


	return EXIT_SUCCESS;
}

