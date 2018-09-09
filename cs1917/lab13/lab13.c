#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LEN 128

void sanitize(char *s);

void shift_right(int array[], int n);

char * twentify(char s[]);

int main(int argc, char *argv[]){

	/*int array[10] = {1,2,3,4,5};
	shift_right(array, 5);
	int i = 0;
	while(i < 5){
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	*/
	
	char *s = "ccc aaaa rtgyd  vvvv";
	char *temp;
	sanitize(s);
	temp = twentify(s);
	int k = 0;
	while(k < strlen(temp)){
		printf("%c", temp[k]);
		k++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}

void shift_right(int array[], int n){

	int i = n - 1;
	int temp = array[n - 1];
	while(i > 0){

		array[i] = array[i - 1];
		i--;

	}
	array[0] = temp;
}

void sanitize(char *s){
	char *temp = malloc(sizeof(char)* strlen(s));
	int i = 0;
	int j = 0;
	while(i < strlen(s)){
		if(strlen(temp) == 0){
			temp[j] = s[i];
			j++;
			i++;
		} else {
			j = 0;
			int check = 0;
			while(j < strlen(temp)){
				if(temp[j] == s[i]){
					check = 1;
				}
				j++;
			}
			if(check == 0){
				temp[strlen(temp)] = s[i];
			}
			i++;
		}

	}
	int k = 0;
	while(k < strlen(temp)){
		printf("%c", temp[k]);
		k++;
	}
	printf("\n");
	free(temp);

}

char * twentify(char s[]){
	char *temp = malloc(sizeof(char) * strlen(s));
	int i = 0;
	int j = 0;
	while(i < strlen(s)){


		if(s[i] != ' '){
			temp[j] = s[i];
			j++;
		} else {
			temp[j] = '%';
			temp[j+1] = '2';
			temp[j+2] = '0';
			j = j + 3;
		}
		i++;
	}
	
	return temp;
}


