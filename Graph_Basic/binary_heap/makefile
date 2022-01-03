all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : main.o binary_heap.o
	g++ -g -Wall -i $@ $^

clean :
	rm -f *.o main