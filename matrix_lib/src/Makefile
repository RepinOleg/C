.PHONY: all clean

CC=gcc
FLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)

GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_matrix

SRCS=$(wildcard *.c)
GCOVNAME=coverage
all: s21_matrix.a

$(LIBNAME).a:
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(LIBNAME).a *.o
	ranlib $(LIBNAME).a
	rm *.o
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main test
	
test: clean
	$(CC) $(SRCS) tests/*.c -o test $(LDFLAGS)
	./test

gcov_report: add_coverage_flag
	$(CC) $(SRCS) tests/*.c -o gcov_main $(LDFLAGS) $(GCOVFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
	

style_check:
	clang-format --style=Google -n $(SRCS)
	
style:
	clang-format --style=Google -i $(SRCS)

add_coverage_flag:
	$(eval FLAGS += --coverage)
