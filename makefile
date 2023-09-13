getTokens: main.o getTokens.c getTokens.h
	gcc -Wall -g main.o getTokens.o
main.o: main.c getTokens.h
	gcc -c main.c
getTokens.o: getTokens.c getTokens.h
	gcc -c getTokens.c