#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[]){

	Lnode *head = NULL;
	head = append(makeNode(1), head);
	head = append(makeNode(1), head);
	head = append(makeNode(2), head);
	head = append(makeNode(3), head);
	head = append(makeNode(3), head);
	head = append(makeNode(4), head);
	head = append(makeNode(4), head);
	head = append(makeNode(1), head);
	printList(head);
	head = backToFront(head);
	printList(head);
	head = removeDuplicates(head);
	printList(head);
	freeList(head);

	return EXIT_SUCCESS;
}
