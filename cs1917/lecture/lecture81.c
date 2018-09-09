#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   int array[10];
   int i = 0;
   while(i < 10){
   scanf("%d", &array[i]);
   i++;
   }
   i = 0;
   while(i < 10){
   printf("%d is %d\n", i, array[i]);
   i++;
   }
   printf("\n");
   return EXIT_SUCCESS;
}

