main: main.o profile.o
	g++ -o main main.o profile.o

tests: tests.o profile.o
	g++ -o tests tests.o profile.o


profile.o: profile.cpp profile.h
	g++ -c profile.cpp


main.o: main.cpp profile.h
	g++ -c main.cpp

tests.o: tests.cpp profile.h
	g++ -c tests.cpp


clean:
	rm -f *o
