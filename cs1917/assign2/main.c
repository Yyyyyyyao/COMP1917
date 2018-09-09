#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"

#define MAX_LENGTH 50 

void printMenu();

int main(int argc, char * argv[]) {

   PkmnList list = createPkmnList();

   printMenu();
   char selection;
   scanf(" %c", &selection);
   while(selection != 'q') {
      if(selection == 'a') {
         int id, type1, type2;
         double height, weight;
         char *name = malloc(sizeof(char)*MAX_LENGTH);
         //the name here has to use malloc
         //otherwise, the name will be changed as the
         //last one you entered. 
         printf("Id: ");
         scanf("%d", &id);
         printf("Name: ");
         scanf("%s", name);
         printf("Height: ");
         scanf("%lf", &height);
         printf("Weight: ");
         scanf("%lf", &weight);
         printf("Type: ");
         scanf("%d", &type1);
         printf("Type: ");
         scanf("%d", &type2);

         Pkmn newPkmn = createPkmn(id, name, height, weight, type1, type2);
         addPkmnToList(list, newPkmn);
         free(name);
         
      } else if (selection == 'p') {
         
         printPkmnList(list);
      } else if (selection == 'd') {
         printCurrentPkmn(list);
      } else if (selection == '>') {
         nextPkmn(list);
      } else if (selection == '<') {
         prevPkmn(list);
      } else if (selection == 'j') {
         int id;
         printf("Id: ");
         scanf("%d", &id);
         jumpToPkmn(list, id);
      } else if (selection == 'r') {
         removePkmn(list);
      } else if (selection == 'f') {
         int seed, factor, numberOfNewPkmn;
         printf("Seed: ");
         scanf("%d", &seed);
         printf("Factor: ");
         scanf("%d", &factor);
         printf("Number to find: ");
         scanf("%d", &numberOfNewPkmn);
         findPkmn(seed, factor, numberOfNewPkmn, list);
      } else if (selection == 'c') {
         int totalnumber;
         totalnumber = totalFound(list);
         printf("%d Pokemon found.\n", totalnumber);
      } else if (selection == 'e') {
         int pkmnId, evolutionId;
         printf("Id of original Pokemon: ");
         scanf("%d", &pkmnId);
         printf("Id of evolution: ");
         scanf("%d", &evolutionId);
         addEvolution(list, pkmnId, evolutionId);
      } else if (selection == 's') {
         showEvolutions(list);
      } /*else if (selection == 'T') {

         int type;
         printf("Type:");
         scanf("%d", &type);
         PkmnList newlist1;
         newlist1 = getPkmnOfType(list, type);
         printPkmnList(newlist1);
         freePkmnList(newlist1);

      } else if (selection == 'F') {

          PkmnList newlist2;
          newlist2 = getFoundPkmn(list);
          printPkmnList(newlist2);
          freePkmnList(newlist2);

      } else if (selection == 'N') {

         PkmnList newlist3;
         char *text = malloc(sizeof(char)*MAX_LENGTH);
         printf("text: ");
         scanf("%s", text);
         newlist3 = searchByName(list, text);
         printPkmnList(newlist3);
         free(text);
         freePkmnList(newlist3);

      }*/


     printMenu();
     scanf(" %c", &selection);
      
   }

   freePkmnList(list);

   return EXIT_SUCCESS;
}

void printMenu() {
   printf("a - Add a Pokemon to the list\n");
   printf("p - Print list\n");
   printf("d - Display details of the current Pokemon\n");
   printf("> - Move to the next Pokemon\n");
   printf("< - Move to the previous Pokemon\n");
   printf("j - Jump to a specific Pokemon\n");
   printf("r - Remove the current Pokemon\n");
   printf("f - Find Pokemon\n");
   printf("c - Count the number of Pokemon which have been found\n");
   printf("e - Add an evolution to a Pokemon\n");
   printf("s - Show the evolutions of the current Pokemon\n");
   printf("q - Quit\n");
}
