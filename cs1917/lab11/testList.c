#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void test_print_reverse(void);
void test_extract_unique(void);

void reverse_empty(void);
void reverse_one(void);
void reverse_mul(void);
void unique_empty(void);
void unique_full(void);
void unique_single(void);
void unique_onebyone(void);

int main(void){
    //call individual test functions
    test_print_reverse();
    test_extract_unique();

    return 0;
}


void test_print_reverse(void){
    reverse_empty();
    reverse_one();
    reverse_mul();
    //add any additional functions to test your implementation here
}

void reverse_empty(void){
    printf("Testing print_reverse with 0 element\n");
    List new = newList();
    assert(num_nodes(new) == 0);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");



}

void reverse_one(void){
    printf("Testing print_reverse with 1 element\n");
    List new = newList();
    append(new, 0);
    printf("Expected output:\n");
    printf("[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

void reverse_mul(void){
    printf("Testing print_reverse with multiple element\n");
    List new = newList();
    append(new, 0);
    append(new, 1);
    append(new, 2);
    append(new, 3);
    printf("Expected output:\n");
    printf("[3]->[2]->[1]->[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");


}

//##################################################################
void test_extract_unique(void){
    unique_empty();
    unique_full();
    unique_single();
    unique_onebyone();
    //add any additional functions to test your implementation here
}

void unique_empty(void){
    printf("Testing extract_unique with empty list\n");
    List new = newList();
    List u = extract_unique(new);
    assert(num_nodes(new) == 0);
    assert(num_nodes(u) == 0);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}

void unique_full(void){
    printf("Testing extract_unique with normal list\n");
    List new = newList();
    append(new, 0);
    append(new, 0);
    append(new, 3);
    append(new, 4);
    append(new, 4);
    append(new, 4);
    append(new, 6);
    append(new, 2);
    List u = extract_unique(new);
    printf("Expected output:\n");
    printf("[0]->[3]->[4]->[6]->[2]->X\n");
    printf("Your output:\n");
    printList(u);
    destroy(new);
    destroy(u);
    printf("=========================\n");
}

void unique_single(void){
    printf("Testing extract_unique with single list\n");
    List new = newList();
    append(new, 0);
    append(new, 6);
    append(new, 2);
    append(new, 4);
    append(new, 5);
    List u = extract_unique(new);
    printf("Expected output:\n");
    printf("[0]->[6]->[2]->[4]->[5]->X\n");
    printf("Your output:\n");
    printList(u);
    destroy(new);
    destroy(u);
    printf("=========================\n");
}

void unique_onebyone(void){
    printf("Testing extract_unique with special list\n");
    List new = newList();
    append(new, 0);
    append(new, 6);
    append(new, 0);
    append(new, 6);
    append(new, 5);
    append(new, 0);
    List u = extract_unique(new);
    printf("Expected output:\n");
    printf("[0]->[6]->[5]->X\n");
    printf("Your output:\n");
    printList(u);
    destroy(new);
    destroy(u);
    printf("=========================\n");
}
