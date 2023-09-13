#Macros
CC = gcc
FLAGS = -Wall -g
all:getTokens
clean:
	rm -f getTokens *.o

getTokens: main.o getTokens.o getTokens.h
	$(CC) $<  getTokens.o -o $@

main.o: main.c getTokens.h
	$(CC) -c $< 

getTokens.o: getTokens.c getTokens.h
	$(CC) -c $< 