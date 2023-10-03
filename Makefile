EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = Maze

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): main.c Mazereader.o Stack.o
	$(EXEC) $(CFLAGS) main.c Mazereader.o Stack.o -o $(PROJECT_NAME) -lm

Mazereader.o: Mazereader.c Mazereader.h
	$(EXEC) $(CFLAGS) -c Mazereader.c

Stack.o: Stack.c Stack.h
	$(EXEC) $(CFLAGS) -c Stack.c
