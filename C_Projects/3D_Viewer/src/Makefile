.PHONY: all clean install uninstall dvi dist test build gcov_report

CC=gcc
FLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)

GCOVFLAGS=-fprofile-arcs -ftest-coverage
APP=Build/s21_3DViewer.app
SRCS=$(wildcard s21_3DViewer/AffineTransform/*.c s21_3DViewer/DynamicBuffer/*.c s21_3DViewer/OBJLoader/*.c)
STYLE=$(wildcard s21_3DViewer/*.cpp s21_3DViewer/*.h s21_3DViewer/MainWindow/*.cpp s21_3DViewer/ModelViewerWidget/*.cpp s21_3DViewer/OBJLoader/*.h s21_3DViewer/Headers/*.h s21_3DViewer/*.h Tests/*.c Tests/*.h)
DOCS_DIR=Docs
DOXY=doxygen

GCOVNAME=coverage

all: install

install: clean build
	mkdir $(HOME)/Desktop/3D_Viewer
	cp -rf $(APP) $(HOME)/Desktop/3D_Viewer/
	make clean

uninstall:
	rm -rf $(HOME)/Desktop/3D_Viewer

dvi:
	cd $(DOCS_DIR)/ && $(DOXY) && open Doxyoutput/html/index.html

dist:
	rm -rf 3D_ViewerArch/
	mkdir 3D_ViewerArch/
	cp -r Makefile s21_3DViewer/ 3D_ViewerArch/
	tar cvzf 3D_Viewer.tgz 3D_ViewerArch/
	rm -rf 3D_ViewerArch/
	
	
test: clean
	$(CC) $(SRCS) Tests/*.c -o test $(LDFLAGS)
	./test

gcov_report: add_coverage_flag
	$(CC) $(SRCS) Tests/*.c -o gcov_main  $(GCOVFLAGS) $(LDFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

build:
	cd ./Build/ && qmake ../s21_3DViewer/ && make && mv s21_3DViewer s21_3DViewer.app
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.tgz gcov_main

style_check:
	clang-format --style=Google -n $(SRCS) $(STYLE)
	
style:
	clang-format --style=Google -i $(SRCS) $(STYLE)

add_coverage_flag:
	$(eval FLAGS += --coverage)


