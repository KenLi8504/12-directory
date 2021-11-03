all: directory.o
	gcc -o main directory.o
directory.o:
	gcc -c directory.c
clean:
	rm -rf main main.o
run:
	./main
