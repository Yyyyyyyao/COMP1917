#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 200
#define TRUE 0
#define FALSE 1

int main(int argc, char *argv[]){
	char fname[100];
	int i = 0;
	while(i < 100){
		sprintf(fname, "area%d", i);
		FILE *file = fopen(fname, "r");
		int count = FALSE;
		char line[MAX_LENGTH];
		char *tru = "truffle";
		fgets(line, MAX_LENGTH, file);
		while(!feof(file)){
			if(*line == *tru && count == FALSE){// strstr()
				printf("%s\n", fname);
				count = TRUE;
			}
			fgets(line, MAX_LENGTH, file);
		}
		fclose(file);
		i++;
	}
	
	
	return EXIT_SUCCESS;
}
