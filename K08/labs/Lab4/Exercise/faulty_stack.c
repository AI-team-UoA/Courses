#include <stdlib.h>
#include <limits.h>
#include "faulty_stack.h"

struct node{
    int data;
    Node *next;
};

struct stack{
    Node *list;
    int count;
};

//Function to create a new stack node
Node* create_stack_node(int data){
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

//Function to initialize a stack
// ERROR HERE - INITIALIZATION ERROR
Stack *stack_init(){
    Stack *s;
    s->list = NULL;
    s->count = 0;
    return s;
}

//Function to check if a stack is empty
int stack_empty(Stack *s){
    return s->count==0;
}

//Function to return the stack size
int stack_size(Stack *s){
    return s->count;
}

//Function to pop the top element of the stack and return it
//ERROR HERE - MEMORY LEAK
int stack_pop(Stack *s){

    //check if the stack is empty
    if(stack_empty(s))
        return INT_MIN;

    int result;
    if(s->count>1) {
        Node *cur = s->list;
        Node *prev = NULL;

        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }

        result = cur->data;
        prev->next = NULL;
    }
    else{
        result = s->list->data;
        free(s->list);
        s->list=NULL;
    }

    s->count--;
    return result;
}

//Function to return the value of the top element of the stack without removing it
//ERROR HERE - INVALID READ
int stack_peek(Stack *s){

    //check if the stack is empty
    if(stack_empty(s))
        return INT_MIN;

    Node *cur = s->list;

    while(cur->next!=NULL){
        cur = cur->next;
    }

    return cur->next->data;
}

//Function to insert a new element to a stack
//ERROR HERE - INVALID READ/WRITE
//TIP: the condition of the while loop
Stack* stack_push(Stack *s,int data){
    if(s->list==NULL){
        s->list = create_stack_node(data);
    }
    else{
        Node *node = create_stack_node(data);
        Node *cur = s->list;

        while(cur!=NULL){
            cur = cur->next;
        }

        //Append the last node
        cur->next = node;
    }

    s->count++;
    return s;
}

//Function to merge two stacks. The memory of the two stacks must be freed
//ERROR HERE - MEMORY LEAKS
Stack* stack_merge(Stack *s1,Stack *s2){
    Stack *newStack = stack_init();

    Node *cur = s1->list;
    while(cur!=NULL){
        newStack = stack_push(newStack,cur->data);
        cur = cur->next;
    }

    cur = s2->list;
    while(cur!=NULL){
        newStack = stack_push(newStack,cur->data);
        cur = cur->next;
    }

    return newStack;
}

//Function to destroy a stack
//ERROR HERE - MEMORY LEAKS
void stack_destroy(Stack *s){

    Node *cur = s->list;
    Node* next = NULL;

    free(s);
}