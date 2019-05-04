CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: virtual-main main

main: main.cpp Shape.cpp Square.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@ 

virtual-main: virtual-main.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

clean:
	rm -f virtual-main.cpp
