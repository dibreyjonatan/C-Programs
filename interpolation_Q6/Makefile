
output="sortie"
.PHONY:clean compile python_plot plot_all run 
source=$(wildcard *.c) 
objs=$(patsubst %.o, %.c,$(source))
clean : 
	rm output *.o 

run : compile 
	./$^	

compile : $(objs)
	gcc $^ -lm  -o $@	

%.o : %.c 
	gcc $< -o $@	

plot_all :
	./plot_all.sh

python_plot:
	source ~/venv/activate ||:
	python graph.py 	
	
