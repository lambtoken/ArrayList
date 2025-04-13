CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = main.c ArrayList.c

TARGET = program

all: main

main: main.c ArrayList.c ArrayList.h
	  $(CC) $(CFLAGS) -o $(TARGET) main.c ArrayList.c

clean: rm -f $(TARGET)