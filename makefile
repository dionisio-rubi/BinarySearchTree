all: tree

tree: main.o
	g++ -o tree main.o

main.o: main.cpp LinkedBinaryTreeNode.h LinkedBSearchTree.h
	g++ -c main.cpp

clean:
	rm *.o *.txt tree