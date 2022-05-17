#include "node.h"

int main(){
		Node node(1,2,3);
		Node node2(4,5,6);
		node.setG(29);
		node.setH(22);
		node2.setG(29);
		node2.setH(26);
		node2.setParent(&node);
		node.print();
		cout << "node with fcost " << node.fcost() << endl;
		cout << "node with value " << node.getValue() << endl;
		node2.print(); 
		cout << "node with fcost " << node2.fcost() << endl;
		cout << "node with value " << node2.getValue() << endl;
}
