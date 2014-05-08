#Makefile for slug program
CC = gcc
CFLAGS = -g -O2
OBJECTS = main.o

slug: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o slug

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

