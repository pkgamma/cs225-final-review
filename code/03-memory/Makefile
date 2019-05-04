CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: example1 example2 extra-puzzle1 extra-puzzle2 heap1 heap2 main puzzle sizeof-int sizeof-intptr sizeof-cube stackframe

example1: example1.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

example2: example2.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

extra-puzzle1: extra-puzzle1.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

extra-puzzle2: extra-puzzle2.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap1: heap1.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

heap2: heap2.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

main: main.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

puzzle: puzzle.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

sizeof-int: sizeof-int.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

sizeof-intptr: sizeof-intptr.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

sizeof-cube: sizeof-cube.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

stackframe: stackframe.cpp Cube.cpp
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -f example1 example2 extra-puzzle1 extra-puzzle2 heap1 heap2 main puzzle sizeof-int sizeof-intptr sizeof-cube stackframe
