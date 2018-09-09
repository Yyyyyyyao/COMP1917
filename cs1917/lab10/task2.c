#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){


	return EXIT_SUCCESS;

}


void insert_string(char s[],char t[],int k){
	int lenS = strlen(s);
	int lenT = strlen(t);
	char temp[lenS+lenT];
	int i = 0;
	int j = 0;
	if(k <= 0){
		while(i < (lenS+lenT)){
			if(i<lenT){
				temp[i] = t[i];
			}else{
				temp[i] = s[j]
				j++;
			}
			i++;
		}
		i = 0;
		while(i < lenS+lenT){
			s[i] = temp[i];
			i++;
		}
	}else if(k < lenS){
		int a = N;
		while(a < lenS){
			temp[i] = s[a];
			a++;
			i++;
		}
		a = N;
		while(j < lenT){
			s[a] = t[j];
			a++;
			j++;
		}
		j = 0;
		while(j < i){
			s[a] = temp[j];
		}
	}else{
		while(i < lenT){
			s[lenS] = t[i];
			i++;
			lenS++;
		}
	}




}