#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazereader.h"
#include "Stack.h"

int main() {
    Maze* maze1 = (Maze*) malloc(sizeof(Maze));
    Stack* stack;
    FILE* fp = openMaze();
    stack = initStack();
    scanMaze(fp, maze1, stack);
    printMaze(maze1);
    verifyMaze(stack);
    fclose(fp);
    return 0;
}