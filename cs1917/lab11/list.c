#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define TURE 0
#define FAIL 1

static int checkNode(Lnode curr, List newl);

struct node{
  int val;
  Lnode next;  
};


struct list{
    Lnode head;
    int num_nodes;
};

static int checkNode(Lnode curr, List newl){
    int check = TURE;
    Lnode curr2 = newl->head;
    while(curr2 != NULL){
        if(curr2->val == curr->val){
            check = FAIL;
        }          
        curr2 = curr2->next;
    }
    return check;
}

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


void destroy(List l){
    assert(l!= NULL);
    Lnode cur = l->head;
    Lnode prev = NULL;
    // free every single element of the list
    while(cur!= NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // free the list structure itself
    free(l);
}
int num_nodes(List l){
    return l->num_nodes;
}
//Given a linked list print it out in reverse
//Do not reverse original list
//Example:
//Given linked list [1]->[2]->[3]->X
//print_reverse output: [3]->[2]->[1]->X
void print_reverse(List l){
    List newl = newList();
    Lnode curr = l->head;
    if(curr != NULL){
    	while(curr != NULL){
    		append(newl, curr->val);
    		curr = curr->next;
    	} 
    	Lnode curr2 = newl->head;
    	Lnode rest = curr2->next;
    	Lnode prev = NULL;
        while(rest != NULL){
            curr2->next = prev;
            prev = curr2;
            curr2 = rest;
            rest = curr2->next;
        }
        curr2->next = prev;
        newl->head = curr2;
        printList(newl);
        destroy(newl);
    }
   
}
//Given a linked list create a new list containing only unique 
//elements of the current list. The order of the elements should remain 
// the same as in original linked list. Do not modify the original list.
//Example
//Input: 1->1->2->3->3->3->0->X
//Output:1->2->3->0->X
List extract_unique(List l){
	List newl = newList();
	Lnode curr = l->head;
    //Lnode curr2 = NULL;
    if(curr != NULL){
        while(curr != NULL){
            if(newl->head == NULL){
                append(newl, curr->val);
            }else{
            	int check = checkNode(curr, newl);
                /*curr2 = newl->head;
                check = 0;
                while(curr2 != NULL){
                    if(curr2->val == curr->val){
                        check = 1;
                    }
                    curr2 = curr2->next;
                }*/
                if(check == TURE){
                   append(newl, curr->val);
                }
            }
            curr = curr->next;
        } 
    }

    return newl;
}








