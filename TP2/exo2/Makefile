
# The prerequisities can be either list of files or another target 
source = $(wildcard *.c)
objs=$(patsubst %.c,%.o, $(source))
CFLAGS= -Wall -Werror -g -Wno-unsed-variable 
executable=output

.PHONY : compile, run, help , clean 

clean :
	rm *.o  $(executable) 2>/dev/null || true 

run : compile
	./$(executable)

compile : $(objs)
	gcc $^ -o $(executable)

%.o : %.c 
	gcc -c $(CFLAGS) $< -o $@
help :
	$(info The available targets are :) 
	$(info compile) 
	$(info run) 
	$(info help) 
	$(info clean) 
	
