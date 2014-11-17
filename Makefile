all: ppm.out

ppm.out: ppm.cpp Image.o
	g++ -Wall -o ppm.out ppm.cpp Image.o

Image.o: Image.h Image.cpp
	g++ -Wall -o Image.o Image.cpp -c

clean:
	rm *.o

mrproper: clean
	rm ppm.out
