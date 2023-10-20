.PHONY: all clean test gcov_report

CC=g++
LGFLAGS=-lgtest -pthread
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_matrix_oop

SRCS=s21_matrix_oop.cc
GCOVNAME=coverage

all: s21_matrix_oop.a

$(LIBNAME).a:
	$(CC) -c -std=c++17 $(SRCS)
	ar rc $(LIBNAME).a *.o
	ranlib $(LIBNAME).a
	rm *.o
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main test
	
test: clean
	$(CC) $(SRCS) tests/*.cc -o test $(LGFLAGS)
	./test

gcov_report: add_coverage_flag
	$(CC) $(SRCS) tests/*.cc -o gcov_main  $(GCOVFLAGS) $(LGFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info -no-external
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
	

style_check:
	clang-format --style=Google -n $(SRCS) tests/*.cc *.h
	
style:
	clang-format --style=Google -i $(SRCS)

add_coverage_flag:
	$(eval FLAGS += --coverage)
