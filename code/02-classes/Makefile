EXE = main
OBJS = main.o Cube.o
CLEAN_RM =

include ../_make/generic.mk

# Directory-specific rules:
puzzle: puzzle.cpp Cube2.cpp
	$(LD) $^ $(LDFLAGS) -o $@

main-ref: main-ref.cpp
	$(LD) $^ $(LDFLAGS) -o $@

all: main-ref
CLEAN_RM += main-ref puzzle