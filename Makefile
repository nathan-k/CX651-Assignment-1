all: calc test-mini test-mini2 caller

test-mini: test.c mini.c
	gcc test.c mini.c -Wall -o test-mini

test-mini2: test.c mini_mod.S
	gcc -Wall test.c mini_mod.S -o test-mini2

calc: calc.c mystery.S
	gcc -Wall calc.c mystery.S -o calc

caller: caller.c
	gcc caller.c -Wall -o caller

# TODO: complete makefile rules for calc, test-mini, test-mini2, caller.

clean:
	rm -f *.o
	rm -f calc
	rm -f caller
	rm -f test-mini
	rm -f test-mini2