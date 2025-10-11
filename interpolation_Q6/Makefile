
library=$(wildcard *.h)
.PHONY:clean compile python_plot plot_all run 
#collect all c files
source=$(wildcard *.c)
#performs a text replacement of *.c files to *.o files i.e all objet files will have thesame name as c files
#the line below creates the name of object files 
#objs=$(patsubst %.o, %.c,$(source))  
 
clean : 
	rm *.o compile  2>/dev/null || true
	
# 2>/dev/null redige la sortie de la commande executés vers le fichier /dev/null
# true est une commande qui ne fait rien 
# en gros le || veut dire que soit la commande est executé ou true est executé 	

run : compile 
	./$^	

#prerequisites are files !!!  
#make automatically search .h files and includes them 
compile : $(source)   
	gcc $^ -lm -o $@
plot_all :
	./plot_all.sh

python_plot:
	source ~/venv/activate ||:
	python graph.py 	
	
