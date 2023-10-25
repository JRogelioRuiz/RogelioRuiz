#include <iostream>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 100 + 1;
    list.push_back(num);
  }
}

int main() {
    
    vector<int> v;

    createListInt(v, 10);

    Heap<int> heap(v);

    MinHeap<int> heap1(v);

    int input = 1;
    bool tipoHeap = true;

    while (input) {
        (tipoHeap) ? cout<<"Elige una opción a realizar con el MaxHeap:" : cout<<"Elige una opción a realizar con el MinHeap:";
        cout<<"\n 1. Push\n 2. Pop\n 3. Top\n 4. isEmpty?\n 5. Size\n 6. Print\n 7. HeapSort\n 8. Cambiar a MaxHeap/MinHeap\n 0. Salir\n";
        cout<<"Heap actual:\n";
        (tipoHeap) ? heap.print() : heap1.print();
        cin>>input;
        while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7 && input != 8) {
            cout<<"\nOPCIÓN NO VÁLIDA\n";
            (tipoHeap) ? cout<<"Elige una opción a realizar con el MaxHeap:" : cout<<"Elige una opción a realizar con el MinHeap:";
            cout<<"\n 1. Push\n 2. Pop\n 3. Top\n 4. isEmpty?\n 5. Size\n 6. Print\n 7.  HeapSort\n 8. Cambiar a MaxHeap/MinHeap\n 0. Salir\n";
            cout<<"Heap actual:\n";
            (tipoHeap) ? heap.print() : heap1.print();
            cin>>input;
        }
        if (input == 1) {
            cout<<"Ingresa el valor a agregar al Heap: ";
            int inputPush;
            cin>>inputPush;
            (tipoHeap) ? heap.push(inputPush) : heap1.push(inputPush);
            cout<<"Heap modificado: \n";
            (tipoHeap) ? heap.print() : heap1.print();
            cout<<endl;

        } else if (input == 2) {
            cout<<"Valor eliminado del Heap: ";
            (tipoHeap) ? cout<<heap.pop()<<endl : cout<<heap1.pop()<<endl;
            cout<<"Heap modificado: \n";
            (tipoHeap) ? heap.print() : heap1.print();
            cout<<endl;

        } else if (input == 3) {
            (tipoHeap) ? cout<<"Valor de mayor prioridad en el MaxHeap: "<<heap.top()<<endl<<endl : cout<<"Valor de mayor prioridad en el MinHeap: "<<heap1.top()<<endl<<endl;
        
        } else if (input == 4) {
            bool empty; 
            (tipoHeap) ? empty = heap.isEmpty() : empty = heap1.isEmpty();
            (empty) ? cout<<"El Heap está vacío\n\n" : cout<<"El Heap no está vacío\n\n"; 
        
        } else if (input == 5) {
            (tipoHeap) ? cout<<"Tamaño del MaxHeap: "<<heap.getSize()<<endl<<endl : cout<<"Tamaño del MinHeap: "<<heap1.getSize()<<endl<<endl;
        
        } else if (input == 6) {
            cout<<"Imprimir HEAP:\n";
            (tipoHeap) ? heap.print() : heap1.print();
            cout<<endl;
        
        } else if (input == 7) {
            cout<<"HeapSort:\n";
            if (tipoHeap) {
                Heap<int> auxHeap;
                while (!heap.isEmpty()) {
                    auxHeap.push(heap.top());
                    cout<<heap.pop() << " ";
                }
                heap = auxHeap; 
            } else {
                MinHeap<int> auxHeap;
                while (!heap1.isEmpty()) {
                    auxHeap.push(heap1.top());
                    cout<<heap1.pop() << " ";
                }
                heap1 = auxHeap;
            }
            cout<<endl<<endl;
        } else if (input == 8) {
            (tipoHeap) ? cout<<"Cambio de MaxHeap a MinHeap:\n" : cout<<"Cambio de MinHeap a MaxHeap:\n";
            if (tipoHeap) {
                while (!heap1.isEmpty()) {
                    heap1.pop();
                }
                cout<<" MaxHeap:\n ";
                while (!heap.isEmpty()) {
                    heap1.push(heap.top());
                    cout<<heap.pop() << " ";
                }
                cout<<"\n MinHeap:\n ";
                heap1.print();
                cout<<endl;
            } else {
                while (!heap.isEmpty()) {
                    heap.pop();
                }
                cout<<" MinHeap:\n ";
                while (!heap1.isEmpty()) {
                    heap.push(heap1.top());
                    cout<<heap1.pop() << " ";
                }
                cout<<"\n MaxHeap:\n ";
                heap.print();
                cout<<endl;
            } 
            (tipoHeap) ? tipoHeap = false : tipoHeap = true;
        }


    }
    // cout<<"/*MAXHEAP*********/\nMaxHeap: \n";
    // heap.print();
    // cout<<endl;

    // cout<<"MaxHeap Top: ";
    // cout<<heap.top()<<endl<<endl;

    // cout<<"MaxHeap Pop: ";
    // cout<<heap.pop()<<endl<<endl;

    // cout<<"MaxHeap: \n";
    // heap.print();
    // cout<<endl;

    // cout<<"MaxHeap Push: 50\n";
    // heap.push(50);    
    // heap.print();
    // cout<<endl;
    
    // cout<<"MaxHeap getSize(): ";
    // cout<<heap.getSize()<<endl<<endl;

    // cout<<"MaxHeap Pop while !isEmpty(): \n";
    // while (!heap.isEmpty()) {
    //     cout<<heap.pop() << " ";
    // }

    // cout<<"\n\nMaxHeap getSize(): ";
    // cout<<heap.getSize()<<endl<<endl;

    // cout<<"/*MINHEAP********/\nMinHeap: \n";
    // heap1.print();
    // cout<<endl;

    // cout<<"MinHeap Top: ";
    // cout<<heap1.top()<<endl<<endl;

    // cout<<"MinHeap Pop: ";
    // cout<<heap1.pop()<<endl<<endl;

    // cout<<"MinHeap: \n";
    // heap1.print();
    // cout<<endl;

    // cout<<"MinHeap Push: 50\n";
    // heap1.push(50);    
    // heap1.print();
    // cout<<endl;

    // cout<<"MinHeap getSize(): ";
    // cout<<heap1.getSize()<<endl<<endl;

    // cout<<"MinHeap Pop while !isEmpty(): \n";
    // while (!heap1.isEmpty()) {
    //     cout<<heap1.pop() << " ";
    // }

    // cout<<"\n\nMinHeap getSize(): ";
    // cout<<heap1.getSize()<<endl<<endl;    

    return 0;
}