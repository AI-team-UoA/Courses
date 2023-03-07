#pragma once

typedef struct node Node;
typedef struct stack Stack;


Node* create_stack_node(int data);
Stack *stack_init();
int stack_empty(Stack *s);
int stack_size(Stack *s);
int stack_pop(Stack *s);
int stack_peek(Stack *s);
Stack* stack_push(Stack *s,int data);
Stack* stack_merge(Stack *s1,Stack *s2);
void stack_destroy(Stack *s);

