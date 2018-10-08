bin: algo-analysis.o algorithm.o main.o
	c++ algo-analysis.o algorithm.o main.o -g -o bin
	rm *.o

algo-analysis.o: algo-analysis.cpp
	c++ algo-analysis.cpp -c -g

algorithm.o: algorithm.cpp
	c++ algorithm.cpp -c -g

main.o: main.cpp
	c++ main.cpp -c -g

clean:
	rm *.o
