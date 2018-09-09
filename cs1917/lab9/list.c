//list.c file that implements all functions declared in list.h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct _node {
    int value;
    Node next;
} node;
 

Node new_node(int value){
  Node newNode = malloc(sizeof(node));
  assert(newNode != NULL);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}


//frees everything malloced for the list
void destroy(Node head) {
   Node curNode = head;
   Node prevNode = NULL;

   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }

}

//appends a node of value to the end of the list
Node append(Node head, int value) {

   Node newNode = new_node(value);
   Node curNode = head;
   
   if ( curNode == NULL ) {
      head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
   return head;
}

void printList(Node head){
  Node cur = head;
    while(cur != NULL){
        printf("[%d]->",cur->value);
        cur = cur->next;
    }
    printf("X\n");
}

// returns the length of a linked list
int length(Node head){
  // TODO
	int num = 0;
	Node curr = head;
	while(curr != NULL){
		num++;
		curr = curr->next;
	}
  return num;
}

// Given a sorted list, insert a node into the list
// preserving sorted order
//given a list 0->1->2->5->7->X
//then sorted_insert(l, 4)
//now the list will be 0->1->2->4->5->7->X

Node sorted_insert(Node head, int val){
  //TODO
	Node curr = head;
	Node prev = NULL;
	Node new = new_node(val);
	if(head != NULL){
		 if(new->value < head->value){
	 		new->next = head;
			head = new;
		}else{
			while(new->value > curr->value && curr->next != NULL){
					prev = curr;
					curr = curr->next;
			}
			if(curr->next != NULL){
				prev->next = new;
				new->next = curr;
			}else{
				curr->next = new;
			}
		}
	}else{
		head = new;
	}	
  return head;
}

//inserts a node of value AT specified index
//	           0  1  2  3
//given a list 0->1->2->X
//then insertAt(l, 2, 9);
//                     0  1  2  3  4
//now the list will be 0->1->9->2->X
//if specified index is greater than the length of the list 
//append it to the end
Node insertAt(Node head, int index, int value){
  //TODO
	Node curr = head;
	Node prev = NULL;
	Node new = new_node(value);
	int i = 0;
	if(index == 0){
		new->next = head;
		head = new;
	}else if(index <=length(head)){
		while(i < index){
			prev = curr;
			curr = curr->next;
			i++;
		}
		prev->next = new;
		new->next = curr;
  	}else{
  		while(curr->next != NULL){
  			curr = curr->next;
  		}
  		curr->next = new;
  	}
  return head;
}

