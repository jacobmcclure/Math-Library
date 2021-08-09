CFLAGS=-Wall -Wextra -Werror -Wpedantic -g
LDFLAGS=-lm
CC=clang $(CFLAGS)

all: math

math: math.o
	$(CC) -o math math.o $(LDFLAGS)
math.o: math.c
	$(CC) -c math.c
clean:
	rm -f math math.o
infer:
	make clean; infer-capture -- make; infer-analyze -- make
clang:
	clang-format -i -style=file *.c

