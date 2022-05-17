#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>
#include "container.h"
using namespace std;

// best practice, avoid numeric constant
#define EMPTY 0 // " "
#define WALL 1  // "#"
#define DOOR 2  // "X"
#define END 3   // "G"
#define PATH 4  // "O"
// modificar datos para la cantidad de paredes / espacios que se ocuparan.
// Class representation of maze structure, generate a random maze with a percentaje of wall, also find
// a paht from startNode to goalNode and print the maze and the path.
class Maze{
  private:
    int **closedList; // Closedlist Matrix
    int **openList;   // OpenList Matrix
    Node startNode;
    Node goalNode;
    Node **maze; // Matrix with the mazess
    int per;    // Percentage of generate a wall or path
    int n;      // Dimensions of the maze (n x n)

  public:
    Maze(int n, int per);
    ~Maze();
    bool inClosedList(Node node, vector <Node> vec);
    void setStartGoal(Node start, Node goal);
    vector <Node> getNeightbours(Node node);
    bool couldGoBottom(Node node);
    bool couldGoRight(Node node);
    bool couldGoLeft(Node node);
    bool couldGoTop(Node node);
    void generate();
    string solve();
    void print();
  };