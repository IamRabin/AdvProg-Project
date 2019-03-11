SRC = Main.cpp
EXE = BST.x
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wextra
INC = BST.h Implementation.h

all:$(EXE)

BST.x: Main.cpp
	$(CXX) $(CXXFLAGS) Main.cpp -o BST.x


clean:
	rm -f $(EXE)

.PHONY: clean all format
