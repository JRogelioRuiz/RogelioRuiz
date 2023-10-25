#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;
    BST<int> bst2;

    bst.insert(12);
    bst.insert(7);
    bst.insert(21);
    bst.insert(4);
    bst.insert(9);
    bst.insert(16);
    bst.insert(25);
    bst.insert(2);
    bst.insert(8);
    bst.insert(11);
    bst.insert(19);
    bst.print();

    if (bst.find(19)) {
        cout<<"Nodo encontrado :D\n";
    } else {
        cout<<"No se encontro D:\n";
    }

    cout<<"\nDepth of 19: "<<bst.whatLevelAmI(19)<<endl;
    cout<<"Depth of 16: "<<bst.whatLevelAmI(16)<<endl;
    cout<<"Depth of 21: "<<bst.whatLevelAmI(21)<<endl;
    cout<<"Depth of 12: "<<bst.whatLevelAmI(12)<<endl<<endl;

    cout<<"Ancestors of 11: ";
    bst.ancestors(11);

    cout<<"\nBST Height: "<<bst.height()<<endl<<endl;
    
    cout<<"BST PREORDER:\n";
    bst.visit(1);
    cout<<"BST INORDER:\n";
    bst.visit(2);
    cout<<"BST POSTORDER:\n";
    bst.visit(3);
    cout<<"BST LEVEL BY LEVEL:\n";
    bst.visit(4);

    cout<<"\nDELETE 12: \n\n";
    bst.deleteData(12);
    bst.print();
    cout<<"\nDELETE 9: \n\n";
    bst.deleteData(9);
    bst.print();
    cout<<"\nDELETE 19: \n\n";
    bst.deleteData(19);
    bst.print();

    cout<<"Corrección Bug al borrar root:\n";
    bst2.insert(12);
    bst2.insert(7);
    bst2.insert(21);
    bst2.print();
    bst2.deleteData(12);
    bst2.print();

    return 0;
}