#ifndef _STACK_H
#define _STACK_H

typedef struct node
{
    void* data;
    struct node* below;  //trocar para below
} Node;

typedef struct stack
{
    int size;
    Node* top;
} Stack;

typedef void* Stackp;
void* initStack();

void push(Stack* stack, void* data);

#endif