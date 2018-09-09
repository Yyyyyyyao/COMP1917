#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char s[]);
int main(int argc, char *argv[]){
	char word[100];
	printf("Enter string:\n");
	fgets(word, 100, stdin);
	word[strlen(word)-1] = '\0';
	int result = isPalindrome(word);
	if(result == 1){
		printf("Yes, is a palindrome.\n");
	}else if(result == 0){
		printf("No, not a palindrome.\n");
	}

	

	return EXIT_SUCCESS;
}

int isPalindrome(char s[]){
	int len = strlen(s);
	int check = 1;
	int i = 0;
	int j = len - 1;
	while(i < j){	
		if(isalpha(s[i]) != 0 && isalpha(s[j]) != 0){
			if(toupper(s[i]) != toupper(s[j])){
					check = 0;
			}
			i++;
			j--;

		}else if(isalpha(s[i]) == 0){
			i++;
		}else if(isalpha(s[j]) == 0){
			j--;
		}
	}
	return check;
}




