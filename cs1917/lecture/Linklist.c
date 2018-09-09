#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Linklist.h"


struct _node {
	int item;
	struct _node * next;
};

struct _list {
	Node head;
	Node tail;
	int size;
};



Node createnode(int item){
	Node node = malloc(sizeof(struct _node));
	assert(node != NULL);
	node->item = item;
	node->next = NULL;
	return node;
}

List creatlist() {
	List list = malloc(sizeof(struct _list));
	assert(list != NULL);
	list ->head = NULL;
	list ->tail = NULL;
	list->size = 0;
	return list;
}



void Appendlist(List list, Node node){
	if(list->head == NULL){
		list->head = node;
	}else {
		list->tail->next = node;
	}
	list->tail = node;
	list->size = list->size + 1;
}

void Printlist(List list){
	Node curr = list->head;
	while(curr != NULL){
		printf("%d\n", curr->item);
		curr = curr->next;
	}
}

void freenode(Node node){
	free(node);
}

void freelist(List list){
	Node curr = list->head;
	Node nextnode = NULL;
	while(curr != NULL){
		nextnode = curr->next;
		freenode(curr);
		curr = nextnode;
	}
	free(list);
}

void Deletenode(List list, int item){
	if(list->size > 0){
		if(list->size == 1){
			if(list->head->item == item){
				freenode(list->head);
				list->head = NULL;
				list->tail = NULL;
				list->size = 0;
			}
		}else {
			Node curr = list->head;
			Node prev = NULL;
			while(curr->item != item && curr != NULL){
				prev = curr;
				curr = curr->next;
			}
			if(curr != NULL){
				if(curr == list->head){
					list->head = curr->next;
				}else if(curr == list->tail){
					prev->next = NULL;
				}else {
					prev->next = curr->next;
				}
				freenode(curr);
				list->size = list->size - 1;
				}
			}
	}


}

void printsize(List list){
	printf("the size of the list is %d\n", list->size);
}

/*int isBegin(List list, Node node){
	if(list->head == node){
		return TRUE;
	}
	return FALSE;
}

int isEnd(List list, Node node){
	if(list->tail == node){
		return TRUE;
	}
	return FALSE;
}

int isAdj(Node n1, Node n2){
	if(n1->next == n2 || n2 ->next == n1){
		return TRUE;
	}
	return FALSE;
}

void swapNodes(List list, int item1, int item2){
	Node curr1 = list->head;
	Node prev1 = NULL;
	while(curr1->item != item1){
		prev1 = curr1;
		curr1 = curr1->next;
	}

	

	Node curr2 = list->head;
	Node prev2 = NULL;
	while(curr2->item != item2){
		prev2 = curr2;
		curr2 = curr2->next;
	}

	assert(curr1 != NULL);
	assert(curr2 != NULL);
	assert(curr1 != curr2);
	Node next1 = curr1->next;
	Node next2 = curr2->next;

	if(!isBegin(list, curr1) && !isEnd(list, curr1) && !isBegin(list, curr2) && !isEnd(list, curr2) && !isAdj(curr1, curr2)){
		prev1->next = curr2;
		curr2->next = next1;

		prev2->next = curr1;
		curr1->next = next2;
	}else if(!isAdj(curr1, curr2)){

	}



}
*/
List reverselist(List list){
	List newlist = creatlist();
	if(list->size > 0){
		Node curr = list->head;
		Node rest = curr->next;
		Node prev = NULL;
		while(curr->next != NULL){
			curr->next = prev;
			prev = curr;
			curr = rest;
			rest = curr->next;
		}
		curr->next = prev;
		newlist->head = curr;
		Node temp = newlist->head;
		while(temp->next != NULL){
			newlist->size = newlist->size + 1;
			temp = temp->next;
		}
	}
	return newlist;
}