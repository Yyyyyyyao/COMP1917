#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"
#include <ctype.h>

const char * const TYPES[] = {
   "Bug",
   "Dark",
   "Dragon",
   "Electric",
   "Fairy",
   "Fighting",
   "Fire",
   "Flying",
   "Ghost",
   "Grass",
   "Ground",
   "Ice",
   "Normal",
   "Poison",
   "Psychic",
   "Rock",
   "Steel",
   "Water"};

// ADD YOUR CODE HERE - any extra typedefs and #defines you'd like to use
#define NOTFOUND 0
#define FOUND 1
#define TRUE 1
#define FALSE 0
#define ENDOFSTRING '\0'
#define MAX_LENGTH 50 

struct _list {
   // ADD YOUR CODE HERE
    Pkmn head;
    Pkmn tail;
    Pkmn curr;
};

struct _pkmn {
   // ADD YOUR CODE HERE
    int id;
    int evolutionId;
    char *name;
    double height;
    double weight;
    int type1;
    int type2;
    int found;

    struct _pkmn * next;
};

// ADD YOUR CODE HERE - any extra structs you'd like to use
void Found(Pkmn curr);
void NotFound(Pkmn curr);
Pkmn getPkmn(PkmnList list, int id);
int checkByName(Pkmn temp, char text[]);

// ADD YOUR CODE HERE - any extra helper functions you'd like to use from within this file
void Found(Pkmn curr){
    //this is the function used in function printCurrentPkmn
    //this is one situation that the current Pokemon has been found
    //and then display the details
    printf("Id: %03d\n", curr->id);
    printf("Name: %s\n", curr->name);
    printf("Height: %.2lfm\n", curr->height);
    printf("Weight: %.2lfkg\n", curr->weight);
    if(curr->type1 < 0){
        printf("Type: %s\n", getTypeString(curr->type2));
    }else if(curr->type2 < 0){
        printf("Type: %s\n", getTypeString(curr->type1));
    }else if(curr->type1 < curr->type2){
        printf("Type: %s/%s\n", getTypeString(curr->type1), getTypeString(curr->type2));
    }else if(curr->type2 < curr->type1){
        printf("Type: %s/%s\n", getTypeString(curr->type2), getTypeString(curr->type1));
    }
}

void NotFound(Pkmn curr){
    //this is the function used in function printCurrentPkmn
    //this is one situation that the current Pokemon has not been found
    //and then display the details as "***" or "--".
    printf("Id: %03d\n", curr->id);
    printf("Name: ");
    int i = 0;
    while(curr->name[i] != ENDOFSTRING){
        printf("*");
        i++;
    }
    printf("\n");
    printf("Height: --\n");
    printf("Weight: --\n");
    printf("Type: --\n");
}

const char * getTypeString(int i) {
   return TYPES[i];
}

Pkmn getPkmn(PkmnList list, int id) {
    //this function is to find the Pokemin with a given id
    //and return it
    //this is used in the function showEvolutions
    //it is like the function jumpToPokemon.
    Pkmn temp = list->head;
    Pkmn target = NULL;
    while(temp != NULL){
        if(temp->id == id){
            target = temp;
        }
        temp = temp->next;
        
    }
    return target;
}

int checkByName(Pkmn temp, char text[]){
    //this is the function to help the function searchByName
    //if it is been found
    //it will return check as TRUE.
    int check = FALSE;
    int i = 0;
    int j = 0;
    while(temp->name[i] != ENDOFSTRING){
        if(toupper(temp->name[i]) == toupper(text[j])){
            i++;
            j++;
            if(text[j] == ENDOFSTRING){
                check = TRUE;
            }
        }else {
            i++;
            j = 0;
        }
    }


    return check;
}


Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
   // ADD YOUR CODE HERE
    Pkmn pkmn = malloc(sizeof(struct _pkmn));
    if(pkmn == NULL){
        printf("out of menmory.\n");
        exit(EXIT_FAILURE);
    }
    pkmn->name = malloc(sizeof(char)* MAX_LENGTH);
    sprintf(pkmn->name, "%s", name);
    pkmn->id = id;
    pkmn->evolutionId = NOTFOUND;
    pkmn->height = height;
    pkmn->weight = weight;
    pkmn->type1 = type1;
    pkmn->type2 = type2;
    pkmn->next = NULL;
    pkmn->found = NOTFOUND;

    return pkmn;
}

void printCurrentPkmn(PkmnList list) {
   // ADD YOUR CODE HERE
    if(list->curr != NULL){
        if(list->curr->found == FOUND){
            Found(list->curr);
        }else{
            NotFound(list->curr);
        }
    }else{
        printf("No Pokemon in list.\n");
    }
}


PkmnList createPkmnList() {
   // ADD YOUR CODE HERE
    PkmnList list = malloc(sizeof(struct _list));
    if(list == NULL){
        printf("out of menmory.\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->tail = NULL;
    list->curr = NULL;
    return list;
}

void freePkmnList(PkmnList list) {
   // ADD YOUR CODE HERE
    Pkmn curr = list->head;
    Pkmn rest = NULL;
    while(curr != NULL){
        rest = curr->next;
        free(curr->name);
        free(curr);
        curr = rest;
    }
    free(list);
}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
   // ADD YOUR CODE HERE
    if(list->head == NULL){
        list->head = pkmn;
        list->curr = list->head;
    }else{
        list->tail->next = pkmn;
    }
    list->tail = pkmn;
}

void printPkmnList(PkmnList list) {
   // ADD YOUR CODE HERE
    Pkmn temp = list->head;
    int i = 0;
    int j = 0;
    if(temp == NULL){
        printf("No Pokemon in list.\n");
    }else{
        while(temp != NULL){
        if(temp == list->curr){
            if(temp->found == FOUND){
                printf("--> #%03d: %s\n", temp->id, temp->name);
            }
            if(temp->found == NOTFOUND){
                printf("--> #%03d: ", temp->id);
                i = 0;
                while(temp->name[i] != ENDOFSTRING){
                    printf("*");
                    i++;
                }
                printf("\n");
            }
        }else{
            if(temp->found == FOUND){
                printf("    #%03d: %s\n", temp->id, temp->name);
            }
            if(temp->found == NOTFOUND){
                printf("    #%03d: ", temp->id);
                j = 0;
                while(temp->name[j] != ENDOFSTRING){
                    printf("*");
                    j++;
                }
                printf("\n");
            }
        }
        temp = temp->next;
        }
    }
}

void nextPkmn(PkmnList list) {
   // ADD YOUR CODE HERE
    if(list->curr == list->tail){
        list->curr = list->curr;
    }else{
        list->curr = list->curr->next;
    }
}

void prevPkmn(PkmnList list) {
   // ADD YOUR CODE HERE
    Pkmn prev = NULL;
    Pkmn temp = list->head;
    if(list->curr == list->head){
        list->curr = list->curr;
    }else{
        while(temp != list->curr){
            prev = temp;
            temp = temp->next;
        }
        list->curr = prev;
    }
}

void jumpToPkmn(PkmnList list, int id) {
   // ADD YOUR CODE HERE
    Pkmn temp = list->head;
    int check = FALSE;
    while(temp != NULL){
        if(temp->id == id){
            list->curr = temp;
            check = TRUE;
        }
        temp = temp->next;
        
    }
    if(check == TRUE){
        list->curr = list->curr;
    }
}

void removePkmn(PkmnList list) {
   // ADD YOUR CODE HERE

    Pkmn prev = list->head;
    if(list->curr == list->head){
        list->head = list->curr->next;
        free(list->curr->name);
        free(list->curr);
        list->curr = list->head;
    }else if(list->curr == list->tail){
        while(prev->next != list->tail){
            prev = prev->next;
        }
        list->tail = prev;
        free(list->curr->name);
        free(list->curr);
        list->curr = list->tail;
    }else{
        while(prev->next != list->curr){
            prev = prev->next;
        }
        prev->next = list->curr->next;
        free(list->curr->name);
        free(list->curr);
        list->curr = prev->next;
    }
}

// Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
   // ADD YOUR CODE HERE
    int count = 0;
    srand(seed);
    while(count < numberOfNewPkmn){
        int num = rand() % factor;
        Pkmn temp = list->head;
        while(temp != NULL){
            
            if(num == temp->id){
                temp->found = FOUND;
                count++;
            }
            temp = temp->next;
        }
    }
    
}

int totalFound(PkmnList list) {
   // ADD YOUR CODE HERE
    Pkmn temp = list->head;
    int totalNumOfFound = 0;
    while(temp != NULL){
        if(temp->found == FOUND){
            totalNumOfFound = totalNumOfFound + 1; 
        }
        temp = temp->next;
    }
   return totalNumOfFound;
}


// Stage 4 Functions

void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
   // ADD YOUR CODE HERE
    Pkmn pkmnWithEvol = NULL;
    Pkmn temp = list->head;
    int check = FALSE;
    while(temp != NULL){
        if(temp->id == pkmnId){
            pkmnWithEvol = temp;
            check = TRUE;
        }
        temp = temp->next;
    }
    if(check == TRUE){
        pkmnWithEvol->evolutionId = evolutionId;
    }
}






void showEvolutions(PkmnList list) {
   // ADD YOUR CODE HERE
    int previd = 0;
    Pkmn temp = list->curr;
    while(temp != NULL && temp->evolutionId != NOTFOUND){
        if(temp->found == FOUND){
            printf("#%03d %s --> ", temp->id, temp->name);
        }else if (temp->found == NOTFOUND){
            printf("#%03d ", temp->id);
            int i = 0;
            while(temp->name[i] != ENDOFSTRING){
            printf("*");
            i++;
            }
            printf(" --> ");
        }
        previd = temp->evolutionId;
        temp = getPkmn(list, temp->evolutionId);
    }
    if(temp != NULL){
        printf("#%03d %s\n", temp->id, temp->name);
    }else {
        printf("#%03d ?????\n", previd);
    }
}

// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
   // ADD YOUR CODE HERE
    PkmnList typelist = createPkmnList();
    Pkmn temp = list->head;
    Pkmn newnode = NULL;
    while(temp != NULL){
        if(temp->type1 == type || temp->type2 == type){
            newnode = createPkmn(temp->id, temp->name, temp->height, temp->weight, temp->type1, temp->type2);
            newnode->evolutionId = temp->evolutionId;
            newnode->found = temp->found;
            addPkmnToList(typelist, newnode);
        }
        temp = temp->next;
    }
   return typelist;
}

PkmnList getFoundPkmn(PkmnList list) {
   // ADD YOUR CODE HERE
    PkmnList foundlist = createPkmnList();
    Pkmn temp = list->head;
    Pkmn newnode = NULL;
    while(temp != NULL){
        if(temp->found == FOUND){
            newnode = createPkmn(temp->id, temp->name, temp->height, temp->weight, temp->type1, temp->type2);
            newnode->evolutionId = temp->evolutionId;
            newnode->found = temp->found;
            addPkmnToList(foundlist, newnode);
        }
        temp = temp->next;
    }
   return foundlist;
}



PkmnList searchByName(PkmnList list, char text[]) {
   // ADD YOUR CODE HERE
    PkmnList namelist = createPkmnList();
    Pkmn temp = list->head;
    Pkmn newnode = NULL;
    while(temp != NULL){
        if(checkByName(temp, text) == TRUE){
            newnode = createPkmn(temp->id, temp->name, temp->height, temp->weight, temp->type1, temp->type2);
            newnode->evolutionId = temp->evolutionId;
            newnode->found = temp->found;
            addPkmnToList(namelist, newnode);
        }
        temp = temp->next;
    }
   return namelist;
}

