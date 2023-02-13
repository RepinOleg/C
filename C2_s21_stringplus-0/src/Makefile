.PHONY: all clean

CC=gcc
FLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)

GCOVFLAGS=
LIBNAME=s21_string

SRCS=$(wildcard *.c)
GCOVNAME=coverage
# SRCS= s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strchr.c s21_strlen.c s21_strcpy.c s21_strncpy.c s21_strcmp.c s21_strncmp.c s21_strstr.c s21_strcat.c s21_strncat.c s21_strpbrk.c s21_strrchr.c s21_strcspn.c s21_strtok.c 
all: s21_string.a

$(LIBNAME).a:
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(SRCS)
	ar rc s21_string.a *.o
	ranlib s21_string.a
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main test

debug:
	$(CC) -g $(FLAGS) $(SRCS) -lm

test:
	$(CC) $(FLAGS) -g $(SRCS) tests/*.c -o test $(LDFLAGS)
	./test

test3:
	$(CC) $(FLAGS) $(LDFLAGS) $(SRCS) tests/*.c -o test
	./11test

gcov_report: add_coverage_flag
	$(CC) $(FLAGS) $(GCOVFLAGS) $(SRCS) tests/*.c -o gcov_main $(LDFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
	

test2: $(LIBNAME).a
	$(CC) $(FLAGS) $(LDFLAGS) -L. $(LIBNAME).a tests/*.c -o test2
	./test2

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report2: add_coverage_flag test2
	gcov -b -l -p -c s21_*.gcno
	lcov -o $(GCOVNAME).info -c -d .
	genhtml -o $(GCOVNAME) $(GCOVNAME).info
	open $(GCOVNAME)/index.html
	rm -rf *.gcda *.gcno *.gcov *.info
