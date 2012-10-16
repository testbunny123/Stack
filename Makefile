run.exe: main.o stack.o
	gcc -o run.exe main.o stack.o -g

main.o: main.c
	gcc -c main.c -g

stack.o: stack.c
	gcc -c stack.c -g

clean:
	rm -f *.o
