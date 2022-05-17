#include "maze.h"

int main() {
  Maze m(50, 90); // Generate the maze with 100x100 dimension an 90% of probability to spawn a blank space
  m.print();  // Print the maze with no solution
  string solution = m.solve();  // Solve method, return a string with the path
  cout << solution << endl; // Print the solution
  m.print();  // Print the maze solved
  return 0;
}
