all: main.c 
	gcc -g -Wall -o me main.c
clean: 
	$(RM) me