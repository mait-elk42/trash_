libn = libprt.a
srcs = src/prt.c
sro = prt.o

all : link 

link :	$(sro)
	ar -crs $(libn) $(sro)
	rm $(sro)
$(sro) :
	gcc -c $(srcs) -o $(sro)
re: $(sro)
	ar -crs $(libn) $(sro)
	rm $(sro)
clean:
	rm $(libn)
	
