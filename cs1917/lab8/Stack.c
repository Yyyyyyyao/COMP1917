#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct _stack {
    int numPancakes;
    Pancake array[MAX_PANCAKES];
};

Stack createStack(void) {
	Stack stack = malloc(sizeof(struct _stack));
    assert(stack != NULL);
	stack->numPancakes = 0;
	return stack;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
	// TO DO

	if(s->numPancakes < MAX_PANCAKES){
		s->array[s->numPancakes] = bake(topping, size);
		s->numPancakes++;
	}
}
// if stack is already empty, do nothing
void eatPancake(Stack s){
	// TO DO
	
	if(s->numPancakes > 0){
		eat(s->array[s->numPancakes-1]);
		s->numPancakes--;
	}
}

int numPancakes(Stack s) {
	// TO DO
	int a = 0;
	a = s->numPancakes;
	return a;
}

int totalSize(Stack s) {
	// TO DO
	
	int i = 0;
	int sum = 0;
	while(i < s->numPancakes){
		sum = sum + getSize(s->array[i]);
		i++;
	}
	return sum;
}

void printToppings(Stack s) {
	// TO DO
	int i = s->numPancakes-1;

	while(i>=0){
		printf("%s\n", getTopping(s->array[i]));
		i--;
	}
}


void consumeStack(Stack s) {
	// TO DO
	free(s);
}
