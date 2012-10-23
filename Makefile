run.exe: main.o stack.o stack-interface.o
	gcc -o run.exe main.o stack.o stack-interface.o -g

main.o: main.c
	gcc -c main.c -g

stack.o: stack.c
	gcc -c stack.c -g

stack-interface.o: stack-interface.c
	gcc -c stack-interface.c -g

clean:
	rm -f *.o
