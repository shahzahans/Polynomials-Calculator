CFLAGS = -std=c++14 -Wall -g

main:	main.o polynomial.o
	g++ main.o polynomial.o -o poly $(CFLAGS)

main.o:	main.cpp polynomial.h
	g++ -c main.cpp -o main.o $(CFLAGS)

polynomial.o:	polynomial.h polynomial.cpp
	g++ -c polynomial.cpp $(CFLAGS)

test: test.o polynomial.o
	g++ test.o polynomial.o -o test $(CFLAGS)

test.o:	unit-test.cpp polynomial.h
	g++ -c unit-test.cpp -o test.o $(CFLAGS)

clean:
	rm test -f poly *.o

run: test
	./test

runmc: test
	valgrind --leak-check=full ./test
