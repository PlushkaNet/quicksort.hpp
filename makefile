COMPILE_DEBUG = g++ -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address -fsanitize=undefined
COMPILE = g++ -O2

run-all: all
	./example-debug
	./example
	./tests-debug
	./tests

.PHONY clean:
	rm -rf example example-debug tests tests-debug

all: example example-debug tests tests-debug

example:
	${COMPILE} quicksort_example.cpp -o example

example-debug:
	${COMPILE_DEBUG} quicksort_example.cpp -o example-debug

tests:
	${COMPILE} tests.cpp -o tests

tests-debug:
	${COMPILE_DEBUG} tests.cpp -o tests-debug
