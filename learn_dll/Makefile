libn = libprt.so
srcs = src/prt.c
sro = $(srcs:.c=.o)

all : link 

link :	$(sro)
	gcc -shared $(sro) -o $(libn)
	rm $(sro)
$(sro) :
	gcc -fPIC -c $(srcs)
	mv *.o src/
re: $(sro)
	gcc -shared $(sro) -o $(libn)
	rm $(sro)
clean:
	rm $(libn)
	
