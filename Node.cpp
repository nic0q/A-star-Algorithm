#include "node.h"
Node::Node() {
  this->iCord = 0;
  this->jCord = 0;
  this->value = 0;
}
Node::Node(Node* node) {
  this->iCord = node->iCord;
  this->jCord = node->jCord;
  this->value = node->value;
}
Node::Node(int i, int j, int value) {
  this->iCord = i;
  this->jCord = j;
  this->value = value;
  this->parent = NULL;
}
Node::~Node () {
}
// the i position in matrix
int Node::get_i() {
  return this->iCord;
}
// the j position in matrix
int Node::get_j() {
  return this->jCord;
}
// value = WALL | PATH | EMPTY | ENTRY
int Node::getValue() {
  return this->value;
}
// get g value
int Node::getG(){
  return this->g;
}
// get h value: heuristic
int Node::getH(){
  return this->h;
}
// Computes the f cost (f = g + h)
int Node::fcost(){
  return this->g + this->h;
}
// get parent node
void Node::setParent(Node*parent) {
  this->parent = parent;
}
void Node::setValue(int value) {
  this->value = value;
}
void Node:: setG(int g){
  this->g = g;
}
void Node:: setH(int h){
  this->h = h;
}
void Node::print() {
  cout << "(" << this->iCord << "," << this-> jCord << ")[" << this->value << "]"<<"->"<< this->parent << "<-" << endl;
}
// get the path from current node to start node (pointing to NULL)
string Node::getPath() {
  string s="("+to_string(this->iCord)+","+to_string(this->jCord)+")";
  if (this->parent != NULL) {
    s = s + this->parent->getPath();
  }
  return s; 
}
