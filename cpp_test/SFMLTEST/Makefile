mainname = test
all: compile link goo

compile :
	g++ -I. -c $(mainname).cpp
link:
	g++ $(mainname).o -o game -lsfml-graphics -lsfml-window -lsfml-system
goo:
	rm $(mainname).o
	./game
