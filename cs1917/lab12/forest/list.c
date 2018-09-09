#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static void delete_list(List l);

struct node{
  int val;
  Lnode next;  
};


struct list{
    Lnode head;
    int num_nodes;
};

Lnode new_node(int val){
    Lnode new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val){
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if(cur == NULL){
        l->head = new;
    }else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new;
        
    }
    l->num_nodes++;
}

void printList(List l){
    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL){
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void deleteList(List l){
    //TODO
    Lnode prev = NULL;
    if(l->head != NULL){
        if(l->head->next== NULL){
            free(l->head);
            free(l);
            return;
        }else{
            prev = l->head;
            l->head = l->head->next;
            delete_list(l);
            free(prev);
            free(l);
            return;
        }
    }else{
        free(l);
    }
}
    

static void delete_list(List l){
    Lnode prev = NULL;
    if(l->head->next == NULL){
            free(l->head);
            return;
        }else{
            prev = l->head;
            l->head = l->head->next;
            delete_list(l);
            free(prev);
            return;
        }
}