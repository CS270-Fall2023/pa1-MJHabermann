#Macros
CC = gcc
FLAGS = -Wall -g
all:getTokens
clean:
	rm -f getTokens *.o

getTokens: main.o getTokens.o getTokens.h
	$(CC) main.o getTokens.o

main.o: main.c getTokens.h
	$(CC) -c main.c

getTokens.o: getTokens.c getTokens.h
	$(CC) -c getTokens.c