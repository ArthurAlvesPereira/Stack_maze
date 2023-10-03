#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void* initStack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack){
    if (stack->size == 0)
    {
        return 1;
    } else {
        return 0;
    }
}

void push(Stack* stack, void* data){
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->below = stack->top;

    stack->top = new;
    stack->size +=1;
}

void pop(Stack* stack){
    Node* aux = (Node*) malloc(sizeof(Node));

    aux = stack->top->below;
    free(stack->top);
    stack->top = aux;
    stack->size -= 1;
    free(aux);
}


