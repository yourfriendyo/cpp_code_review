all:obj lib main

obj:fileio.c
	gcc -o fio.o -c $^
	gcc -o pic_fio.o -c $^ -fPIC

lib:fio.o
	ar -rc -o libfio.a $^
	gcc -shared -o libfio.so pic_$^

main:main.c
	gcc -o s$@ $^ -lfio -I. -L. -static
	gcc -o d$@ $^ -lfio -I. -L.


.PHONY:clean
clean:
	rm -rf *main *.o lib*
