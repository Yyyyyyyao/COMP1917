#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include <assert.h>

void testEmpty(void);
void testOne(void);
void testManyPancakes(void);
void testTooManyPancakes(void);

int main(void) {

      
    testEmpty();
    testOne();
    testManyPancakes();
    testTooManyPancakes();	
    return 0;
}


void testEmpty(){
    printf("Testing empty stack\n");
    
    Stack s = NULL;
    s = createStack();
    assert(s != NULL);  
    
    printf("%d\n", numPancakes(s));
    assert(numPancakes(s) == 0);

    assert(totalSize(s) == 0);
    printf("%d\n",totalSize(s));

    eatPancake(s);
    
    printToppings(s);
    printf("\n");
    consumeStack(s);
}

void testOne(void){
    printf("Testing one pancake\n");
}

void testManyPancakes(void){
    printf("Testing a lot of blueberry pancakes\n");
}

void testTooManyPancakes(void){
    printf("Testing too many blueberry pancakes\n");
}







