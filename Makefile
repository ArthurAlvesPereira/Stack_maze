EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = maze

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): Main.c Maze.o Stack.o
	$(EXEC) $(CFLAGS) Main.c Maze.o Stack.o -o $(PROJECT_NAME) -lm

Maze.o: Maze.c Maze.h
	$(EXEC) $(CFLAGS) -c Maze.c

Stack.o: Stack.c Stack.h
	$(EXEC) $(CFLAGS) -c Stack.c