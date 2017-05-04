all: ej1 ej2
clean:
	rm -f ej1
	rm -f ej2

ej1: ej1.cpp 
	g++ -std=c++11 -g ej1.cpp -o ej1

ej2: ej2.cpp 
	g++ -std=c++11 -g ej2.cpp -o ej2