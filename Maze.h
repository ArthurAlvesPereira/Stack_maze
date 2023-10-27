#ifndef _MAZE_H
#define _MAZE_H

typedef struct maze {
    int size;
    int** maze;
} Maze;

void* scanMaze(FILE* filename, void* stack); //Função que escaneia o labirinto e armazena em uma matriz e empilha a posição inicial
void printMaze(Maze* maze); //Função que escaneia o labirinto e imprime no terminal os caracteres em vez de numeros

void solveMaze(Maze* maze, void* stack); //Função prinicipal que resolve o labirinto

void killMaze(Maze* maze); //Função que da free na struct Maze

#endif 