run.out: Shape.o Circle.o Rectangle.o Tester.o
	g++ -o run.out Shape.o Circle.o Rectangle.o Tester.o

Tester.o: Tester.cpp
	g++ -c Tester.cpp

Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp

Circle.o: Circle.cpp
	g++ -c Circle.cpp

Shape.o: Shape.cpp
	g++ -c Shape.cpp

clean:
	rm -rf *.o *.out
