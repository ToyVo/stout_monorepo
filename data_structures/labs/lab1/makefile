runTest.out: Sequence.o Gene.o GeneTest.o
	g++ -o runTest.out Sequence.o Gene.o GeneTest.o

runScore.out: Sequence.o Gene.o GeneScore.o
	g++ -o runScore.out Sequence.o Gene.o GeneScore.o

GeneScore.o: GeneScore.cpp
	g++ -c GeneScore.cpp

GeneTest.o: GeneTest.cpp
	g++ -c GeneTest.cpp

Gene.o: Gene.cpp
	g++ -c Gene.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

clean:
	rm -rf *.o runTest