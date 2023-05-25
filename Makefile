
CC = c++


clean:
	rm *.o

polygon.o: polygon.hpp polygon.cpp
	$(CC) -c polygon.cpp -o polygon.o -std=c++11

reading.o: reading.hpp polygon.hpp reading.cpp
	$(CC) -c reading.cpp -o reading.o -std=c++11

runit.o: reading.hpp polygon.hpp runit.cpp
	$(CC) -c runit.cpp -o runit.o -std=c++11

it: polygon.o reading.o runit.o
	$(CC) runit.o polygon.o reading.o  -std=c++11
