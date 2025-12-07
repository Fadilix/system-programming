CC = gcc
CFLAGS = -Wall -g

run: main.o stack.o
	$(CC) $(CFLAGS) -o run stack.o main.o
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c
go:
	./run
clean:
	rm -rf *.o run
