/* 
Evidencia 4
Autor: José Rogelio Ruiz Martínez A00835536
Fecha: 01/12/2023

Descripción del Programa: 
- El programa lee un archivo de datos de ciudades con distancias y tiempos para rutas por carro y por tren hacia otras ciudades  
- Da al usuario un menu de opciones donde puede ordenar en un archivo las ciudades alfabéticamente, regresar un archivo con la
lista de adyacencias del grafo de ciudades, recorrer el grafo por DFS y BFS y regresar la ruta más corta entre dos ciudades con el 
algoritmo Dijkstra
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "HashCiudades.h"
#include "GraphC.h"

using namespace std;

int main() {
    /*Se lee el archivo creando el grafo con los datos leídos a una matriz de edges y un hashtable de ciudades*/
    ifstream file;
    file.open("EuropeCities.csv");
    string line, word;
    int cont = 1;
    getline(file, line);
    vector< EdgeC<string> > edges;
    HashCiudades vertices;

    while (getline(file, line)) {
        stringstream s(line);
        string sourceCity, targetCity, TrainTime,TrainDistance,CarTime,CarDistance;
        while (getline(s, word, ',')) {
            if (cont == 1)  {
                sourceCity = word;
            } else if (cont == 2)  {
                targetCity = word;
            } else if (cont == 3)  {
                TrainTime = word;
            } else if (cont == 4)  {
                TrainDistance = word;
            } else if (cont == 5)  {
                CarTime = word;
            } else if (cont == 6)  {
                CarDistance = word;
            }
            cont++;
        }  
        int TrainTimeMinutes = 0, CarTimeMinutes = 0;
        if(TrainTime[1] == ':') {   
            TrainTimeMinutes += (TrainTime[0]-'0') * 60;
            TrainTimeMinutes += (TrainTime[2]-'0') * 10;
            TrainTimeMinutes += (TrainTime[3]-'0') * 1;
        } else {
            TrainTimeMinutes += (TrainTime[0]-'0') * 600;
            TrainTimeMinutes += (TrainTime[1]-'0') * 60;
            TrainTimeMinutes += (TrainTime[3]-'0') * 10;
            TrainTimeMinutes += (TrainTime[4]-'0') * 1;
        }

        if(CarTime[1] == ':') {   
            CarTimeMinutes += (CarTime[0]-'0') * 60;
            CarTimeMinutes += (CarTime[2]-'0') * 10;
            CarTimeMinutes += (CarTime[3]-'0') * 1;
        } else {
            CarTimeMinutes += (CarTime[0]-'0') * 600;
            CarTimeMinutes += (CarTime[1]-'0') * 60;
            CarTimeMinutes += (CarTime[3]-'0') * 10;
            CarTimeMinutes += (CarTime[4]-'0') * 1;
        }

        edges.emplace_back(sourceCity, targetCity, TrainTimeMinutes, stoi(TrainDistance), CarTimeMinutes, stoi(CarDistance));
        if (vertices.findCiudad(sourceCity) == -1) {
            vertices.insert(sourceCity);
        }
        cont = 1;
    }

    file.close();

    GraphC<string> graph(vertices, edges);

    string enter;

    int input = 1;
    
    while (input) {
        cout<<"ELIGE UNA OPCIÓN:\n 1. Ordenar Ciudades Alfabeticamente\n 2. Lista de adyacencias del Grafo\n 3. Recorrer Grafo\n 4. Ruta más corta entre 2 ciudades\n 5. Salir\n";
        cin>>input;
        getline(cin,enter);

        while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
            cout<<"OPCION NO VALIDA\nELIGE UNA OPCIÓN:\n 1. Ordenar Ciudades Alfabeticamente\n 2. Lista de adyacencias del Grafo\n 3. Recorrer Grafo\n 4. Ruta más corta entre 2 ciudades\n 5. Salir\n";
            cin>>input;
            getline(cin,enter);
        }

        if (input == 1) {
            ofstream quickSortCiudades("output603-1.txt");
            vertices.alphabeticalOrder(quickSortCiudades);
            cout<<"Archivo con las Ciudades ordenadas Alfabeticamente Creado\n";
            cout<<endl;

        } else if (input == 2) {
            ofstream listaDeAdyacencias("output603-2.txt");
            graph.print(listaDeAdyacencias);
            cout<<"Archivo con la lista de Adyacencias del Grafo Creado\n";
            cout<<endl;

        } else if (input == 3) {
            cout<<"Ingrese la ciudad de inicio:\n";
            string origin;
            getline(cin,origin);
            ofstream bfsTraversal("output603-3.txt");
            ofstream dfsTraversal("output603-4.txt");
            
            graph.DFS(origin, dfsTraversal);
            graph.BFS(origin, bfsTraversal);
            cout<<"Archivos con los Recorridos por DFS y BFS creados\n";
            cout<<endl;

        } else if (input == 4) {
            cout<<"Ingrese la ciudad de origen y de destino:\n";
            string origin;
            cout<<" Ciudad de Origen: ";
            getline(cin,origin);
            string destino;
            cout<<" Ciudad de Destino: ";
            getline(cin,destino);
            
            ofstream bfsTraversal("output603-3.txt");
            ofstream dfsTraversal("output603-4.txt");
            
            cout<<endl<<endl<<"Ruta más corta entre las ciudades por Tren:\n";
            graph.dijkstra(origin, destino,1);

            cout<<endl<<endl<<"Ruta más corta entre las ciudades por Carro:\n";
            graph.dijkstra(origin, destino,0);
            
            cout<<endl;

        } else if (input == 5) {
            //Se utiliza la variable de control del ciclo para terminar el programa
            input = 0;
        }


    }

    return 0;
}