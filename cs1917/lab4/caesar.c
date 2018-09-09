#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int rotate_right( int ch);
int rotate_left( int ch);
int encode( int ch, int shift);
int main(int argc, char *argv[]){
	int shift, n;
	printf("Enter shift: ");
	scanf("%d", &shift);
	n = shift;
	printf("Enter Text:");
	char ch;
        ch = getchar();
	while(ch != EOF){
           ch = encode(ch, n);
	
	   putchar(ch);
           ch = getchar();
	}
	
	return EXIT_SUCCESS;
}

int encode( int ch, int shift){
	int i = 0;
	int k = 0;	
	if(shift > 0){
	     while(i < shift){
	         ch = rotate_right( ch);
	         i++;
	     }	  
	}else if(shift < 0){
	  while(k > shift){
	      ch = rotate_left( ch);
	      k--;
	  }
	}

	return ch;
}






int rotate_right( int ch){
	
	    if(ch >= 'A' && ch < 'Z'){
	        ch = ch + 1;
	    }else if (ch == 'Z') {
            ch = 'A';
	    }
	
	    if(ch >= 'a' && ch < 'z'){
	        ch = ch + 1;
	    }else if(ch == 'z'){
	        ch = 'a';
	    }
	
	char c = (char)ch;
	return c;
}

int rotate_left( int ch){
	
	    if(ch > 'A' && ch <= 'Z' ){
	        ch = ch - 1;
	    }else if (ch == 'A'){
	        ch = 'Z';
	    }
	
	    if(ch > 'a' && ch <= 'z'){
	       ch = ch - 1;
	    }else if (ch == 'a'){
	       ch = 'z';
	    }
	
	char c = (char)ch;
	return c;
}
