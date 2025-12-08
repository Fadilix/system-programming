CC = gcc
CFLAGS = -Wall -g

ll: main.o linked_list.o
	$(CC) $(CFLAGS) -o ll main.o linked_list.o
main.o: main.c linked_list.h
	$(CC) $(CFLAGS) -c $*.c
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf *.o
go:
	./ll
