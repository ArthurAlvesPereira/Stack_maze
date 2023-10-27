#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    return stack;
}

void push(Stack *stack, int x, int y){
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = stack->top;
    stack->top = node;
}

void pop(Stack *stack){
    Node* node = stack->top;
    stack->top = node->next;
    free(node);
}

void* top(Stack *stack){
    return stack->top;
}

int isEmpty(Stack *stack){
    if (stack->top == NULL){
        return 1;
    } else {
        return 0;
    }
}

void killStack(Stack *stack){
    Node* node = stack->top;
    while (node != NULL){
        Node* temp = node->next;
        free(node);
        node = temp;
    }
    free(stack);
}
