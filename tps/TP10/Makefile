CC=gcc
CFLAGS=-std=gnu99 -g -fno-stack-protector -O0
SRC=$(wildcard *.c)
EXE=$(SRC:.c=)

all: $(EXE)
clean:
	rm -f $(EXE) *~
test: all
	./debugSimple
