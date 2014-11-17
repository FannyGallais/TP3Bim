all: ppm.out

ppm.out: ppm.c Image.o
	gcc -Wall -o ppm.out ppm.c Image.o

Image.o: Image.h Image.c
	gcc -Wall -o Image.o Image.c -c
