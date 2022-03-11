# -*- MakeFile -*-

#target: dependencies
#	action

periodic_table: main.o get_closest.o
	gcc main.o get_closest.o -o periodic_table

main.o: main.c functions.h
	gcc -c main.c

get_closest.o: get_closest.c 
	gcc -c get_closest.c

clean: 
	rm *.o


