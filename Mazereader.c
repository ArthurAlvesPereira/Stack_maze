#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazereader.h"
#include "Stack.h"

FILE* openMaze(){
    FILE* fp = fopen("labirinto.txt", "r");
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;

}

void scanMaze(FILE* fp, Maze* maze1, void* stack){
    int size;
    
    Stack* s = (Stack*) stack;

    fscanf(fp, "%d", &size);
    maze1->size = size;

    maze1->mazeint = malloc(sizeof(int*) * maze1->size);
    for (int i = 0; i < maze1->size; i++) {

        maze1->mazeint[i] =malloc(sizeof(int) * maze1->size);
    }

    for (int i = 0; i < maze1->size; i++) {
        for (int j = 0; j < maze1->size; j++) {
            fscanf(fp, "%d", &maze1->mazeint[i][j]);
            // printf("%d", maze1->mazeint[i][j]);
        }
        // printf("\n");
    }

    push(s, maze1);

}

void printMaze(Maze* maze1){
    char Maze[maze1->size][maze1->size];

    for (int i = 0; i < maze1->size; i++){
        for (int j = 0; j < maze1->size; j++){
            if (maze1->mazeint[i][j] == 0) {
                Maze[i][j] = ' ';
            } else if (maze1->mazeint[i][j] == 1) {
                Maze[i][j] = '#';
            } else if (maze1->mazeint[i][j] == 2) {
                Maze[i][j] = 'o';
            } else if (maze1->mazeint[i][j] == 3) {
                Maze[i][j] = '@';
            }
        }
    }
    
    for (int i = 0; i < maze1->size; i++) {
        for (int j = 0; j < maze1->size; j++) {
            printf("%c ", Maze[i][j]);
        }
        printf("\n");
    }
}

void verifyMaze(Stack* stack){
    Stack *s = (Stack*) stack;
    for (int i = 0; i < stack->top->data->size; i++){
        for (int j = 0;j < s->top->data->size; j++){
            if (s->top->data->mazeint[i][j] == 2){  //Entra em estado de verifição de qual direção esta livre
                // verifydirection(maze1, i, j);
                printf("Ponto inicial encontrado");
            }

        }
    }
}

void verifydirection(Maze* maze1, int i, int j){
    maze1->mazeint[i][j] = 4;
    if (maze1->mazeint[i-1][j] == 0){
        verifydirection(maze1, i-1, j);
    } else if (maze1->mazeint[i][j+1] == 0){
        verifydirection(maze1, i, j+1);
    } else if (maze1->mazeint[i+1][j] == 0){
        verifydirection(maze1, i+1, j);
    } else if (maze1->mazeint[i][j-1] == 0){
        verifydirection(maze1, i, j-1);
    } else {
        if (maze1->mazeint[i-1][j] == 3){
        printf("Fim do labirinto encontrado no ponto %d %d", i-1, j);
    } else if (maze1->mazeint[i][j+1] == 3){
        printf("Fim do labirinto encontrado no ponto %d %d", i, j+1);
    } else if (maze1->mazeint[i+1][j] == 3){
        printf("Fim do labirinto encontrado no ponto %d %d", i+1, j);
    } else if (maze1->mazeint[i][j-1] == 3){
        printf("Fim do labirinto encontrado no ponto %d %d", i, j-1);
    } 
}
}