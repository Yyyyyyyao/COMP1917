#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   char name[20+1];
   fgets(name, 20, stdin);
   int num = strlen(name);
   name[num-1] = '\0';

   printf("%s\n", name);





   return EXIT_SUCCESS;
}
