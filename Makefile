OBJ=main.o server.o

main:$(OBJ)
	g++ $(OBJ) -o server -levent
	gcc client_demo.c -o client

runs:
	./server

runc:
	./client

clean:
	- rm -f *.o main
	- rm -f ./client
	- rm -f ./server
