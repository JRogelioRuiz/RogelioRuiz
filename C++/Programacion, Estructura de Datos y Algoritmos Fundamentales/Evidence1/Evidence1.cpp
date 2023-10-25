/* 
Evidencia 1
Autor: José Rogelio Ruiz Martínez A00835536
Fecha: 10/09/2023

Descripción del Programa: 
- El programa lee un archivo de datos de errores con sus fechas  
- Regresa otro archivo con los datos ordenados utilizando el algoritmo Quick Sort
- Pide al usuario un rango de fechas, luego lo despliega en la pantalla y regresa otro archivo con solo esos datos 

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"

/*Función para intercambiar dos posiciones de una lista
    Recibe como argumentos la dirección de la lista y los índices a intercambiar
    No regresa nada porque la dirección de la lista original se modifica directamente 
*/
template<class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

/*Función de Búsqueda Binaria Modificada:
    recibe un vector y un dato tipo template como argumentos, y un boleano. 
        El Boleano determina si se quiere el siguiente número arriba 
        del dato buscado o si se quiere el de abajo, si no existiera el dato buscado. 
    si existe el dato, regresa el índice en el cuál se encuentra el valor en el vector.
    si no existe regresa el valor determinado por el boleano.
 */
template <class T>
int binarySearchModified (vector<T> list, T data, bool wantAboveNum) {
    
    int left = 0;
    int right = list.size()-1;
    int mid = 0;

    while (left<=right) {
        mid = left + (right - left) / 2;
        if (list[mid]==data) {
            return mid;
        } else if (list[mid] > data) {
            right = mid-1;
        } else if (list[mid] < data) {
            left = mid+1;
        }
    }
    
    if (wantAboveNum) {
        return left;
    } else {
        return right;
    }
}

/*Función de ordenamiento con algoritmo Quick Sort:
    la función recibe un vector de clase template y dos valores enteros que representan los índices 
    en los cuáles se va a realizar el algoritmo
    no tiene valor de retorno, porque se ordena la lista original
*/
template <class T> 
void quickSort(vector<T> &list, int left, int right) {  
    int aux = left-1;
    if (left < right) {
    // Ciclo for que itera desde left hasta right-1
    for (int index = left; index < right; index++) {
        // Se checa si el elemento en la posición del índice es menor a el pivote
        if (list[index] < list[right]) {
            // Si el elemento del índice es menor, se aumenta el índice auxiliar
            // y se intercambian el elemento del pivote con el del índice auxiliar 
            aux++; 
            swap(list, aux, index);
        }  
    }
    // Al final del ciclo for se aumenta 1 al auxiliar, y se intercambia con el pivote.
    aux++;
    swap(list, aux, right);

    // Se manda a llamar la función quicksort para ambos lados del pivote ya ordenado   
    // del lado izquierdo se llama con el left original, con el pivote menos 1.
    quickSort(list, left, aux-1);
    // del lado derecho se llama con el pivote +1 y el right original
    quickSort(list, aux+1, right);
    }
}


int main() {

    // Archivo de entrada
    ifstream fileIn("C:/Users/Prueba/OneDrive/Documentos/Universidad/3. Tercer Semestre/Programacion de Estructuras de Datos y Algoritmos Fundamentales/GitA00835536/C.MTY.TC1031.603.2313.A00835536/Evidences/Evidence1/log603.txt");
    // Archivo de salida con todos los registers ordenados
    ofstream fileOutOrdered("output603.txt");
    // Archivo de salida con el rango pedido
    ofstream fileOutRange("range603.txt");

    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year, month, day, time, ip, message;
    vector<Log> logs;
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
        
        logs.push_back(log);
        // Incrementamos el contador de registros
        cont++;
    }

    // Se ordena la lista con el algoritmo Quick Sort
    quickSort(logs,0,logs.size()-1);

    // Ciclo for que escribe todos los registros ordenados en el vector "logs" en el archivo output603.txt   
    for (int i = 0; i < logs.size(); i++) {
        if (i == logs.size()-1)
            fileOutOrdered << logs[i];
        else 
            fileOutOrdered << logs[i] << endl;            
    }

    // Se despliega la cantidad de registros 
    cout << "La cantidad de registros es: " << cont << endl;

    // Inicialización de variables string necesarias para pedir el rango 
    string lowerMonth, lowerDay, lowerYear, lowerHour, lowerMinute, lowerSecond;
    string upperMonth, upperDay, upperYear, upperTime, upperHour, upperMinute, upperSecond;

    // Se despliegan las instrucciones y se reciben los datos
    cout<<"Ingrese el rango de fechas que desea ver separando cada valor por un espacio: \n  Formato: Month Year Day Hour Minute Second\n  Ejemplo: Dec 01 2022 00 00 00\n\n";
    cout<<"Primera fecha: \n";
    cin >> lowerMonth >> lowerDay >> lowerYear>> lowerHour >> lowerMinute >> lowerSecond;

    cout<<"Segunda fecha: \n";
    cin>> upperMonth >> upperDay>> upperYear>> upperHour >> upperMinute >> upperSecond;

    // Se utilizan los datos para crear objetos Log, para poder utilizar los operadores de comparacion "<, >, =="
    Log lowerLog(lowerYear, lowerMonth, lowerDay,  lowerHour+":"+lowerMinute+":"+lowerSecond, "ip", "message");
    Log upperLog(upperYear, upperMonth, upperDay, upperHour+":"+upperMinute+":"+upperSecond, "ip", "message");    
    
    // Se obtienen los índices superior e inferior del rango pedido
    int lowerLogOrNextAboveIndex = binarySearchModified(logs,lowerLog,1);
    int upperLogOrNextBelowIndex = binarySearchModified(logs,upperLog,0);  

    // Ciclo for que escribe en el archivo range603.txt los registros del rango especificado, y los despliega en la pantalla
    for (int i = lowerLogOrNextAboveIndex; i <= upperLogOrNextBelowIndex; i++) {
        if (i != upperLogOrNextBelowIndex) {
        fileOutRange << logs[i] << endl; 
        }
        else {
        fileOutRange << logs[i];
        }
        cout << logs[i] << endl;
    } 

    return 0;

}