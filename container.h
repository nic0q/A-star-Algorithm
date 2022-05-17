#include <iostream>
#include <math.h>
#include "node.h"
using namespace std;
// Clase usada para representar la cola de prioridad, usando la estructura "heap"
// Contiene metodos para retirar elementos, ver el tamaño, añadir y ver si está vacía
// Una heap es posible representarla en un array, el cual facilita los metodos de recorrer y encontrar datos
class Container {
public:
  Container(int size);
  ~Container();
  int isEmpty();
  void insert(Node *node);
  Node* pull();
  Node* peek();
  int getSize();
  void print();
  bool inHeap(Node e);
private:
  Node *arr;
  int size;
  int count;
  void swap(int i, int j);
  void bubbleUp();
  void bubbleDown();
};
