bin=bin
src=src
libsrc=libsrc

liba=lib/a
libso=lib/so
obja=obj/a
objso=obj/so

sbin=$(bin)/smain
dbin=$(bin)/dmain

target_bin=$(sbin) $(dbin)

target_liba=$(liba)/libmath.a 
target_libso=$(libso)/libmath.so

target_obja=$(obja)/add.o $(obja)/sub.o
target_objso=$(objso)/add.o $(objso)/sub.o


all: $(target_obja) $(target_objso) $(target_liba) $(target_libso) $(target_bin)


$(obja)/%.o:$(libsrc)/%.c 
	gcc -o $@ -c $<

$(objso)/%.o:$(libsrc)/%.c 
	gcc -fPIC -o $@ -c $<

$(target_liba):$(target_obja)
	ar -rc -o $@ $^
$(target_libso):$(target_objso)
	gcc -shared -o $@ $^

$(sbin):$(src)/main.c
	gcc -o $(sbin) $(src)/main.c -lmath -Iinc -L$(liba) 
$(dbin):$(src)/main.c
	gcc -o $(dbin) $(src)/main.c -lmath -Iinc -L$(libso)

.PHONY:clean
clean:
	rm -rf obj/a/* obj/so/* lib/a/* lib/so/* bin/*
