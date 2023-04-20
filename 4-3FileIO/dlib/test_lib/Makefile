bin=bin
src=src
libsrc=libsrc

lib=lib
obj=obj

sbin=$(bin)/smain
dbin=$(bin)/dmain

target_bin=$(sbin) $(dbin)

target_lib=$(lib)/libmath.a 
target_shared_lib=$(lib)/libmath.so

target_obj=$(obj)/add.o $(obj)/sub.o
target_pic_obj=$(obj)/pic_add.o $(obj)/pic_sub.o


all: $(target_obj) $(target_pic_obj) $(target_lib) $(target_shared_lib) $(target_bin)


$(obj)/%.o:$(libsrc)/%.c 
	gcc -o $@ -c $<
$(target_lib):$(target_obj)
	ar  -o $@ $^ -rc

$(obj)/pic_%.o:$(libsrc)/%.c 
	gcc -o $@ -c $< -fPIC
$(target_shared_lib):$(target_pic_obj)
	gcc -o $@ $^ -shared 

$(sbin):$(src)/main.c
	gcc -o $(sbin) $(src)/main.c -lmath -Iinc -L$(lib) -static
$(dbin):$(src)/main.c
	gcc -o $(dbin) $(src)/main.c -lmath -Iinc -L$(lib)

.PHONY:clean
clean:
	rm -rf obj/* lib/* bin/*
