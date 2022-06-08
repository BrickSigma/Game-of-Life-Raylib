CC = gcc
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces
LIB = lib/
INCLUDE = include/
LINKERS = -lraylib -lopengl32 -lgdi32 -lwinmm #-mwindows

SRC = src/*.c
OUT = main

build:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) -I $(INCLUDE) -L $(LIB) $(LINKERS)