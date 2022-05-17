all: test_maze test_node test_container main

main: Main.cpp Maze.o Container.o Node.o
	g++ Maze.o Node.o Container.o Main.cpp -o main

test_container: testContainer.cpp Node.o Container.o
	g++ Container.o Node.o testContainer.cpp -o test_container

test_maze: testMaze.cpp Maze.o Node.o Container.o
	g++ Maze.o Node.o Container.o testMaze.cpp -o test_maze

test_node: testNode.cpp Node.o
	g++ Node.o testNode.cpp -o test_node

Container.o: Container.cpp container.h
	g++ -c Container.cpp

Maze.o: Maze.cpp maze.h
	g++ -c Maze.cpp

Node.o: Node.cpp node.h
	g++ -c Node.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -f *.o