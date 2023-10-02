#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mazereader.h"

int main() {
    Maze* maze1 = (Maze*) malloc(sizeof(Maze));

    FILE* fp = openMaze();
    scanMaze(fp, maze1);
    printMaze(maze1);
    verifyMaze(maze1);
    fclose(fp);
    return 0;
}