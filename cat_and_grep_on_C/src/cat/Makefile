CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: s21_cat clean

s21_cat: s21_cat.o
	$(CC) s21_cat.o -o s21_cat

s21_cat.o: s21_cat.c s21_cat.h
	$(CC) $(CFLAGS) -c s21_cat.c

clean:
	rm -rf *.o