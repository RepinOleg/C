.PHONY: all clean install uninstall dvi dist test build gcov_report

CC=gcc
FLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)

GCOVFLAGS=-fprofile-arcs -ftest-coverage
APP=build/SmartCalc.app
SRCS=$(wildcard *.c)
GCOVNAME=coverage

all: install

install: clean build
	mkdir $(HOME)/Desktop/SmartCalc
	cp -rf $(APP) $(HOME)/Desktop/SmartCalc/
	make clean

uninstall:
	rm -rf $(HOME)/Desktop/SmartCalc

dvi:
	open ./SmartCalc.texi

dist:
	rm -rf SmartCalcArch/
	mkdir SmartCalcArch/
	cp Makefile *.c *.h *.ui *.cpp *.texi *.pro *.user SmartCalcArch/
	tar cvzf SmartCalc.tgz SmartCalcArch/
	rm -rf SmartCalcArch/
	
	
test: clean
	$(CC) $(LDFLAGS) $(SRCS) tests/*.c -o test 
	./test

gcov_report: add_coverage_flag
	$(CC) $(LDFLAGS) $(SRCS) tests/*.c -o gcov_main  $(GCOVFLAGS) 
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

build:
	mkdir build
	cd ./build/ && qmake ../ && make && mv smart_calc SmartCalc.app
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg  gcov_main test build/ SmartCalcArch/

style_check:
	clang-format --style=Google -n *.c *.cpp *.h tests/*.c *.h
	
style:
	clang-format --style=Google -i *.cpp *.c *.h tests/*.c *.h

add_coverage_flag:
	$(eval FLAGS += --coverage)