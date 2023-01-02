CC = gcc
FLAGS = -Wall -g -fPIC
PROG1 = isort.o
PROG2 = txtfind.o


all: isort txtfind     

isort: $(PROG1) 
	$(CC) $(FLAGS) -o isort $(PROG1)        

txtfind: $(PROG2)                             
	$(CC) $(FLAGS) -o txtfind $(PROG2)      

isort.o: isort.c isort.h         
	$(CC) $(FLAGS) -c isort.c      

txtfind.o: txtfind.c txtfind.h             
	$(CC) $(FLAGS) -c txtfind.c              

.PHONY:clean all

clean:
	rm -f isort txtfind *.o