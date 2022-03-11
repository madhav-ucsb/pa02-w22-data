CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=runMovies


all: ${BINARIES}

tests: ${BINARIES}
	./runMovies


runMovies: main.o movie.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

movie.o: movies.cpp movies.h
	${CXX} movie.cpp -c
runMovies.o: main.cpp movies.h 
	${CXX} main.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o