all:myfile flag test

myfile:myfile.c
	gcc -o $@ $^ -std=c99

flag:flag.c
	gcc -o $@ $^ -std=c99

test:test.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -rf myfile flag test
