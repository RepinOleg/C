CC = gcc
SFLAGS = -Wall -Werror -Wextra -D_GNU_SOURCE -c

all: s21_grep clean

s21_grep: s21_grep.o
	$(CC) s21_grep.o -o s21_grep

grep.o: grep.c s21_grep.h
	$(CC) $(SFLAGS) grep.c

clean:
	rm -rf *.o