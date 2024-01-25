#ifndef HashCiudades_h
#define HashCiudades_h

#include<vector>
#include<iostream>

using namespace std;

struct HashCiudades {
    private: 

    public:
        int insertedSize = 0;
        bool orderedAlphabeticaly = 0;
        vector<string> table;
        vector<string> AlphabeticalTable;
        vector<bool> status;
        HashCiudades();
        // HashCiudades(int (*hash) (string));
        void insert(string ciudad);
        void remove(string ciudad);
        int findCiudad(string ciudad);
        string getCiudad(int position);
        int hash(string ciudad);
        int getSize();
        void print();
        void alphabeticalOrder(ofstream& QuickSortCiudades);
        void QuickSort(vector<string> &list, int left, int right);
        void swap(vector<string> &list, int a, int b);
};

/*Constructor default de la clase HashCiudades que inicializa los tamaños de la tabla y el vector de estatus*/
HashCiudades::HashCiudades() {   
    table.resize(60);
    status.resize(60, false);
}

/*Función Hash de la clase HashCiudades que recibe un string que se quiere ingresar a la tabla, realiza una operación
arbitraria para crearle un índice y checa si este índice está ocupado, iterando hasta que se encuentre uno que no lo esté
para regresarlo*/
int HashCiudades::hash(string ciudad) {
    int position = 0; 
    int ciudadHash = ciudad[0] * 1000 + ciudad[ciudad.length()-1] * 100;
    position = (ciudadHash%100 + (ciudadHash/1000)%100)%table.size();
    
    int newPosition = position;
    while (newPosition != position && !table[newPosition].empty() && table[newPosition] != ciudad) {
        newPosition = (newPosition+1)%table.size();
    }
    return position;
}

/*Método de la clase HashCiudades que recibe un string que representa una ciudad como parámetro de entrada,
utiliza el método Hash para obtener la posición, y en caso de que no se encuentre en la posición dada por hash,
se itera en toda la tabla hasta darle la vuelta, si existe regresa su posición, si no regresa -1*/
int HashCiudades::findCiudad(string ciudad) {
    // Obtengo el índice de la función de hashing
    int index = hash(ciudad);
    if (table[index] == ciudad) {
        return index;
    } else {
        // Creamos un índice auxiliar para determinar si ya le dimos la vuelta
        int newIndex = (index + 1) % table.size();
        // Recorremos la tabla para buscar el elemento
        while (index != newIndex && (!table[index].empty() || status[index])) {
            // Validamos si el valor de la tabla en newIndex es igual al valor buscado
            if (table[newIndex] == ciudad) {
                // Regresamos newIndex
                return newIndex;
            }
            // Incrementamos el valor de newIndex
            newIndex = (newIndex + 1) % table.size();
        }
        // No lo encontré
        return -1;
    }
}

/*Método de la clase HashCiudades que recibe como parámetro un string que representa una ciudad que se
quiere insertar, se checa si existe, si no, se obtiene su posición con el método Hash y se inserta en la tabla*/
void HashCiudades::insert(string ciudad) {
    // Validar si existe el elemento
    if (findCiudad(ciudad) == -1) {
        if (insertedSize+1 >= table.size()) {
            table.resize(insertedSize+1);
            status.resize(insertedSize+1);
        }
        // Obtengo el índice de la función de hashing
        int index = hash(ciudad);
        // cout<<index<<endl;
        // Revisamos si el índice esta vacío
        if (table[index].empty()) {
            // insertamos el dato
            table[index] = ciudad;
            // Actualizamos el estado de newIndex
            status[index] = false;
            insertedSize++;
        } else {
            // Creamos un índice auxiliar para determinar si ya le dimos la vuelta
            int newIndex = (index + 1) % table.size();
            // Recorremos la tabla mientras no le demos la vuelta y el valor no sea vacío
            while (newIndex != index && !table[newIndex].empty()) {
                // Recorremos newIndex
                newIndex = (newIndex + 1) % table.size();
            }
            // Validamos que no le hayamos dado la vuelta a la tabla
            if (newIndex != index) {
                // insertamos el dato
                table[newIndex] = ciudad;
                // Actualizamos el estado de newIndex
                status[newIndex] = false;
                insertedSize++;
            } else {
                // Le dimos la vuelta a la tabla, es decir la tabla esta llena
                // cout<<ciudad<<table.size()<<endl;
                throw invalid_argument("La tabla esta llena");
            }
        }
    } else {
        throw invalid_argument("El valor ya se encuentra en la tabla");
    }     
}

/*Método de la clase HashCiudades que recibe como parámetro un string que representa una ciudad que se quiere eliminar,
se checa si existe, si sí se elimina de la tabla y se pone su estatus como borrado*/
void HashCiudades::remove(string ciudad) {
    int index = findCiudad(ciudad);
    if (index != -1) {
        // table[index] = "b";
        table[index] = "";
        status[index] = true;
        insertedSize--;
    } else {  
        throw invalid_argument("La matrícula no está en la Tabla\n"); 
    }
}

/*Método de la clase hash ciudades que itera en toda la tabla e imprime los valores y posiciones que no estén vacíos*/
void HashCiudades::print() {
    int cont = 1;
    for (int i = 0; i < table.size(); i++) {
        if (!table[i].empty() && !status[i]) { 
            cout<<cont<<"  "<<table[i]<<" "<<i<<endl;
            cont++;
        }
    }
    cout<<"Number of elements: "<<insertedSize<<endl;
}

/*Método de la clase HashCiudades que recibe como parámetro un entero que representa la posición
que de la ciudad en la tabla cuyo valor se quiere regresar, si existe se regresa el string de la ciudad*/
string HashCiudades::getCiudad(int position) {
    string ciudad = table[position];
    if(ciudad.empty() || status[position]) {
        // throw invalid_argument
        cout<<"No hay matrícula en esa posición\n";
        return "";
    }
    else 
        return ciudad;
}

/*Método de la clase HashCiudades que regresa el valor del atributo insertedSize, que representa la cantidad
de elementos que han sido insertados en la hashtable*/
int HashCiudades::getSize() {
    return insertedSize;
}

/*Método de la clase HashCiudades que recibe como parámetros una dirección a un vector y dos enteros que
representan posiciones en este cuyos valores se quieren intercambiar*/
void HashCiudades::swap(vector<string> &list, int a, int b) {
    if (list[a] != list[b]) {
        string aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }

    //print(list);
}

/*Método de la clase HashCiudades que recibe como parámetro una dirección a un vector de strings
dos posiciones que representan el rango en el cual se aplicará el algoritmmo QuickSort*/
void HashCiudades::QuickSort(vector<string> &list, int left, int right) {  
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
    QuickSort(list, left,aux-1);
    // del lado derecho se llama con el pivote +1 y el right original
    QuickSort(list, aux+1, right);
    }
}

/*Método de la clase HashCiudades que recibe como parámetro una direccíon a un archivo ofstream
en el cuál se escribiran las ciudades ordenadas alfabéticamente utilizando quicksort
    Nota: se puede usar porque los operadores booleanos de comparación ya ordenan strings lexicográficamente*/
void HashCiudades::alphabeticalOrder(ofstream &QuickSortCiudades) {
    AlphabeticalTable.assign(table.begin(), table.end());
    QuickSort(AlphabeticalTable,0,AlphabeticalTable.size()-1);
    for (auto a : AlphabeticalTable) {
        QuickSortCiudades << a << endl;
        // cout<<a<<endl;
    }
}

#endif