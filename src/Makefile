CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: test gcov_report

math.a: clean
	$(CC) $(CFLAGS) -c s21_*.c
	ar rc math.a *.o

test: math.a
	$(CC) $(CFLAGS) -c unit_tests.c -o test.o 
	$(CC) test.o math.a $(TEST_LIBS) -o test
	./test

gcov_report: math.a
	$(CC) $(CFLAGS) --coverage unit_tests.c s21_*.c math.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "math" -o math.info -c -d .
	genhtml -o report math.info
	open ./report/index.html

clean:
	rm -rf test *.o *.a *.gcno *.gcda *.info report gcov_test
