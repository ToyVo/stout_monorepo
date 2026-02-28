test: SequenceGrade.o Sequence.o
	g++ -o test SequenceGrade.o Sequence.o

SequenceGrade.o: SequenceGrade.cpp
	g++ -c SequenceGrade.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

clean:
	rm -rf *.o test
