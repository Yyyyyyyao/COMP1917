#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "list.h"


Lnode * makeNode( int data ){
  Lnode *new_node = (Lnode*)malloc(sizeof(Lnode));
  if( new_node == NULL ) {
    printf("Error: memory allocation failed\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return( new_node);
}


Lnode * append( Lnode *new_node, Lnode *head ){

  if( head == NULL ) {
    head = new_node;
  }
  else {
    Lnode *current = head;
    // find the tail of the list
    while( current->next != NULL ) {
      current = current->next;
    }
    current->next = new_node;
  }
  return( head );
}

void printList( Lnode *head ){

  Lnode *node = head;

  // traverse the list printing each node in turn
  while( node != NULL ) {
    printf("->%d", node->data );
    node = node->next;
  }
  printf("\n");
}

void freeList( Lnode *head ){

  Lnode *node = head;
  Lnode *tmp;

  while( node != NULL ) {
    tmp = node;
    node = node->next;
    free(tmp);
  }
}

Lnode *backToFront (Lnode * head){
  Lnode *front = head;
  Lnode *curr = head;
  Lnode *prev = NULL;
  while(curr->next != NULL){
        prev = curr;
        curr = curr->next;

  }
  curr->next = front;
  head = curr;
  prev->next = NULL;
  return head;

}

Lnode *removeDuplicates (Lnode *head){
    Lnode *curr = head;
    Lnode *check = curr->next;
    Lnode *prev = NULL;
    Lnode *rest = check->next;
    while(curr != NULL){
        check = curr->next;
        prev = curr;
        if(check != NULL){
        rest = check->next;
        while(check->next != NULL){
            if(curr->data == check->data){
                free(check);
                prev->next = rest;
                check = rest;
                rest = check->next;
            }else {
                prev = check;
                check = check->next;
                rest = check->next;
            }

        }
        if(check->data == curr->data){
            free(check);
            prev->next = NULL;
        }
        }
        curr = curr->next;
    }
    return head;
}