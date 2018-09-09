#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]){
    int a = 0;
    int i = 0;
    printf("enter a number as n : \n");
    scanf("%d", &a);
    while(i <= a){
        if(i % 2 != 0){
            printf("%d\n", i);
        }
        i++;
    }


    return EXIT_SUCCESS;

}
