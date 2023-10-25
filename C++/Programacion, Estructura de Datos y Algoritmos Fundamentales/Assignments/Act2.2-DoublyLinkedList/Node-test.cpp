#include <iostream>
using namespace std;
#include "DNode.h"

int main() {
    DNode<int> node1;
    DNode<int> node2(5);
    DNode<int>* nodeP = &node2; 
    //DNode<int> node3(10, nodeP);
    cout << node1.next << endl;
    cout << node2.data << " " << node2.next << endl;
    cout << node3.data << " " << node3.next << endl;
    cout << &node2<<endl;
    cout << node3.next->data<<endl;

}