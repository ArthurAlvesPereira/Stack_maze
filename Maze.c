#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Stack.h"
#include "Maze.h"


void* scanMaze(FILE* fp, void* stack){
    Stack* s = (Stack*)stack;
    int size;
    fscanf(fp, "%d", &size);
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->size = size;
    maze->maze = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++){
        maze->maze[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++){
            fscanf(fp, "%d", &maze->maze[i][j]);
            if (maze->maze[i][j] == 2){
                push(s, i, j);
            }
        }
    }

    return maze;
}

void printMaze(Maze* maze){
    
    for(int i = 0; i < maze->size; i++){
        for(int j = 0; j < maze->size; j++){
            if (maze->maze[i][j] == 0){ //Caminho
                printf("  ");
            } else if (maze->maze[i][j] == 1){ //Parede
                printf("# ");
            } else if (maze->maze[i][j] == 2){ //Inicial
                printf("I ");
            } else if (maze->maze[i][j] == 3){ //Final
                printf("F ");
            } else if (maze->maze[i][j] == 4){ //Caminha percorrido
                printf(". ");
            } else if (maze->maze[i][j] == 5){ //Quando acha um caminho errado e volta
                printf("x ");
            } else if (maze->maze[i][j] == 6){ //Quando achar o final
                printf("Y ");
            }
        }
        printf("\n");
    }
}

void solveMaze(Maze* maze, void* stack){
    if (isEmpty(stack)){
        printf("Não há solução para o labirinto\n");
        return;
    }
    printMaze(maze);
    usleep(250000);
    // IFs para verificar qual o SO e limpa o terminal
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    
    Stack* s = (Stack*)stack;
    Node* node = s->top;

    //Função que verifica se a proxima cordenada é o final

    if(maze->maze[node->x][node->y+1] == 3 || maze->maze[node->x+1][node->y] == 3 || maze->maze[node->x][node->y-1] == 3 || maze->maze[node->x-1][node->y] == 3){
        if (maze->maze[node->x][node->y+1] == 3){
            maze->maze[node->x][node->y+1] = 6;
            push(s, node->x, node->y+1);
            printMaze(maze);
            return;
        } else if (maze->maze[node->x+1][node->y] == 3){
            maze->maze[node->x+1][node->y] = 6;
            push(s, node->x+1, node->y);
            printMaze(maze);
            return;
        } else if (maze->maze[node->x][node->y-1] == 3){
            maze->maze[node->x][node->y-1] = 6;
            push(s, node->x, node->y-1);
            printMaze(maze);
            return;
        } else if (maze->maze[node->x-1][node->y] == 3){
            maze->maze[node->x-1][node->y] = 6;
            push(s, node->x-1, node->y);
            printMaze(maze);
            return;
        }
        
    }  else { 
        // Ifs que verificam se a proxima cordenada é um caminho e se for, empilha e marca como percorrido

        if(maze->maze[node->x][node->y + 1] == 0){ //direita
            push(s, node->x, node->y + 1);
            maze->maze[node->x][node->y + 1] = 4;
            solveMaze(maze, s);
        } else if(maze->maze[node->x + 1][node->y] == 0){ //baixo
            push(s, node->x + 1, node->y);
            maze->maze[node->x + 1][node->y] = 4;
            solveMaze(maze, s);
        } else if(maze->maze[node->x][node->y - 1] == 0){ //esquerda
            push(s, node->x, node->y - 1);
            maze->maze[node->x][node->y - 1] = 4;
            solveMaze(maze, s);
        } else if(maze->maze[node->x - 1][node->y] == 0){ //cima
            push(s, node->x - 1, node->y);
            maze->maze[node->x - 1][node->y] = 4;
            solveMaze(maze, s);
        } else if(maze->maze[node->x][node->y + 1] == 1 || maze->maze[node->x + 1][node->y] == 1 || maze->maze[node->x][node->y - 1] == 1 || maze->maze[node->x - 1][node->y] == 1) {
            maze->maze[node->x][node->y] = 5;
            pop(s);
            solveMaze(maze, s);
        }
    }
}

void killMaze(Maze* maze){
    for(int i = 0; i < maze->size; i++){
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}