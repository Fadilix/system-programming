CC = gcc
CFLAGS = -Wall

result: main.o hashmap.o
	$(CC) $(CFLAGS) -o result main.o hashmap.o
main.o: main.c hashmap.h
	$(CC) $(CFLAGS) -c $<
hashmap.o: hashmap.c hashmap.h
	$(CC) $(CFLAGS) -c $<


