#ifndef _MAZEREADER_H_
#define _MAZEREADER_H_

#include <stdio.h>

typedef struct maze {
    int size;
    int** mazeint;
    char** mazech;
} Maze;

FILE* openMaze();

void scanMaze(FILE* fp, Maze* maze);

void printMaze(Maze* maze);

void verifyMaze(Maze* maze);

void verifydirection(Maze* maze, int i, int j);


#endif // _MAZEREADER_H_