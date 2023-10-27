#ifndef _STACK_H
#define _STACK_H

typedef struct node {
    int x, y;
    struct node *next;
} Node;

typedef struct stack {
    int size;
    Node *top;
} Stack;

void* createStack(); //Função que cria a pilha
void push(Stack *stack, int x, int y); //Função que empilha uma cordenada
void pop(Stack *stack); //Função que desempilha uma cordenada
void* top(Stack *stack); //Função que retorna o topo da pilha
int isEmpty(Stack *stack); //Função que verifica se a pilha está vazia

void killStack(Stack *stack); //Função que da free na pilha e seus nodes


#endif