#ifndef GraphC_h
#define GraphC_h

#include "EdgeCiudad.h"
#include "Queue.h"
#include "HashCiudades.h"
#include <stack>
#include <algorithm>

template <class T>
class GraphC {
private:
    HashCiudades vertices;
    vector< vector< EdgeC<T> > > adjacencyList;
    int findVertex(T vertex);
    int findEdge(EdgeC<T> edge);
    void DFSR(T vertex, vector<bool> &status, ofstream& dfsTraversal);
    void DFSR(T vertex, vector<bool> &status);
    int findSmallest(vector<bool> &status, vector<int> &cost);
public:    
    GraphC();
    GraphC(HashCiudades vertices, vector< EdgeC<T> > edges);
    void addVertex(T vertex);
    void addEdge(EdgeC<T> edge);
    void removeVertex(T vertex);
    void removeEdge(EdgeC<T> edge);
    void BFS(T vertex, ofstream& bfsTraversal);
    void BFS(T vertex);
    void print(ofstream& listaDeAdyacencias);
    void print();
    void DFS(T vertex, ofstream& dfsTraversal);
    void DFS(T vertex);
    void dijkstra(T vertex, T LeTarget, bool TrueIfTrain);
};

template <class T>
GraphC<T>::GraphC() {
    

}

/*Constructor de la clase Graph C que recibe una HashTable con las ciudades (vértices) 
y una matriz de edges con las conexiones entres las ciudades*/
template <class T>
GraphC<T>::GraphC(HashCiudades vertices, vector< EdgeC<T> > edges) {
    // Actualizar la lista de vertices con los vertices que recibimos de parámetro
    this->vertices = vertices;
    // inicializamos la lista de adyacencias 
    adjacencyList.resize(vertices.getSize());

    // Iteramos la lista de adyacencias
    for (auto edge : edges) {
        // Encontramos el índice en la lista de vértices del vértice origen
        int sourceIndex = findVertex(edge.sourceCity);
        // Encontramos el índice en la lista de vértices del vértice destino
        int targetIndex = findVertex(edge.targetCity);
        // Actualizamos en verdadero en la matriz en el renglon del indice origen y en la columna del indice destino
        if (sourceIndex != -1 && targetIndex != -1) {
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}

/*Método de la clase GraphC que recibe un vértice del grafo y regresa el índice de la hashtable en la cuál se encuentra*/
template <class T>
int GraphC<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.table.begin(), vertices.table.end(), vertex);

    if (it != vertices.table.end()) {
        return it - vertices.table.begin();
    } else {
        return -1;
    }
}

/*Método de la clase GraphC que recibe un arco del grafo y regresa el índice del arco en en el vector en la posición del vértice
 de origen en la matriz, es decir, donde edge = adjacencylist[edge.source][posiciónRegresada]*/
template <class T>
int GraphC<T>::findEdge(EdgeC<T> edge) {
    int sourceIndex = findVertex(edge.sourceCity);
    typename vector<EdgeC<T>>::iterator it;
    it = find(adjacencyList[sourceIndex].begin(), adjacencyList[sourceIndex].end(), edge);
    if (it != adjacencyList[sourceIndex].end()) {
        return it - adjacencyList[sourceIndex].begin();
    } else {
        return -1;
    }
}

/*Método de la clase GraphC que recibe un valor de un vértice y lo agrega al grafo*/
template <class T>
void GraphC<T>::addVertex(T vertex) {
    // Buscar si ya existe el valor a agregar
    int vertexIndex = findVertex(vertex);
    // si no existe se agrega a la lista de vértices
    if(vertexIndex == -1) {
        // se agrega a la lista de vértices
        vertices.insert(vertex);
        // se agrega a la lista de adyacencias
        vector<EdgeC<T>> emptyEdges;
        adjacencyList.push_back(emptyEdges);
        cout<<"Vértice Agregado!\n";
    } else {
        // Vertex ya existe
        throw invalid_argument("Vértice ya existe");
    }
}

/*Método de la clase GraphC que recibe un valor de un edge y lo agrega al grafo*/
template <class T>
void GraphC<T>::addEdge(EdgeC<T> edge) { 
    // Validar que los vértices origen y destino existan
    int sourceIndex = findVertex(edge.sourceCity);
    int targetIndex = findVertex(edge.targetCity);
    if (sourceIndex != -1 && targetIndex != -1) {    
        for (auto neighbor : adjacencyList[sourceIndex]) {
            // Validar que el edge no se encuentre ya en la lista de adyacencias
            if (neighbor.targetCity == edge.targetCity) {
                throw invalid_argument("El arco ya existe");
            }
        }
        // Agregar el edge a la lista de adyacencias
        adjacencyList[sourceIndex].push_back(edge);
        cout<<"Edge Agregado!\n";
    } else {
        throw invalid_argument("Alguno de los vértices no existe");
    }

}

/*Método de la clase GraphC que recibe un valor de un vértice, revisa si existe, 
si sí, lo elimina del grafo*/
template <class T>
void GraphC<T>::removeVertex(T vertex) {
    // Checar si existe el vértice
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        //CHECAR EN TODAS LAS DEMAS POSICIONES DE LA ADJACENCY LIST SI EXISTE EL VERTICE como TARGET
        for (auto vEdgesList : adjacencyList) {
            for (auto edge : vEdgesList) {
                if (edge.targetCity == vertex) {
                    removeEdge(edge);
                }
            }
        }
        vertices.remove(vertex);
        adjacencyList.erase(adjacencyList.begin()+vertexIndex);
        cout<<"Vértice Elimnado\n";
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

/*Método de la clase GraphC que recibe un valor de un edge, revisa si existe, 
si sí, lo elimina del grafo*/
template <class T>
void GraphC<T>::removeEdge(EdgeC<T> edge) {
    // Buscar si ya existe el vertice source
    int sourceVertexIndex = findVertex(edge.sourceCity);
    // Checar si existe el edge
    int posInAdyacencyList = findEdge(edge);

    // si no existe se agrega a la lista de vértices
    if(sourceVertexIndex != -1 && posInAdyacencyList != -1) {
        adjacencyList[sourceVertexIndex].erase(remove(adjacencyList[sourceVertexIndex].begin(), adjacencyList[sourceVertexIndex].end(), edge), adjacencyList[sourceVertexIndex].end());
        cout<<"Edge Elimnado\n"; 
    } else
    throw invalid_argument("El arco o vértice no existe");
}

/*Sobrecarga del Método BFS de la clase GraphC que recibe un valor de un vértice y una dirección de archivo ofstream 
para escribir el recorrido BFS en el archivo*/
template <class T>
void GraphC<T>::BFS(T vertex, ofstream& bfsTraversal) {
    // validamos que el vértice de inicio exista
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        //creamos una fila de tipo int que va a guardar los índices de los vértices por visitar
        Queue<int> bfsQueue;
        // creamos una lista de estado inicializada con la cantidad de vértices en falso
        vector<bool> status(vertices.getSize(), false);
        // Agregamos el índice del vértice de inicio a la fila
        bfsQueue.push(vertexIndex);
        // Cambiamos su estado a verdadero
        status[vertexIndex] = true;
        
        // Mientras la fila no esté vacía
        while(!bfsQueue.isEmpty()) {            
            // Recorremos los vecinos del primer elemento de la fila
            for (auto neighbor : adjacencyList[bfsQueue.getFront()]) {
                // Obtenemos el índice del target
                int targetIndex = findVertex(neighbor.targetCity);
                // Validamos si el estado es falso
                if (!status[targetIndex]) {
                    // Agregamos el vertice al queue
                    bfsQueue.push(targetIndex);
                    // Cambiamos su estatus a verdadero
                    status[targetIndex] = true;
                }
            }
            bfsTraversal<<vertices.getCiudad(bfsQueue.getFront())<< " ";
            bfsQueue.pop();
        }
        cout << endl;
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

/*Sobrecarga del Método BFS de la clase GraphC que recibe un valor de un vértice y 
despliega el recorrido BFS en la pantalla*/
template <class T>
void GraphC<T>::BFS(T vertex) {
    // validamos que el vértice de inicio exista
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        //creamos una fila de tipo int que va a guardar los índices de los vértices por visitar
        Queue<int> bfsQueue;
        // creamos una lista de estado inicializada con la cantidad de vértices en falso
        vector<bool> status(vertices.getSize(), false);
        // Agregamos el índice del vértice de inicio a la fila
        bfsQueue.push(vertexIndex);
        // Cambiamos su estado a verdadero
        status[vertexIndex] = true;
        
        // Mientras la fila no esté vacía
        while(!bfsQueue.isEmpty()) {            
            // Recorremos los vecinos del primer elemento de la fila
            for (auto neighbor : adjacencyList[bfsQueue.getFront()]) {
                // Obtenemos el índice del target
                int targetIndex = findVertex(neighbor.targetCity);
                // Validamos si el estado es falso
                if (!status[targetIndex]) {
                    // Agregamos el vertice al queue
                    bfsQueue.push(targetIndex);
                    // Cambiamos su estatus a verdadero
                    status[targetIndex] = true;
                }
            }
            cout<<vertices.getCiudad(bfsQueue.getFront())<< " ";
            bfsQueue.pop();
        }
        cout << endl;
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

/*Sobrecarga del Método DFSR de la clase GraphC que recibe un valor de un vértice, un vector booleano que 
representa el estatus de los vértices y una dirección de archivo ofstream para obtener 
recursivamente el recorrido DFS y escribirlo en el archivo*/
template <class T>
void GraphC<T>::DFSR(T vertex, vector<bool> &status, ofstream& dfsTraversal) {
    // Visitamos el vértice
    dfsTraversal << vertex << " ";
    // Buscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Actualizamos su estado
    status[vertexIndex] = true;
    // Recorremos todos sus vecinos
    for (auto neighbor : adjacencyList[vertexIndex]) {
        // Obtenemos el índice del vecino
        int neighborIndex = findVertex(neighbor.targetCity);
        // Validamos su estado
        if (!status[neighborIndex]) {
            // Llamamos al dfsr
            DFSR(neighbor.targetCity, status, dfsTraversal);
        }
    }
}

/*Sobrecarga del Método DFS de la clase GraphC que recibe un valor de un vértice, un vector booleano que 
representa el estatus de los vértices y una dirección de archivo ofstream para llamar al metodo DFSR que 
obtendrá el recorrido DFS recursivamente, y lo escribirá en el archivo*/
template <class T>
void GraphC<T>::DFS(T vertex, ofstream& dfsTraversal) {
    // Validamos si el vértice existe
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos una lista de estado del tamaño de la cantidad de vértices inicializado en falso
        vector<bool> status(vertices.getSize(), false);
        // Llamamos a la función de recursividad
        DFSR(vertex, status, dfsTraversal);
    } else {
        throw invalid_argument("Vértice inválido");
    }
}

/*Sobrecarga del Método DFSR de la clase GraphC que recibe un valor de un vértice y un vector booleano que 
representa el estatus de los vértices para obtener recursivamente el recorrido DFS y desplegarlo en la pantalla*/
template <class T>
void GraphC<T>::DFSR(T vertex, vector<bool> &status) {
    // Visitamos el vértice
    cout << vertex << " ";
    // Buscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Actualizamos su estado
    status[vertexIndex] = true;
    // Recorremos todos sus vecinos
    for (auto neighbor : adjacencyList[vertexIndex]) {
        // Obtenemos el índice del vecino
        int neighborIndex = findVertex(neighbor.targetCity);
        // Validamos su estado
        if (!status[neighborIndex]) {
            // Llamamos al dfsr
            DFSR(neighbor.targetCity, status);
        }
    }
}

/*Sobrecarga del Método DFS de la clase GraphC que recibe un valor de un vértice y un vector booleano que 
representa el estatus de los vértices para llamar al metodo DFSR que obtendrá el recorrido DFS recursivamente,
y lo desplegará en la pantalla*/
template <class T>
void GraphC<T>::DFS(T vertex) {
    // Validamos si el vértice existe
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos una lista de estado del tamaño de la cantidad de vértices inicializado en falso
        vector<bool> status(vertices.getSize(), false);
        // Llamamos a la función de recursividad
        DFSR(vertex, status);
    } else {
        throw invalid_argument("Vértice inválido");
    }
}

/*Método de la clase GraphC que recibe una dirección de un vector de booleanos que representa el estatus de los vértices
en el algoritmo dijkstra y otro con los costos, regresa el indice del vértice con el menor costo cuyo estatus es False*/
template<class T>
int GraphC<T>::findSmallest(vector<bool> &status, vector<int> &cost) {
    //inicializamos una variable en -1 para guardar el índice del costo más pequeño
    int smallestIndex = -1;
    //inicializamos una variable para determinar cuáll fue el costo más pequeño
    int smallestCost = INT_MAX;
    //Iteramos en todos los vértices para obtener el más pequeño
    for (int i = 0; i < vertices.getSize(); i++) {
        //Validamos quue eel estatus del vértice actual sea falso 
        //Y comparamos si el costo del vértice actual es menor al costo más pequeño
        if (!status[i] && cost[i] < smallestCost) {
            //Si ambos son ciertos, actualizamos las variables
            smallestIndex = i;
            smallestCost = cost[i];
        } 
    }
    return smallestIndex;
}

/*Método de la clase GraphC que recibe un vector de origen, un vector de fin y un booleano que indica si se está checando
la ruta más corta por Tren o no (carro), y aplica el algoritmo Dijkstra para obtener la ruta más corta entre los dos vertices
y desplegarla junto con su costo final*/
template <class T>
void GraphC<T>::dijkstra(T vertex, T LeTarget, bool TrueIfTrain) {
    int vertexIndex = findVertex(vertex);
    int TargetIndex = findVertex(LeTarget);
    if (vertexIndex != -1 && TargetIndex != -1) {
        //Creamos la tabla de estados
        vector<bool> status(vertices.getSize(), false);
        //Creamos la tabla de costos
        vector<int> cost(vertices.getSize(), INT_MAX);
        //Creamos la tabla de Path
        vector<int> path(vertices.getSize(), -1);
        //Actualizamos el costo en 0 de vértice inicio
        cost[vertexIndex] = 0;
        //Creamos una variable para guuardar cual fue el vértice más peqeño de los que tienen estado en also
        int shortestIndex = vertexIndex;

        //Iteramos mientras exista un vértice con estado en falso
        while (shortestIndex != -1) {
            //Actualizamos el estado del ShortestIndex
            status[shortestIndex] = true;
            // recorremos los vecinos del shortestIndex
            for (auto neighbor : adjacencyList[shortestIndex]) {
                //buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.targetCity);
                // validamos que el estado del vecino sea falso
                if(!status[neighborIndex]) {
                    if (TrueIfTrain) {
                        //validamos si el costoo del vecino sea mayor que el costo del shortest index más el peso del vecino
                        if(cost[neighborIndex]>cost[shortestIndex]+neighbor.TrainDistance){
                            //actualiza el costo del vecino
                            cost[neighborIndex] = cost[shortestIndex]+neighbor.TrainDistance;
                            //Se actualiza el path al vecino
                            path[neighborIndex] = shortestIndex;
                        }
                    } else {
                        //validamos si el costoo del vecino sea mayor que el costo del shortest index más el peso del vecino
                        if(cost[neighborIndex]>cost[shortestIndex]+neighbor.CarDistance){
                            //actualiza el costo del vecino
                            cost[neighborIndex] = cost[shortestIndex]+neighbor.CarDistance;
                            //Se actualiza el path al vecino
                            path[neighborIndex] = shortestIndex;
                        }
                    }
                }
            }
            //Actualizamos el valor de shortest Index
            shortestIndex = findSmallest(status, cost);
        }
        
        // Seguimos con el  proceso de actualizar la lista de pilas
        //Inicializamos una lista de pilas vacías
        vector<stack<int>> shortestPaths(vertices.getSize());
        //Recorremos todos los vértices
        for(int i = 0; i < vertices.getSize(); i++) {
            //Agregamos a la pila del vértice actual su índice
            shortestPaths[i].push(i);
            //Creamos una variable para guardar el índice del path
            int pathIndex = path[i];
            // Iteramoos mientras pathIndex sea diferente de -1
            while (pathIndex != -1) {
                //Agregamos el path index a la pila
                shortestPaths[i].push(pathIndex);
                //Actualizamos el path index con el valor del path de path index
                pathIndex = path[pathIndex];
            } 
        }
        //Imprimimos el resultado
        //Iteramos todos los vértices
        for(int i = 0; i < vertices.getSize(); i++){
            if (vertices.getCiudad(i) == LeTarget) {
                cout<<vertex<<"->"<<LeTarget<<": ";
                //Validamos que la pila no sea vacía o que el costo  no sea infinito
                if (cost[i] != INT_MAX){
                    //Iteramos mientras la pila no sea vacía
                    while(!shortestPaths[i].empty()) {
                        //Imprimimos el primer elemeto de la pila
                        cout<<vertices.getCiudad(shortestPaths[i].top()) << " ";
                        //Sacamos el primer elemento de la pila
                        shortestPaths[i].pop();
                    }

                cout<<" - "<<cost[i]<<" Kilometros"<<endl;


                } else {
                    cout<<"No hay ruta\n";
                }
            }
        }

    } else {
        throw invalid_argument("Alguna de las ciudades no existe");
    }
}

/*Sobrecarga del Método print de la clase GraphC que recibe una dirección de archivo ofstream 
y escribe en el la lista de adyacencias del grafo*/
template <class T>
void GraphC<T>::print(ofstream& listaDeAdyacencias) {
    for (int i=0; i<vertices.getSize(); i++) {
        listaDeAdyacencias << i<< " " <<vertices.getCiudad(i) << " - ";
        for (int j = 0;  j < adjacencyList[i].size(); j++) {
            if (j < adjacencyList[i].size()-1)
                listaDeAdyacencias<< adjacencyList[i][j].targetCity << " " << adjacencyList[i][j].weight<< " - "; 
            else 
                listaDeAdyacencias<< adjacencyList[i][j].targetCity << " " << adjacencyList[i][j].weight;
        }
        listaDeAdyacencias << endl;
    }
}

/*Sobrecarga del Método print de la clase GraphC que despiega en la pantalla la lista de adyacencias del grafo*/
template <class T>
void GraphC<T>::print() {
    for (int i=0; i<vertices.getSize(); i++) {
        cout << i<< " " <<vertices.getCiudad(i) << " - ";
        for (int j = 0;  j < adjacencyList[i].size(); j++) {
            if (j < adjacencyList[i].size()-1)
                cout<< adjacencyList[i][j].targetCity << " " << adjacencyList[i][j].weight<< " - "; 
            else 
                cout<< adjacencyList[i][j].targetCity << " " << adjacencyList[i][j].weight;
        }
        cout << endl;
    }
}

#endif