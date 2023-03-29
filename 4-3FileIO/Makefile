all:myfile test_flag

myfile:myfile.c
	gcc -o $@ $^ -std=c99

test_flag:test_flag.c
	gcc -o $@ $^ -std=c99

.PHONY:clean
clean:
	rm -rf myfile test_flag
