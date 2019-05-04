EXE = main
OBJS = main.o
CLEAN_RM = functionTemplate1 virtual-dtor

include ../_make/generic.mk

functionTemplate1: functionTemplate1.cpp cs225/Cube.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

virtual-dtor: virtual-dtor.cpp
	$(CXX) $(FLAGS) $^ -lm -o $@

all: functionTemplate1 virtual-dtor


