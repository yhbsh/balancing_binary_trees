
draw: run
	dot -Tjpg ../out/out.dot -o ../out/out.jpg && ..\\out\\out.jpg


run: build
	../exe/main

build: ./main.c
	gcc -o ../exe/main main.c