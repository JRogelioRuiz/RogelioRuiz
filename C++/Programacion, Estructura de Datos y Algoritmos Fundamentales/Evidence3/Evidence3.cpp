/* 
Evidencia 3
Autor: José Rogelio Ruiz Martínez A00835536
Fecha: 29/10/2023

Descripción del Programa: 
- El programa lee un archivo de datos de errores con sus fechas  
- Da al usuario un menu de opciones donde puede ordenar los datos de mayor a menor (maxHeap) y menor a mayor (minHeap) y regresarlos
en un archivo, mostrar las 10 ips que se repiten más veces y encontrar la cantidad de veces que se repite una IP ingresada.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"

/*Función main con el menu y todas sus opciones*/
int main() {

    // Archivo de entrada
    ifstream fileIn("log603-3.txt");

    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year, month, day, time, ip, message;
    Heap<Log> logs;
    MinHeap<Log> logs_mH;
    BST<Log> logs_BST;
    Heap<Log> auxLogsHeap;
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    cout<<"Leyendo Registros: \n";
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
        logs_BST.insert(log);
        auxLogsHeap.push(log);
        // Incrementamos el contador de registros
        cont++;
    }

    int input = 1;

    while (input) {
        cout<<"Elige una opción:\n";
        cout<<" 1. Ordenar datos de mayor a menor\n 2. Ordenar datos de menor a mayor\n 3. Desplegar las 10 IPs más comúnes\n 4. Búsqueda por ip en un BST\n 5. Salir\n";
        cin >> input;
        while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
            cout<<"OPCIÓN NO VÁLIDA\n\nElige una opción:\n";
            cout<<" 1. Ordenar datos de mayor a menor\n 2. Ordenar datos de menor a mayor\n 3. Desplegar las 10 IPs más comúnes\n 4. Búsqueda por ip en un BST\n 5. Salir\n";
            cin >> input;
        }
       
        if (input == 1) {
            cout<<"Archivo creado con datos ordenados con un MaxHeap\n\n";

            ofstream fileOutMaxHeapSort("output603-1.txt");
              
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
            cout<<"Las 10 IPs más comunes son: \n";
            vector<string> mostCommonIPS(10, "null");
            vector<int> mostCommonIPSnumRepetitions(10,0);
            int currentIPRepetitions = 1;
            int iteraciones = auxLogsHeap.getSize();
            
            /*Ciclo for que itera en todas las posiciones de un MaxHeap con todos los registros, 
            contando cuantas veces se repite un IP sacado con el método pop() y checando en los vectores de las IPs
            que más se repiten, si la IP que se acaba de checar remplaza a otra en el top 10 de ips que más se repiten*/
            for (int i = 0; i < iteraciones; i++) {
                Log currentLog = auxLogsHeap.pop();
                int currentIPVal = currentLog.ipValue;
                
                if (!auxLogsHeap.isEmpty()) {
                    if (currentIPVal != auxLogsHeap.top().ipValue) {
                        
                        bool replacedAValue = false;
                        
                        for (int i = 0; i < mostCommonIPS.size(); i++) {
                            
                            if(!replacedAValue && currentIPRepetitions > mostCommonIPSnumRepetitions[i]) {
                            
                                string auxLogIP = mostCommonIPS[i];
                                int auxRepetitions = mostCommonIPSnumRepetitions[i];
                                
                                mostCommonIPSnumRepetitions[i] = currentIPRepetitions;
                                mostCommonIPS[i] = currentLog.ip;
                                
                                for (int j = i+1; j < mostCommonIPS.size(); j++ ) {
                                    if(auxRepetitions >= mostCommonIPSnumRepetitions[j]) {
                                        string auxLogIP2 = mostCommonIPS[j];
                                        int auxRepetitions2 = mostCommonIPSnumRepetitions[j];
                                        
                                        mostCommonIPS[j] = auxLogIP;
                                        mostCommonIPSnumRepetitions[j] = auxRepetitions;

                                        auxRepetitions = auxRepetitions2;
                                        auxLogIP = auxLogIP2;
                                    }
                                }
                                replacedAValue = true;
                            }
                        }
                        currentIPRepetitions = 1;
                        
                    } else {
                        currentIPRepetitions++;
                    }
                } else {
                    
                    bool replacedAValue = false;
                    
                    for (int i = 0; i < mostCommonIPS.size(); i++) {
                        
                        if(!replacedAValue && currentIPRepetitions > mostCommonIPSnumRepetitions[i]) {
                            
                            string auxLogIP = mostCommonIPS[i];
                            int auxRepetitions = mostCommonIPSnumRepetitions[i];
                            
                            mostCommonIPSnumRepetitions[i] = currentIPRepetitions;
                            mostCommonIPS[i] = currentLog.ip;

                            for (int j = i+1; j < mostCommonIPS.size(); j++ ) {
                                if(auxRepetitions >= mostCommonIPSnumRepetitions[j]) {
                                    string auxLogIP2 = mostCommonIPS[j];
                                    int auxRepetitions2 = mostCommonIPSnumRepetitions[j];
                                    
                                    mostCommonIPS[j] = auxLogIP;
                                    mostCommonIPSnumRepetitions[j] = auxRepetitions;

                                    auxRepetitions = auxRepetitions2;
                                    auxLogIP = auxLogIP2;
                                }
                            }
                            replacedAValue = true;
                        }
                    }
                    currentIPRepetitions = 1;
                }
            }

            cout<<"Orden      IP        No. Veces\n";
            for (int i = 0; i < mostCommonIPS.size(); i++){
                (i == 9) ? cout<<i+1<<".    "<<mostCommonIPS[i]<<"    "<<mostCommonIPSnumRepetitions[i]<<endl : cout<<i+1<<".     "<<mostCommonIPS[i]<<"    "<<mostCommonIPSnumRepetitions[i]<<endl;
            }
            cout<<"\nNota: las ips que se repiten el mismo número de veces se ordenan de mayor a menor"<<endl<<endl;

        } else if (input == 4) {
            cout<<"Busqueda en BST por IP: (ejemplo 10.14.125.2)\n Ingrese una IP: ";
            string laIP;
            cin>> laIP;
            Log logAux("2000", "Jan", "00", "00:00:00", laIP, "message");
            int numVeces = logs_BST.find(logAux);
            (numVeces) ? cout<<"\nCantidad de veces que se encuentra esta IP: "<<numVeces<<endl<<endl : cout<<"\nLa IP ingresada no se encuentra en los registros"<<endl<<endl;
        
        } else if (input == 5) {
            input = 0;
        }
    }

    return 0;
}