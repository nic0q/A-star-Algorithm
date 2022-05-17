#include "container.h"

Container::Container(int size) {
  Container :: size = size;
  count = 0;
  arr = new Node[size];
}
Container::~Container() {
  delete[] arr;
}
// Get the size of the heap
int Container::getSize() {
  return size;
}
// Insert a node in the heap
void Container::insert(Node *node) {
  if (count == size) {
      cout << "Heap is full" << endl;
      return;
  }
  arr[count] = *node; // Notice: copy the node
  count++;
  bubbleUp();
}
// Check is heap is empty
int Container::isEmpty() {
  return count == 0;
}
// Get the root of the heap
Node *Container::peek() {
  return &arr[0];
}
// Print the heap
void Container::print() {
  int h = (int)(log(count)/log(2));
  for(int a=0;a <= h;a++){
    for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
      int k=(1<<a)-1+b;
      cout<<arr[k].fcost()<<" ";
    }
    cout << endl;
  }
}
// Gets and delete a root node (Like pop method)
Node* Container::pull() {
  if (isEmpty()) {
    cout << "Heap is empty" << endl;
    return NULL;
  }
  Node *node = new Node(arr[0]);
  arr[0] = arr[count - 1];
  count--;
  bubbleDown();
  return node;
}
void Container::swap(int i, int j) {
  Node temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void Container::bubbleUp(){
  int index = count - 1;
  int parentIndex =  (index - 1) / 2;
  while (index > 0 &&
      parentIndex >= 0 && 
      arr[index].fcost() < arr[parentIndex].fcost()) {
      swap(index, parentIndex);
      index = parentIndex;
      parentIndex =  (index - 1) / 2;
  }
}
void Container::bubbleDown(){
  int index = 0;
  int leftChildIndex = 1;
  int rightChildIndex = 2;
  while (leftChildIndex < count) {
      // Find the largest child for swapping
      if (arr[leftChildIndex].fcost() < arr[index].fcost() || 
          arr[rightChildIndex].fcost() < arr[index].fcost()) {
          if (arr[leftChildIndex].fcost() < arr[rightChildIndex].fcost()) {
              swap(index, leftChildIndex);
              index = leftChildIndex; // Move to the left child
          } else {
              swap(index, rightChildIndex);
              index = rightChildIndex; // Move to the right child
          }
          // Update the child index
          leftChildIndex = index * 2 + 1;
          rightChildIndex = index * 2 + 2;
      } else {
          break; // no need to bubble down
      }
  }
}
