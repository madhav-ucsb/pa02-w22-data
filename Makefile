CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=runMovies


all: ${BINARIES}

tests: ${BINARIES}
	./runMovies


runMovies: main.o movie.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

movie.o: movie.cpp movie.h
	${CXX} movie.cpp -c
runMovies.o: main.cpp movie.h 
	${CXX} main.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o