#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "GraphC.h"
#include "HashCiudades.h"


int main() {

    HashCiudades vertices;
    vertices.insert("A");
    vertices.insert("B");
    vertices.insert("C");
    vertices.insert("D");
    vertices.insert("E");
    vector< EdgeC<string> > edges;
    edges.emplace_back("A","B",1,1,1,1);
    edges.emplace_back("B","A",2,2,2,2);
    edges.emplace_back("A","C",3,3,3,3);
    edges.emplace_back("C","A",4,4,4,4);
    edges.emplace_back("A","E",5,5,5,5);
    edges.emplace_back("E","A",6,6,6,6);
    edges.emplace_back("B","D",7,7,7,7);
    edges.emplace_back("D","B",8,8,8,8);
    edges.emplace_back("C","D",9,9,9,9);
    edges.emplace_back("D","C",10,10,10,10);
    edges.emplace_back("E","D",11,11,11,11);
    edges.emplace_back("D","E",12,12,12,12);

    // GraphM<string> graphM(vertices, edges);
    GraphC<string> graph(vertices, edges);

    string enter;
    int input = 1;
    bool useListaDeAdyacencias = true;

    while (input) {
        cout<<"Elige una opción a realizar con el Graph";
        cout<<" de strings:\n 1. Add Vertex\n 2. Add Edge\n 3. Remove Vertex\n 4. Remove Edge\n 5. Print\n 6. DFS Traversal\n 7. BFS Traversal\n 8. Use Dijkstra\n 0. Salir\n";
        cout<<"Grafo actual:\n";
        graph.print();
        cout<<endl;
        cin>>input;
        getline(cin,enter);
        while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7 && input != 8) {
            cout<<"\nOPCIÓN NO VÁLIDA\n";
            cout<<"Elige una opción a realizar con el Graph";
            cout<<" de strings:\n 1. Add Vertex\n 2. Add Edge\n 3. Remove Vertex\n 4. Remove Edge\n 5. Print\n 6. DFS Traversal\n 7. BFS Traversal\n 8. Use Dijkstra\n 0. Salir\n";
            cout<<"Grafo actual:\n";
            graph.print();
            cout<<endl;
            cin>>input;
            getline(cin,enter);
        }
        if (input == 1) {
            cout<<"Ingrese el Valor del Vértice que quiere añadir:\n";
            string inputStr;
            getline(cin,inputStr);
            graph.addVertex(inputStr);
            cout<<endl<<endl;

        } else if (input == 2) {
            cout<<"Ingrese los valores de Punto de Inicio, Destino y Peso para el Arco que quiere añadir:\n";
            string source, target;
            int peso;
            cout<<"Punto de inicio: ";
            getline(cin, source);
            cout<<endl;
            cout<<"Destino: ";
            getline(cin, target);
            cout<<endl;
            cout<<"Peso: ";
            cin>>peso;
            cout<<endl;

            EdgeC<string> addedEdge(source,target,peso,1,1,1);
            graph.addEdge(addedEdge);
            cout<<endl<<endl;

        } else if (input == 3) {
            cout<<"Ingrese el Valor del Vértice que quiere eliminar:\n";
            string input;
            cin>>input;
            graph.removeVertex(input);  
            cout<<endl<<endl;

        } else if (input == 4) {
            cout<<"Ingrese los valores de Punto de Inicio, Destino y Peso para el Arco que quiere Eliminar:\n";
            string source, target;
            int peso;
            cout<<"Punto de inicio: ";
            cin>>source;
            cout<<endl;
            cout<<"Destino: ";
            cin>>target;
            cout<<endl;
            cout<<"Peso: ";
            cin>>peso;
            cout<<endl;
            
            // Edge<string> removedEdge(source,target,peso);
            // graph.removeEdge(removedEdge); 
            cout<<endl<<endl;

        } else if (input == 5) {
            cout<<"Grafo actual:\n";
            graph.print();
            cout<<endl<<endl;
            
        } else if (input == 6) {
            cout<<"Ingrese el vértice donde quiere empezar el DFS Traversal:\n";
            string input;
            cin>>input;
            graph.DFS(input);
            cout<<endl<<endl;
        } else if (input == 7) {
            cout<<"Ingrese el vértice donde quiere empezar el BFS Traversal:\n";
            string input;
            cin>>input;
            graph.BFS(input);
            cout<<endl<<endl;
        } else if (input == 8) {
            cout<<"Ingrese el vértice donde quiere utilizar el algoritmo Dijkstra:\n";
            string source, target;
            cout<<"Punto de inicio: ";
            getline(cin, source);
            cout<<endl;
            cout<<"Destino: ";
            getline(cin, target);
            cout<<endl;
            cout<<"Se imprimen los vértices en orden y el costo total después de un guión:\n Train\n";
            graph.dijkstra(source, target, 1);
            cout<<endl<<" Car\n";
            graph.dijkstra(source, target, 0);
            cout<<endl<<endl;
        }

    }

    return 0;
}