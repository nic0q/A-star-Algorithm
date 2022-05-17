#include "maze.h"

int main() {
  Node node1(1,2,5);
  Node node2(1,2,4);
  Node node3(1,2,3);

  Container heap(20);
  cout << "Add a node" << endl;
  heap.insert(&node1);
  cout << heap.pull() << endl;
  cout << "New low cost node" << endl;
  heap.insert(&node2);
  cout << heap.pull() << endl;
  cout << "The node cost is lower than the last one" << endl;
  heap.insert(&node3);
  cout << heap.pull() << endl;
  cout << "The heap size is " << heap.getSize() << endl;
}
