CC = gcc
CFLAGS = -Wall -Wextra

all: meu_programa

meu_programa: main.o sorted_list.o
	$(CC) $(CFLAGS) -o meu_programa main.o sorted_list.o

main.o: main.c sorted_list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

sorted_list.o: sorted_list.c sorted_list.h
	$(CC) $(CFLAGS) -c -o sorted_list.o sorted_list.c

clean:
	rm -f meu_programa main.o list.o
