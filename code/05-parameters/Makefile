CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: heap-puzzle3 joinCubes-byPointer joinCubes-byValue joinCubes-byReference joinCubes-byValue-const

heap-puzzle3: heap-puzzle3.cpp cs225/Cube.cpp
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
	rm -f heap-puzzle3 joinCubes-byPointer joinCubes-byValue joinCubes-byReference
