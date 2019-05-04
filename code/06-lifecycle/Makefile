CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: joinCubes-byPointer joinCubes-byValue joinCubes-byReference main

main: main.cpp cs225/Cube.cpp Tower.cpp
	$(CXX) $(FLAGS) $^ -o $@

joinCubes-byPointer: joinCubes-byPointer.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

joinCubes-byValue: joinCubes-byValue.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

joinCubes-byReference: joinCubes-byReference.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

joinCubes-byValue-const: joinCubes-byValue-const.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

clean:
	rm -f joinCubes-byPointer joinCubes-byValue joinCubes-byReference main
