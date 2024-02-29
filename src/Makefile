CC= gcc
CFLAGS= -Wall -Werror -Wextra -std=c11 -g
MATH= s21_*.c
OBJECTS= *.o
TEST= ./unit_tests/s21_*.c 
CLANG= clang-format

OS = $(shell uname)

ifeq ($(OS), Darwin)
 TEST_LIBS=-lcheck
else
 TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
endif

.PHONY: all clean test rebuild

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) -c $(MATH)
	ar rcs ../src/s21_string.a $(OBJECTS)

test: s21_string.a
	$(CC) $(CFLAGS) $(MATH) $(TEST) ../src/s21_string.a $(TEST_LIBS) -lm -o test
	./test

build:
	$(CC) $(CFLAGS) s21_string.h *.c

clean:
	rm -rf *.o *.a test *.gch *.gcno *.gcda *.info report 

rebuild:
	make clean
	make all

# brew:
# 	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
# 	brew install lcov

gcov_report: s21_string.a
	$(CC) $(CFLAGS) --coverage $(MATH) $(TEST) $(TEST_LIBS) -lm -o test 
	./test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	rm -rf *.o *.a  *.gch *.gcno test
	open ./report/index.html


clang_n:
	$(CLANG) -style=Google -n *.[ch]

clang_i:
	$(CLANG) -style=Google -i *.[ch]
