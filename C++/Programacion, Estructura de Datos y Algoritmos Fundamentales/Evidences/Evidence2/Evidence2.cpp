/* 
Evidencia 2
Autor: José Rogelio Ruiz Martínez A00835536
Fecha: 08/10/2023

Descripción del Programa: 
- El programa lee un archivo de datos de errores con sus fechas  
- Da al usuario un menu de opciones donde puede ordenar los datos por fecha, ordenar por IP, encontrar un rango de IPs o desplegar las ips por año y mes.
- Regresa archivos para las operaciones de ordenar datos por fecha, por IP y uno con el rango en orden ascendente y otro con el rango en orden descentente 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "DoublyLinkedList.h"
#include "Log.h"


int main() {

    // Archivo de entrada
    ifstream fileIn("log603-2.txt");

    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year, month, day, time, ip, message;
    DoublyLinkedList<Log> logs;
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
        
        logs.addLast(log);
        // Incrementamos el contador de registros
        cont++;
    }

    bool togglePrintResults = false;

    // Se inicializa el ciclo while con el Menu
    int input = 1;
    while (input) {
        // Se despliega el Menu
        cout<<"\nElige una opción: \n";
        cout<<"1. Ordenar datos por fecha y Hora\n2. Ordenar datos por ip, fecha y hora\n3. Búsqueda por rango de ip's\n4. Cantidades de Ips por año y mes\n5. Salir\n6. Desplegar Resultados en Terminal / Sólo regresar Archivos\n";
        
        // Se registra el input del usuario y se checa que sea válido
        cin >> input;
        while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6) {
            cout<<"\nOpcion no valida";
            cout<<"\nElige una opción: \n";
            cout<<"1. Ordenar datos por fecha y Hora\n2. Ordenar datos por ip, fecha y hora\n3. Búsqueda por rango de ip's\n4. Cantidades de Ips por año y mes\n5. Salir\n6. Desplegar Resultados en Terminal / Sólo regresar Archivos\n";
            cin>>input;
        }

        /*Condicionales que checan cada caso de input*/

        if (input == 1) {
            // Se despliega la opción elegida
            cout<<"Ordenando datos por fecha y hora:\n\n";
            // Se crea el archivo de salida
            ofstream fileOutOrdered("output602-1.txt"); /*CAMBIAR A .OUT*/
            // Se ordena la lista con el algoritmo Quick Sort
            logs.quickSort(0,logs.getSize()-1,0);

            // Ciclo for que escribe todos los registros ordenados en la DoublyLinkedList "logs" en el archivo output602-1.txt   
            for (int i = 0; i < logs.getSize(); i++) {
                if (i == logs.getSize()-1) {
                    fileOutOrdered << logs[i]; 
                }
                else {
                    fileOutOrdered << logs[i] << endl; 
                }         
            }
            if (togglePrintResults) logs.print(); 
        } else if (input == 2) {
            /*Ordenar datos por ip fecha y hora*/
            cout<<"Ordenando datos por IP, fecha y hora:\n\n";
            /*Archivo de salida*/
            ofstream fileOutOrdered("output602-2.txt"); 

            // Se ordena la lista con el algoritmo Quick Sort
            logs.quickSort(0,logs.getSize()-1,1);

            // Ciclo for que escribe todos los registros ordenados en la DoublyLinkedList "logs" en el archivo output602-1.txt  
            for (int i = 0; i < logs.getSize(); i++) {
                if (i == logs.getSize()-1) {
                    fileOutOrdered << logs[i];
                }
                else {
                    fileOutOrdered << logs[i] << endl;  
                }         
            }
            if (togglePrintResults) logs.print();

        } else if (input == 3) {
            /*Búsqueda de rangos por ip con el algoritmo de búsqueda secuencial*/
            
            //Se pide el rango
            cout<<"Busqueda de Rangos por IP: (ejemplo 10.14.125.2)\n Ingrese el límite inferior: ";
            string ipInferior;
            cin>>ipInferior;
            cout<<" Ingrese el límite Superior: ";
            string ipSuperior;
            cin>>ipSuperior;
            
            // Se obtiene el valor de la IP como entero 
            Log LogAux1;
            Log LogAux2;
            LogAux1.ip = ipInferior;
            LogAux2.ip = ipSuperior; 
            int IP_Inferior = LogAux1.getIPValue();
            int IP_Superior = LogAux2.getIPValue();

            // Se crea una lista doblemente encadenada para guartar los datos
            DoublyLinkedList<Log> listaIPs; 

            // Se crean los archivos de salida
            ofstream file_IP_Range_Ascending("iprange602-a.txt"); 
            ofstream file_IP_Range_Descending("iprange602-d.txt"); 
            
            //Ciclo que itera en la lista "logs" y guarda los datos que estén dentro del rango en la lista "listaIPs" 
            for (int i = 0; i < logs.getSize(); i++) {
                if (logs[i].getIPValue() >= IP_Inferior && logs[i].getIPValue() <= IP_Superior) {
                    listaIPs.addLast(logs[i]);   
                }
            } 

            // Se ordena de modo ascendente la listaIPs
            listaIPs.quickSort(0,listaIPs.getSize()-1,1);

            if (togglePrintResults) cout<<"\nIPs en Orden Ascendente: \n\n";
            // Se guarda en el archivo de salida y se despliega en la pantalla
            for (int i = 0; i < listaIPs.getSize(); i++) {
                file_IP_Range_Ascending << listaIPs[i] << endl;  
            }    
            if (togglePrintResults) listaIPs.print();
            
            if (togglePrintResults) cout<<"\nIPs en Orden Descendente: \n\n";
            // Se despliega, ordena de modo descendente y se guarda en un archivo la listaIPS  
            for (int i = listaIPs.getSize()-1; i >= 0 ; i--) {
                file_IP_Range_Descending << listaIPs[i] << endl; 
                if (togglePrintResults) cout<<listaIPs[i] << endl;    
            } 



        } else if (input == 4) {
            /*Desplegar en pantalla la cantidad de ips en el archivo por cada año y mes*/
            
            // Variables enteras para cada año y mes
            int IPS_2022_Total = 0, IPS_2022_Jan = 0, IPS_2022_Feb = 0, IPS_2022_Mar = 0, IPS_2022_Apr = 0, IPS_2022_May = 0, IPS_2022_Jun = 0,  IPS_2022_Jul = 0,  IPS_2022_Aug = 0,  IPS_2022_Sep = 0,  IPS_2022_Oct = 0,  IPS_2022_Nov = 0,  IPS_2022_Dec = 0;
            int IPS_2023_Total = 0, IPS_2023_Jan = 0, IPS_2023_Feb = 0, IPS_2023_Mar = 0, IPS_2023_Apr = 0, IPS_2023_May = 0, IPS_2023_Jun = 0,  IPS_2023_Jul = 0,  IPS_2023_Aug = 0,  IPS_2023_Sep = 0,  IPS_2023_Oct = 0,  IPS_2023_Nov = 0,  IPS_2023_Dec = 0;         
            
            // Ciclo que itera en toda la lista "logs" y va checando el valor del año y mes para cada registro, para aumentar su contador correspondiente
            for (int i = 0; i < logs.getSize(); i++) {
                if (logs[i].yearValue == 2022) {
                    IPS_2022_Total++;
                    if      (logs[i].month == "Jan") {IPS_2022_Jan++;} 
                    else if (logs[i].month == "Feb") {IPS_2022_Feb++;}
                    else if (logs[i].month == "Mar") {IPS_2022_Mar++;} 
                    else if (logs[i].month == "Apr") {IPS_2022_Apr++;} 
                    else if (logs[i].month == "May") {IPS_2022_May++;} 
                    else if (logs[i].month == "Jun") {IPS_2022_Jun++;} 
                    else if (logs[i].month == "Jul") {IPS_2022_Jul++;} 
                    else if (logs[i].month == "Aug") {IPS_2022_Aug++;} 
                    else if (logs[i].month == "Sep") {IPS_2022_Sep++;} 
                    else if (logs[i].month == "Oct") {IPS_2022_Oct++;} 
                    else if (logs[i].month == "Nov") {IPS_2022_Nov++;} 
                    else if (logs[i].month == "Dec") {IPS_2022_Dec++;}
                }
                else if (logs[i].yearValue == 2023) {
                    IPS_2023_Total++;
                    if      (logs[i].month == "Jan") {IPS_2023_Jan++;} 
                    else if (logs[i].month == "Feb") {IPS_2023_Feb++;}
                    else if (logs[i].month == "Mar") {IPS_2023_Mar++;} 
                    else if (logs[i].month == "Apr") {IPS_2023_Apr++;} 
                    else if (logs[i].month == "May") {IPS_2023_May++;} 
                    else if (logs[i].month == "Jun") {IPS_2023_Jun++;} 
                    else if (logs[i].month == "Jul") {IPS_2023_Jul++;} 
                    else if (logs[i].month == "Aug") {IPS_2023_Aug++;} 
                    else if (logs[i].month == "Sep") {IPS_2023_Sep++;} 
                    else if (logs[i].month == "Oct") {IPS_2023_Oct++;} 
                    else if (logs[i].month == "Nov") {IPS_2023_Nov++;} 
                    else if (logs[i].month == "Dec") {IPS_2023_Dec++;}
                }
            }

            // Se despliegan las cantidades de manera ordenada
            cout<<"Cantidad de IPs por AÑO y MES: \n";
            cout<<" IPS 2022: " << IPS_2022_Total << endl;
            cout<<"  IPS Jan: " << IPS_2022_Jan << endl << "  IPS Feb: " << IPS_2022_Feb << endl << "  IPS Mar: " << IPS_2022_Mar << endl << "  IPS Apr: " << IPS_2022_Apr << endl;
            cout<<"  IPS May: " << IPS_2022_May << endl << "  IPS Jun: " << IPS_2022_Jun << endl << "  IPS Jul: " << IPS_2022_Jul << endl << "  IPS Aug: " << IPS_2022_Aug << endl;
            cout<<"  IPS Sep: " << IPS_2022_Sep << endl << "  IPS Oct: " << IPS_2022_Oct << endl << "  IPS Nov: " << IPS_2022_Nov << endl << "  IPS Dec: " << IPS_2022_Dec << endl<< endl;

            cout<<" IPS 2023: " << IPS_2023_Total << endl;
            cout<<"  IPS Jan: " << IPS_2023_Jan << endl << "  IPS Feb: " << IPS_2023_Feb << endl << "  IPS Mar: " << IPS_2023_Mar << endl << "  IPS Apr: " << IPS_2023_Apr << endl;
            cout<<"  IPS May: " << IPS_2023_May << endl << "  IPS Jun: " << IPS_2023_Jun << endl << "  IPS Jul: " << IPS_2023_Jul << endl << "  IPS Aug: " << IPS_2023_Aug << endl;
            cout<<"  IPS Sep: " << IPS_2023_Sep << endl << "  IPS Oct: " << IPS_2023_Oct << endl << "  IPS Nov: " << IPS_2023_Nov << endl << "  IPS Dec: " << IPS_2023_Dec << endl;
            

        } else if (input == 5) {

            // Se iguala a 0 la variable de control del ciclo while para salir del programa
            input = 0;
        } else if (input == 6) {
            /*Esta opción fue agregada arbitrariamente*/

            // Si la variable que controla si se imprimen los resultados es verdadera, se hace falsa, si es falsa se hace verdadera
            (togglePrintResults) ? togglePrintResults = false : togglePrintResults = true;
        }
    }

}