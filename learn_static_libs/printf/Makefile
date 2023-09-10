all : link compile
	@echo "Completed"

link:
	gcc -c src/prt.c -o src/prt.o
compile:
	ar crs libtest.a src/prt.o
	rm src/*.o
