
source = $(wildcard *.c)

objs= $(patsubst %.c,%.o, $(source))

.PHONY : clean, compile, run 

run : compile 
	./$^

# Il faut ajouter le math flag lors de la compilation vers le binaire final 	
compile : $(objs)
	gcc $^ -lm -o $@

%.o : %.c 
	gcc -c $< -o $@

clean :
	rm *.o *.dat compile 2>/dev/null || true 	
		
