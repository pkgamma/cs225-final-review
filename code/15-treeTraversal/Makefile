CXX = clang++
FLAGS = -std=c++1y -stdlib=libc++ -O0 -Wall -Wextra -pedantic -lpthread -lm

all: main 

main: main.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

clean:
	rm -f main
