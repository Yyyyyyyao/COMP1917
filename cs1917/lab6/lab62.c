#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    int a = 0;
    int i = 0;
    printf("enter a number as n: \n");
    scanf("%d", &a);
    while(a > 0){
        i = 0;
        while(i < a){
            printf("*");
            i++;
        }
        printf("\n");
        a--;
    }
    return EXIT_SUCCESS;
}
