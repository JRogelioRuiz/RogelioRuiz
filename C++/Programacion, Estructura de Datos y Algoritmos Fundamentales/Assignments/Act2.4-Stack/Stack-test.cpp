#include <iostream>
#include <vector>
using namespace std;
#include "Stack.h"

int main() { 
    Stack<int> stack;

    cout<<"Prueba método push() de números del 1 al 10:\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);

    stack.print();
    cout<<endl;

    cout<<"Prueba método getTop(): elemento en la cima de la Pila: "<<stack.getTop()<<endl<<endl;

    cout<<"Prueba método pop(): elemento en la cima de la Pila eliminado: "<<stack.pop()<<endl<<endl;

    cout<<"Pila: \n";
    stack.print();
    cout<<endl;
    
    cout<<"Prueba método pop(): elementos en la cima de la Pila eliminados: "<<stack.pop()<<" "<<stack.pop()<<" "<<stack.pop()<<endl<<endl;
    cout<<"Pila: \n";
    stack.print();

    cout<<"Prueba errores métodos pop() y getTop(): elementos en la cima de la Pila eliminados: "<<stack.pop()<<" "<<stack.pop()<<" "<<stack.pop()<<" "<<stack.pop()<<" "<<stack.pop()<<" "<<stack.pop()<<endl<<endl;
    cout<<"Errores: \n";
    try {
        cout<<stack.pop();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    try {
        cout<<stack.getTop();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    cout<<endl;
}
