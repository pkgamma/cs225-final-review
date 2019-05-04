EXE = stlList
OBJS = stlList.o
CLEAN_RM = stlList-forEach

include ../_make/generic.mk

stlList-forEach: stlList-forEach.cpp
	$(CXX) $(LDFLAGS) $^ -lm -o $@

all: stlList-forEach

