.PHONY: all clean

CC=gcc
FLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)

GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_decimal

SRCS=$(wildcard ant/s21_*.c arithmetic/s21_*.c cmp/s21_*.c cnv/s21_*.c common/s21_*.c)
GCOVNAME=coverage
all: s21_decimal.a

$(LIBNAME).a:
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(LIBNAME).a *.o
	ranlib $(LIBNAME).a
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main test
	
test: clean
	$(CC)  $(SRCS) tests/*.c -o test $(LDFLAGS)
	./test

gcov_report: add_coverage_flag
	$(CC) $(GCOVFLAGS) $(SRCS) tests/*.c -o gcov_main $(LDFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
	

style_check:
	clang-format --style=Google -n $(SRCS) tests/*.c *.h
	
style:
	clang-format --style=Google -i $(SRCS) tests/*.c *.h

add_coverage_flag:
	$(eval FLAGS += --coverage)
