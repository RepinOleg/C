.PHONY: all clean install uninstall dvi dist tests build gcov_report

CXX=g++
CXXFLAGS=-std=c++17 -Wall -g -Werror -Wextra
GCOVFLAGS=-fprofile-arcs -ftest-coverage
APP=build/SmartCalc.app
SRCS=$(wildcard controller/*.cc model/*.cc view/*.cc)
GCOVNAME=coverage
LDFLAGS =-lgtest -lgcov
TEST_SRCS=$(wildcard model/*.cc tests/*.cc)

all: install

install: clean build
	mkdir $(HOME)/Desktop/SmartCalc
	cp -rf $(APP) $(HOME)/Desktop/SmartCalc/
	make clean

uninstall:
	rm -rf $(HOME)/Desktop/SmartCalc

dvi:
	open SmartCalc.txt

dist:
	rm -rf SmartCalcArch/
	mkdir SmartCalcArch/
	cp -r Makefile controller model tests view SmartCalc.txt SmartCalcArch/
	tar cvzf SmartCalc.tgz SmartCalcArch/
	rm -rf SmartCalcArch/
	
	
tests: clean
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o test $(LDFLAGS)
	./test

gcov_report: add_coverage_flag
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o gcov_main  $(GCOVFLAGS) $(LDFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info -no-external
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

build:
	mkdir build
	cd ./build/ && qmake ../view/ && make
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.tgz gcov_main test build/ SmartCalcArch/

style_check:
	clang-format --style=Google -n $(SRCS) view/*.h model/*.h controller/*.h

add_coverage_flag:
	$(eval FLAGS += --coverage)