SPtester: SimplePerson.o Student.o SPtester.o
	g++ -o  SPtester SimplePerson.o Student.o SPtester.o

SPtester.o: SPtester.cpp
	g++ -c SPtester.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

SimplePerson.o: SimplePerson.cpp
	g++ -c SimplePerson.cpp

clean:
	rm -rf *.o SPtester
