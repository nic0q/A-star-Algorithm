#include <iostream>
#include <stdlib.h>
using namespace std;

// Un nodo representa una casilla o grid del laberinto, la cual posee 2 coordenadas (i,j)
// un valor si es pared, espacio, salida, entrada o path, ademas cada nodo puede tener un
// previo o padre
class Node {
public:
    Node();
    ~Node();
    Node(Node *node);
    Node(int i, int j, int value);
    int getH();
    int getG();
    void setG(int g);
    void setH(int h);
    int fcost();
    int get_i();
    int get_j();
    int getValue();
    void setParent(Node *previous);
    void setValue(int value);
    string getPath();
    void print();
    int g;
    int h;
private:   
    Node *parent; // the previous node in the path
    int iCord; // row
    int jCord; // column
    int value; // a value representing a cost for choosing this node
};
