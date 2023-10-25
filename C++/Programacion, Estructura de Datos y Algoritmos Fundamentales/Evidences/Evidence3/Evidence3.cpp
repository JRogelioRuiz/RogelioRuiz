#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"


int main() {

    // Archivo de entrada
    ifstream fileIn("log603-3 copy.txt");

    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year, month, day, time, ip, message;
    Heap<Log> logs;
    MinHeap<Log> logs_mH;
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn,line)) { 
        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(line);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip >> message;
        // Ciclo para recorrer cada palabra del campo message
        while (ss >> word) {
            message = message + " " + word;
        }
        // Creamos objeto Log con los datos
        Log log(year, month, day, time, ip, message);
        
        logs.push(log);
        logs_mH.push(log);
        // Incrementamos el contador de registros
        cont++;
    }

    logs.print();
    cout<<endl<<endl;
    logs_mH.print();

    int input = 1;

    while (input) {
        cout<<"Elige una opción:\n";
        cout<<" 1. Ordenar datos de mayor a menor\n 2. Ordenar datos de menor a mayor\n 3. Desplegar los 10 datos más comúnes\n 4. Búsqueda por ip en un BST\n 5. Salir\n";
        cin >> input;
        while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
            cout<<"OPCIÓN NO VÁLIDA\nElige una opción:\n";
            cout<<" 1. Ordenar datos de mayor a menor\n 2. Ordenar datos de menor a mayor\n 3. Desplegar los 10 datos más comúnes\n 4. Búsqueda por ip en un BST\n 5. Salir\n";
            cin >> input;
        }
       
        if (input == 1) {
            cout<<"Archivo creado con datos ordenados con un MaxHeap\n\n";

            /*Archivo de salida*/
            ofstream fileOutMaxHeapSort("output603-1.txt");
            // Ciclo for que escribe todos los registros ordenados en la DoublyLinkedList "logs" en el archivo output602-1.txt  
            int iter = logs.getSize();
            
            for (int i = 0; i < iter; i++) {
                if (i == iter-1) {
                    fileOutMaxHeapSort << logs.top().month << " " << logs.top().day  << " "<< logs.top().year<< " " << logs.top().time<< " " << logs.top().ip<< " " << logs.top().message;
                }
                else {
                    fileOutMaxHeapSort << logs.top().month << " " << logs.top().day  << " "<< logs.top().year<< " " << logs.top().time<< " " << logs.top().ip<< " " << logs.top().message << endl;  
                }
                logs.pop();      
            }

        }
        else if (input == 2) {
            cout<<"Archivo creado con datos ordenados con un MinHeap\n\n";

            ofstream fileOutMinHeapSort("output603-2.txt");
            int iter2 = logs_mH.getSize();

            for (int i = 0; i < iter2; i++) {
                if (i == iter2-1) {
                    fileOutMinHeapSort << logs_mH.top().month << " " << logs_mH.top().day  << " "<< logs_mH.top().year<< " " << logs_mH.top().time<< " " << logs_mH.top().ip<< " " << logs_mH.top().message;
                }
                else {
                    fileOutMinHeapSort << logs_mH.top().month << " " << logs_mH.top().day  << " "<< logs_mH.top().year<< " " << logs_mH.top().time<< " " << logs_mH.top().ip<< " " << logs_mH.top().message << endl;  
                }
                logs_mH.pop();      
            }
        } else  if (input == 3) {

        } else if (input == 4) {
            cout<<"Ingrese una ip: ";
            string inputIP;
            cin >> inputIP;
            
        }

    }

    return 0;
}