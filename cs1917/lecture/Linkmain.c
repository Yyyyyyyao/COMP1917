#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"


int main(int argc, char *argv[]){

	List l = creatlist();
	Appendlist(l, createnode(1));
	Appendlist(l, createnode(2));
	Appendlist(l, createnode(3));
	Appendlist(l, createnode(4));
	Appendlist(l, createnode(5));
	Printlist(l);
	printsize(l);
	l = reverselist(l);
	Printlist(l);
	return EXIT_SUCCESS;
}