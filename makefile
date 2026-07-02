COMPILE_DEBUG = g++ -g -O0 -Wpedantic -fsanitize=address -fsanitize=undefined
COMPILE = g++ -O2

run-all: all
	./example-debug
	./example

.PHONY clean:
	rm -rf example example-debug

all: example example-debug

example:
	${COMPILE} quicksort_example.cpp -o example

example-debug:
	${COMPILE_DEBUG} quicksort_example.cpp -o example-debug
