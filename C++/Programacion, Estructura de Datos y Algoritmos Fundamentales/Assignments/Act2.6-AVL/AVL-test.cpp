#include <iostream>
using namespace std;

#include "AVL.h"

int main() {

    AVL<int> avl;
    AVL<int> avll;
    AVL<int> avl2;
    AVL<int> avl3;
    AVL<int> avl4;
    AVL<int> avl5;

    cout<<"Ejemplo Insercion Left Left:\n";
    avl.insert(13);
    avl.insert(10);
    avl.insert(15);
    avl.insert(5);
    avl.insert(11);
    avl.insert(16);
    avl.insert(4);
    avl.insert(8);
    avl.print();
    cout<<"Insert: 3\n";
    avl.insert(3);
    avl.print();
    cout<<endl;

    cout<< "Find 16: \n";
    if (avl.find(16)) {
    cout<<"Nodo encontrado :D\n";
    } else {
        cout<<"No se encontro D:\n";
    }
    cout<<endl;
    
    cout<<"Ejemplo Insercion Left Left:\n";
    avll.insert(1);
    avll.insert(0);
    avll.insert(9);
    avll.insert(5);
    avll.insert(-1);
    avll.print();
    cout<<"Insert: 2\n";
    avll.insert(2);
    avll.print();
    cout<<endl<<endl;

    cout<<"Ejemplo Insercion Right Right:\n";
    avl2.insert(30);
    avl2.insert(5);
    avl2.insert(35);
    avl2.insert(32);
    avl2.insert(40);
    avl2.print();
    cout<<"Insert: 45\n";
    avl2.insert(45);
    avl2.print();
    cout<<endl<<endl;
    
    cout<<"Ejemplo Insercion Left Right:\n";
    avl3.insert(13); 
    avl3.insert(10);
    avl3.insert(15);
    avl3.insert(5);
    avl3.insert(11);
    avl3.insert(16);
    avl3.insert(4);
    avl3.insert(6);
    avl3.print();
    cout<<"Insert: 7\n";
    avl3.insert(7);
    avl3.print();
    cout<<endl<<endl;

    cout<<"Ejemplo Insercion Right Left:\n";
    avl4.insert(5); 
    avl4.insert(2);
    avl4.insert(7);
    avl4.insert(1);
    avl4.insert(4);
    avl4.insert(6);
    avl4.insert(9);
    avl4.insert(3);
    avl4.insert(16);
    avl4.print();
    cout<<"Insert: 15\n";
    avl4.insert(15);
    avl4.print();
    cout<<endl<<endl;

    cout<<"Ejemplo Delete Dato:\n";
    avl5.insert(9); 
    avl5.insert(5);
    avl5.insert(10);
    avl5.insert(0);
    avl5.insert(6);
    avl5.insert(11);
    avl5.insert(3);
    avl5.insert(2);
    avl5.insert(-1);
    avl5.print();
    cout<<"delete 10:\n";
    avl5.deleteData(10);
    avl5.print();
    cout<<"delete 11:\n";
    avl5.deleteData(11);
    avl5.print();
    cout<<"delete 2:\n";
    avl5.deleteData(2);
    avl5.print();
    cout<<"delete 6:\n";
    avl5.deleteData(6);
    avl5.print();
    cout<<"delete 9:\n";
    avl5.deleteData(9);
    avl5.print();
    cout<<"delete -1:\n";
    avl5.deleteData(-1);
    avl5.print();
    cout<<"delete 3:\n";
    avl5.deleteData(3);
    avl5.print();
    cout<<endl<<endl;


    /*if (avl.find(19)) {
        cout<<"Nodo encontrado :D\n";
    } else {
        cout<<"No se encontro D:\n";
    }

    cout<<"\nDepth of 19: "<<avl.whatLevelAmI(19)<<endl;
    cout<<"Depth of 16: "<<avl.whatLevelAmI(16)<<endl;
    cout<<"Depth of 21: "<<avl.whatLevelAmI(21)<<endl;
    cout<<"Depth of 12: "<<avl.whatLevelAmI(12)<<endl<<endl;

    // cout<<"Ancestors of 11: ";
    // avl.ancestors(11);

    cout<<"\navl Height: "<<avl.height()<<endl<<endl;
    
    cout<<"avl PREORDER:\n";
    avl.visit(1);
    cout<<"avl INORDER:\n";
    avl.visit(2);
    cout<<"avl POSTORDER:\n";
    avl.visit(3);
    cout<<"avl LEVEL BY LEVEL:\n";
    avl.visit(4);

    cout<<"\nDELETE 12: \n\n";
    avl.deleteData(12);
    avl.print();
    cout<<"\nDELETE 9: \n\n";
    avl.deleteData(9);
    avl.print();
    cout<<"\nDELETE 19: \n\n";
    avl.deleteData(19);
    avl.print();
    */
    return 0;
}