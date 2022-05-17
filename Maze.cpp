#include "maze.h"

Maze::Maze(int n, int per){
  srand(time(NULL)); // set seed for random number generator
  Maze::n = n;
  Maze::per = per;
  Maze::generate();
}
// Deletes the maze's matrix
Maze::~Maze(){ // Delete the maze array
  for(int i = 0; i < n; i++){
    delete[] maze[i];
  }
  delete[] maze;
}
// Sets the goal and start node of the maze
void Maze :: setStartGoal(Node start, Node goal){
  maze[start.get_i()][start.get_j()].setValue(DOOR);
  maze[goal.get_i()][goal.get_j()].setValue(END);
  Maze::startNode = maze[start.get_i()][start.get_j()];
  Maze::goalNode = maze[goal.get_i()][goal.get_j()];
}
// Generate the maze's matrix, closedList and Openlist to reduce the algorithm cost
void Maze :: generate(){
  maze = new Node * [n];
    closedList = new int * [n];
  openList = new int * [n];
  for(int i = 0; i < n ; i++){
    maze[i] = new Node [n];
    closedList[i] = new int [n];
    openList[i] = new int [n];
    for(int j = 0; j < n; j++){
      Node a(i,j,rand()%100>per);
      maze[i][j] = a;
      closedList[i][j] = 0;
      openList [i][j] = 0;
    }
  }
  setStartGoal(maze[0][0],maze[n-1][n-1]);
}
// Print the maze
void Maze::print(){
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < n; j++){
      if(maze[i][j].getValue() == PATH){
        cout << "\033[1;32mO\033[0m";
      }
      else if(maze[i][j].getValue() == WALL){
        cout << "#";
      }
      else if(maze[i][j].getValue() == EMPTY){
        cout << " ";
      }
      else if(maze[i][j].getValue() == DOOR){
        cout << "\033[1;35mX\033[0m";
      }
      else if(maze[i][j].getValue() == END){
        cout << "\033[1;35mG\033[0m";
      }
    }
    cout << "\n";
  }
}
// couldGo....a functions that compute if I can move in a given direction
bool Maze :: couldGoLeft (Node node){
  if(node.get_j() == 0){
    return false;
  }
  return true;
}
bool Maze :: couldGoRight(Node node){
  if(node.get_j() == n - 1){
    return false;
  }
  return true;
}
bool Maze :: couldGoTop(Node node){
  if(node.get_i() == 0){
    return false;
  }
  return true;
}
bool Maze :: couldGoBottom(Node node){
  if(node.get_i() == n - 1){
    return false;
  }
  return true;
}
// Get all possible neightbours, in this case, North, South, West, East
vector <Node> Maze :: getNeightbours(Node node){
  vector <Node> arr;
  if (couldGoLeft(node)){
    arr.push_back(maze[node.get_i()][node.get_j()-1]);
  }
  if(couldGoRight(node)){
    arr.push_back(maze[node.get_i()][node.get_j()+1]);
  }
  if(couldGoBottom(node)){
    arr.push_back(maze[node.get_i()+1][node.get_j()]);
  }
  if(couldGoTop(node)){
    arr.push_back(maze[node.get_i()-1][node.get_j()]);
  }
  return arr;
}
float getDistance(Node nodeA, Node nodeB) {
	return sqrt(pow(nodeA.get_i() - nodeB.get_i(),2) + pow(nodeA.get_j() - nodeB.get_j(),2));
  
}
// Solve/Find the most efficient path from startNode to goalNode
string Maze :: solve(){
  Container heap(n*n);
  heap.insert(&startNode);
  openList[startNode.get_i()][startNode.get_j()] = 1;
  while(!heap.isEmpty()){
    Node current = heap.pull();
    openList[current.get_i()][current.get_j()] = 0;
    closedList[current.get_i()][current.get_j()] = 1;
    vector <Node> neightbours;  // vector of 4 positions max
    neightbours = getNeightbours(current);
    if(current.get_i() == goalNode.get_i() && current.get_j() == goalNode.get_j()){ // if the current node is the goal node
		  return maze[goalNode.get_i()][goalNode.get_j()].getPath();
    }
    maze[current.get_i()][current.get_j()].setValue(PATH);  // Set the PATH constant to the maze
    for(int i = 0; i < neightbours.size(); i++){
      if(neightbours[i].getValue() == WALL ||  closedList[neightbours[i].get_i()][neightbours[i].get_j()] == 1){  // ignore if is a WALL or is in the closedList
        continue;
      }
      int tentative = current.getH() + getDistance(current, neightbours[i]);  // Tentative best distance
      if(openList[neightbours[i].get_i()][neightbours[i].get_j()] == 0 || tentative < neightbours[i].getG()){ // If the distance is better than actual
        neightbours[i].setG(tentative); // set the g cost
        neightbours[i].setH(getDistance(neightbours[i],goalNode));  // set the h cost
        maze[neightbours[i].get_i()][ neightbours[i].get_j()].setParent(&maze[current.get_i()][current.get_j()]); // set the parent of actual node(neightbour)
        heap.insert(&neightbours[i]); // Mark as visited
        openList[neightbours[i].get_i()][neightbours[i].get_j()] = 1;
      }
    }
  }
  return "No hay camino";
}