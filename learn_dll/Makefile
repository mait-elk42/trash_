libn = libprt.so
srcs = src/prt.c
sro = $(srcs:.c=.o)
all : link 

link :	$(sro) definsys
	gcc -shared $(sro) -o $(libn)
	rm $(sro)

definsys:
	export LD_LIBRARY_PATH=$PWD:LD_LIBRARY_PATH

$(sro) :
	gcc -fPIC -c $(srcs)
	mv *.o src/
re: $(sro)
	gcc -shared $(sro) -o $(libn)
	rm $(sro)
clean:
	rm $(libn)
	
