CC = g++
CFLAGS = -std=c++17 -Wextra -Wall -Werror
BUILD_DIR = obj
TEST_DIR = ./tests
TEST = ./tests/test
SRC  := $(shell find ./s21_containers ./s21_containersplus -name "s21*.cc" | sed -e 's/\.\///')
OBJS := $(SRC:%.cc=$(BUILD_DIR)/%.o)
TEST_SRC := $(shell find $(TEST_DIR) -name "*.cc" | sed -e 's/\.\///')
TEST_OBJS := $(TEST_SRC:%.c=$(BUILD_TEST_DIR)/%.o)
CGFLAGS = -fprofile-arcs -ftest-coverage --coverage -O0
TEST_FLAGS =-lgtest -lgcov

all: clean test

test: clean $(TEST_DIR)/*.cc $(TEST_DIR)/test_containers.h
	$(CC) $(CFLAGS) $(TEST_DIR)/*.cc $(TEST_DIR)/test_containers.h $(TEST_FLAGS) -o $(TEST)
	$(TEST)

$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@

gcov_report: clean
	$(CC) $(CFLAGS) $(CGFLAGS) $(TEST_OBJS) $(SRC) $(TEST_FLAGS) -o $(TEST)
	$(TEST)
	rm -rf $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda
	gcovr -r . -s --html --html-details -o ./coverage_report.html
	rm -rf *.gcno *.gcda *.o
	open ./coverage_report.html

style_check:
	@find . \( -name '*.h' -o -name '*.inc' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google

style_fix:
	@find . \( -name '*.h' -o -name '*.inc' -o -name '*.cc' \) -print0 | xargs -0 clang-format -i -style=Google

leaks_check: clean test
ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt $(TEST)
endif

cppcheck:
	cppcheck . 2> cppcheck.log

clean:
	@rm -rf *.o *.a coverage* report RESULT_VALGRIND.txt $(TEST) ./obj cppcheck.log *.gcda *.gcno