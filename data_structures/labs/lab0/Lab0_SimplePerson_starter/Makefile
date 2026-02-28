SPtester: SPtester.o SimplePerson.o
	g++ -o SPtester SPtester.o SimplePerson.o

SPtester.o: SPtester.cpp
	g++ -c SPtester.cpp

SimplePerson.o: SimplePerson.cpp
	g++ -c SimplePerson.cpp

clean:
	rm -rf *.o SPtester
