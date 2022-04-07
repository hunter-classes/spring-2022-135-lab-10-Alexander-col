main: main.o funcs.o
	g++ -o main main.o funcs.o



clean: 
	rm -f main.o funcs.o 