// Nome: Arthur Alves Pereira
// Matricula: 202000560261



#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Maze.h"

int main(){
    FILE* fp = fopen("labirinto.txt", "r");
    Stack* stack = (Stack*)createStack();
    Maze* maze = (Maze*)scanMaze(fp, stack);
    fclose(fp);
    solveMaze(maze, stack);
    printf("\n\n Labirinto resolvido \n\n");
    killStack(stack);
    return 0;
}