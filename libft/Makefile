srcs = src/*.c
outs = *.o
libn = libft.a

all : $(outs)
	ar -crs $(libn) $(outs)
	@make clean

$(outs):
	gcc -c $(srcs)

clean:
	rm *.o

fclean:
	rm $(libn)