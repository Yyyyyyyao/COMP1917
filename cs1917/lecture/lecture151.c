#include <stdio.h>
#include <stdlib.h>




void reverse(int a1[], int len);

int main(int argc, char *argv[]){

	int a1[] = {1,9,2,8,3,7};
	reverse(a1,6);
	

	return EXIT_SUCCESS;
}

void reverse(int a1[], int len){

	if(len <= 1){
		return;
	}else{
		int temp = a1[0];
		a1[0] = a1[len - 1];
		a1[len - 1] = temp;
		reverse(&a[1], len - 2);

	}


}
