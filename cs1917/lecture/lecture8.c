#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
   char c;
   c = getchar();
   while(c != EOF){
   putchar(c);
   c = getchar();
   }
   return EXIT_SUCCESS;
}
