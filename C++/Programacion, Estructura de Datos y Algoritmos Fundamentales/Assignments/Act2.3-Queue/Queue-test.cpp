#include <iostream>
#include <vector>
using namespace std;
#include "Queue.h"

int main() { 
    Queue<int> queue;

    cout<<"Prueba método push() de números del 1 al 10:\n";
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);

    queue.print();
    cout<<endl;

    cout<<"Prueba método getFront(): elemento al frente de la fila: "<<queue.getFront()<<endl<<endl;

    cout<<"Prueba método pop(): elemento al frente de la fila eliminado: "<<queue.pop()<<endl<<endl;

    cout<<"Fila: \n";
    queue.print();
    cout<<endl;
    
    cout<<"Prueba método pop(): elementos al frente de la fila eliminados: "<<queue.pop()<<" "<<queue.pop()<<" "<<queue.pop()<<endl<<endl;
    cout<<"Fila: \n";
    queue.print();
    cout<<endl;

    cout<<"Prueba errores métodos pop() y getFront(): elementos en al frente de la fila eliminados: "<<queue.pop()<<" "<<queue.pop()<<" "<<queue.pop()<<" "<<queue.pop()<<" "<<queue.pop()<<" "<<queue.pop()<<endl<<endl;
    cout<<"Errores: \n";
    try {
        cout<<queue.pop();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    try {
        cout<<queue.getFront();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}
