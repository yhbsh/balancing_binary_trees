all: main

main: src/main.c src/lib.c
	clang src/main.c src/lib.c -o bin/main

clean:
	rm -r bin
