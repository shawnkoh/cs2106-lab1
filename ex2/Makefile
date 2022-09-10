all:
	gcc -std=c99 -Wall -Wextra node.c ex2.c -o ex2

clean:
	rm -f *.o ex2

test:
	./ex2 < sample.in | diff -Z sample.out -