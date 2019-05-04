CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: heap1 heap2 puzzle heap-puzzle1 heap-puzzle2 heap-puzzle3 copy

heap1: heap1.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap2: heap2.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

puzzle: puzzle.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap-puzzle1: heap-puzzle1.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap-puzzle2: heap-puzzle2.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap-puzzle3: heap-puzzle3.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

copy: copy.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

reference: reference.cpp
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -f heap1 heap2 puzzle heap-puzzle1 heap-puzzle2 heap-puzzle3 copy reference
