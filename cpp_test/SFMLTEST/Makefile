all: compile link goo

compile :
	g++ -c main.cpp
link:
	g++ main.o -o game -lsfml-graphics -lsfml-window -lsfml-system
goo:
	./game
	rm main.o