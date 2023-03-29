all:myfile flag

myfile:myfile.c
	gcc -o $@ $^ -std=c99

flag:flag.c
	gcc -o $@ $^ -std=c99

.PHONY:clean
clean:
	rm -rf myfile flag
