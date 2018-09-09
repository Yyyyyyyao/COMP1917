#include <stdio.h>
#include <stdlib.h>

void copystring(char *dest, char *src);

int main(int argc, char *argv[]){
   char *original = "Hi my name is sim.         rmd";
   char copy[50];
   copystring(copy, original);
   printf("original is : %s\n", original);
   printf("copy: %s\n", copy);
   return EXIT_SUCCESS;
}

void copystring(char *dest, char *src){
   int i = 0;
   while(src[i] != '\0'){
     dest[i] = src[i];
   i++;
   }
   dest[i] = src[i];
}

