#include <stdio.h>
#include <stdlib.h>

void printStringR(char * string);
void printStringL(char * string);

int main(int argc, char * argv[]){
	
	printStringR("hello");
	printf("\n");



	return EXIT_SUCCESS;
}

void printStringL(char * string){
	while(*string != '\0'){
		printf("%c", string[0]);
		string = &string[1];
	}
	printf("\n");



}

void printStringR(char * string){
	if(string[0] == '\0'){
		return;
	}else {
		printStringR(&string[1]);
		printf("%c", string[0]);
		return;
	}
}

