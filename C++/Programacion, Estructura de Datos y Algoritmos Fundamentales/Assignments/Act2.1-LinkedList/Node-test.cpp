#include <iostream>
using namespace std;
#include "Node.h"

int main() {
    Node<int> node1;
    Node<int> node2(5);
    Node<int>* nodeP = &node2;
    Node<int> node3(10, nodeP);
    cout << node1.next << endl;
    cout << node2.data << " " << node2.next << endl;
    cout << node3.data << " " << node3.next << endl;
    cout << &node2<<endl;
    cout << node3.next->data<<endl;

}