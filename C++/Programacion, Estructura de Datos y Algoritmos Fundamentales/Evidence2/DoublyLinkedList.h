#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList {
    private: 
    Node<T>* head;
    int size;

    public:
    DoublyLinkedList();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    void insertAfter(int posicion, T data);
    bool deleteData(T dato);
    bool deleteAt(int index);
    T getData(int indice);
    Node<T>* getDataPTR(int indice);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int findData(T data);
    T& operator[](int indice);
    void operator=(DoublyLinkedList<T> lista);
    void clear();
    void duplicate();
    void removeDuplicates();
    void print();
    bool isEmpty();
    void swap(Node<T>* aux1, Node<T>* aux2);
    void quickSort(int left, int right, int ipOrNot);
};

/*Constructor default de la clase DoublyLinkedList que inicializa head como nullptr y size como 0*/
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    size = 0;
}

/*Método sin entradas de la clase DoublyLinkedList que regresa la variable entera size*/
template<class T> 
int DoublyLinkedList<T>::getSize() {
    return size;
}

/*Método sin salidas de la clase DoublyLinkedList que recibe un dato y actualiza los punteros
necesarios para añadirlo al principio de la lista*/
template<class T> 
void DoublyLinkedList<T>::addFirst(T data) {
    // Asignamos a head un nuevo nodo con data y head de parámetros
    
    Node<T>* nodo = new Node<T>(data,nullptr,head);

    if (head != nullptr) {
        head->previous = nodo;
    }

    // Update the head pointer to point to the new node
    head = nodo;

    // Incrementamos el valor de size
    size++;
}

/*Método sin salidas de la clase DoublyLinkedList que recibe un dato y actualiza los punteros
necesarios para añadirlo al final de la lista*/
template<class T> 
void DoublyLinkedList<T>::addLast(T data) {
    
    if (isEmpty()) {
        head = new Node<T>(data,head,head);
    } else {
    // Definamos un apuntador auxiliar igual 
    Node<T>* aux = head;
    // Recorremos la lista
    while (aux->next != nullptr) {
        // recorrer aux
        aux = aux->next;
    }
    // Agregamos un nuevo nodo a aux
    aux->next = new Node<T>(data,aux,nullptr);
    }
    // Incrementamos size
    size++;
}

/*Método sin salidas de la clase DoublyLinkedList que recibe un entero y dato,
itera en la lista para encontrar la posición después de la magnitud del entero 
e insertar el dato*/
template<class T>
void DoublyLinkedList<T>::insertAfter(int posicion, T data){
    if (posicion >= 0 && posicion < size){
    // Definimos un apuntador auxiliar que sea igual a head
    Node<T>* aux = head;
    // Hacemos ciclo que actualiza el apuntador auxiliar hasta llegar
    // al valor de la lista en la posición anterior a la que buscamos redefinir 
    for (int i = 0; i < posicion; i++) {
        aux = aux->next;
    }
    // redefinimos el apuntador del auxiliar insertando un nuevo nodo que apunte
    // al nodo al cual antes apuntaba el auxiliar
    aux->next = new Node<T>(data, aux, aux->next);
    // aumentamos el tamaño de la lista
    size++;
    } else if (posicion == 0) 
    {
        addFirst(data);
    }
    else {
        throw out_of_range("El Indice esta fuera del rango"); 
    }
}

/*Método de la clase DoublyLinkedList que recibe un dato,
itera en la lista para encontrar la posición del dato y regresarla*/
template<class T>
int DoublyLinkedList<T>::findData(T data) {
    Node<T>* aux = head;
    int contador = 0;
    while (aux->data != data && aux->next != nullptr) {
        // se recorre la lista 
        aux = aux->next;
        contador++;
    }
    if (aux->data != data) {
            return -1;
    } else {
        return contador;
    } 
}

/*Método sin salidas de la clase DoublyLinkedList que recibe dos datos,
itera en la lista para encontrar el primer dato y lo reemplaza con el segundo dato*/
template<class T>
void DoublyLinkedList<T>::updateData(T data, T newData){
    Node<T>* aux = head;

    // se recorre la lista
    while (aux->data != data && aux->next != nullptr) {
        aux = aux->next;
    }
    if (aux->data == data) {
        aux->data = newData;
    }
    else {
        throw out_of_range("El Indice esta fuera del rango"); 
    }
}

/*Método sin salidas de la clase DoublyLinkedList que recibe un dato y un entero,
itera en la lista hasta llegar a la posición del entero y reemplaza el dato de esa posición 
con el dato dado*/
template<class T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    Node<T>* aux = head;
    if (index >= 0 && index <= size) {
        for (int i = 0; i < index; i++) { 
            aux = aux->next;
        }
        aux->data = newData;
    } else {
        throw out_of_range("El Indice esta fuera del rango"); 
    }
}

/*Método de la clase DoublyLinkedList que recibe un índice, 
itera hasta encontrar el dato de ese índice y lo regresa*/
template<class T>
T DoublyLinkedList<T>::getData(int indice) {
    // validamos si el indice es correcto
    if (indice >= 0 && indice <= size) {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // recorremos la lista hasta llegar al índice deseado
        for (int i = 0; i < indice; i++) { 
            aux = aux->next;
        }
        return aux->data;
    }
    else {       
        throw out_of_range("Índice inválido");
    }
}

/*Método de la clase doubly linked list que recibe un índice,
itera hasta encontrar el puntero del nodo en esa posición y
lo regresa*/
template<class T>
Node<T>* DoublyLinkedList<T>::getDataPTR(int indice) {
    // validamos si el indice es correcto
    if (indice >= 0 && indice <= size) {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // recorremos la lista hasta llegar al índice deseado
        for (int i = 0; i < indice; i++) { 
            aux = aux->next;
        }
        return aux;
    }
    else {       
        throw out_of_range("Índice inválido");
    }
}


/*Método de la clase DoublyLinkedList que recibe un dato,
itera en la lista para encontrar la posición del dato y actualiza los punteros 
necesarios para eliminarlo de la lista, regresa verdadero sólo si se eliminó el dato*/
template <class T>
bool DoublyLinkedList<T>::deleteData(T data) {
    if(DoublyLinkedList::findData(data) != -1) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // Validamos si el elemento a borrar es el primero de la lista
        if (head->data == data) {
            // Creamos un apuntador auxiliar igual a head
            Node<T>* aux = head;
            // Cambiamos el valor de head
            head = head->next;
            head->previous = nullptr;
            // Decrementamos el valor de size
            size--;
            // Liberamos de memoria el node que esta en aux
            delete aux;
            // regresamos verdadero
            return true; 
        } else {
            // Creamos un apuntador auxuliar previo igual a head
            Node<T>* auxPrev = head;
            // Creamos un apuntador auxuliar igual a al siguiente nodo despues de head
            Node<T>* aux = head->next;
            // Recorremos la lista hasta encontrar el valor a borrar
            while (aux != nullptr) {
                if (aux->data == data) {
                    auxPrev->next = aux->next;
                    if (aux->next != nullptr) {
                        aux->next->previous = auxPrev;
                    }
                    delete aux;
                    size--;
                    return true;
                }
                auxPrev = aux;
                aux = aux->next;
            }
            // No se encontró el valor buscado
            return false;
        }
    } else {
        return false;
    }
    }
    else {
        return false;
    }
}

/*Método de la clase DoublyLinkedList que recibe un índice,
itera en la lista para encontrar el dato en esa posición y actualiza los punteros 
necesarios para eliminarlo de la lista, regresa verdadero sólo si se eliminó el dato*/
template<class T>
bool DoublyLinkedList<T>::deleteAt(int index) {
   // Validamos que el índice sea válido
   if (index>= 0 && index < size) {
        //Validamos si se quiere borrar el primer elemento
        if(index == 0) {
            // Creamos un apuntador auxiliar = head
            Node<T>* aux = head;
            // Cambiamos el valor de head
            head = head->next;

            head->previous = nullptr;
            //Decrementamos el valor de size
            size--;
            // Liberamos de memoria el nodo que está en aux
            delete aux;
            // regresamos verdadero
            return true; 
        } else {
            // Creamos un apuntador auxiliar previo igual a head
            Node<T>* auxPrevious = head;
            // Creamos una apuntador auxiliar igual al siguiente nodo después de head
            Node<T>* aux = head->next;
            // Creamos un índice auxiliar igual a 1
            int auxIndex = 1;
            //Recorremos la lista hasta llegar al nodo deseado
            while (auxIndex < index) {
                //Recorremos los nodos auxilirares
                auxPrevious = aux;
                aux = aux->next;
                // Incrementamos auxIndex
                auxIndex++;
            }
            // Actualizamos el valor de next del nodo auxiliar anterior
            auxPrevious->next = aux->next;

            // Actualizamos el valor de next del nodo auxiliar anterior
            auxPrevious->next->previous = auxPrevious;

            // Decrementamos el valor de size
            size--;
            //Liberamos de memoria el nodo aux
            delete aux;
            //Regresamos verdadero
            return true;
        }
   } else {
        return false;
   }
}

/*Sobrecarga de operador[] de la clase DoublyLinkedList, recibe un índice
itera en la lista hasta encontrar el dato en esa posición y lo regresa*/
template<class T>
T& DoublyLinkedList<T>::operator[](int indice) {
    // validamos si el indice es correcto
    if (indice >= 0 && indice <= size) {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // recorremos la lista hasta llegar al índice deseado
        for (int i = 0; i < indice; i++) { 
            aux = aux->next;
        }
        return aux->data;
    }
    else {       
        throw out_of_range("Índice inválido");
    }
}

/*Sobrecarga de operador= de la clase DoublyLikedLists recibe otra DLL
utilza el método clear() para borrar la lista e itera en la DLL que recibió
para añadir todos sus valores a la lista en la cuál se aplica el método*/
template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> lista) {
    // DoublyLinkedList<T>::addLast(something);
    DoublyLinkedList<T>::clear();
    
    for (int i = 0; i < lista.getSize(); i++) {
        DoublyLinkedList<T>::addLast(lista[i]);
    }
    // DoublyLinkedList<T>::deleteAt(0);
}

/*Método de la clase DoublyLinkedList que elimina todos los valores de la lista*/
template<class T>
void DoublyLinkedList<T>::clear() {

    Node<T>* aux = head;

    while (aux != nullptr) {
        Node<T>* nodo = aux;
        aux = aux->next;
        delete nodo;
    }

    head = nullptr;
    size = 0;
}

/*Método de la clase DoublyLinkedList que despliega todos los valores de la lista*/
template<class T> 
void DoublyLinkedList<T>::print() { 
    // Definimos un apuntador auxiliar que sea igual a head
    Node<T>* aux = head;
    while(aux != nullptr) {
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << endl;
        }
        // recorremos aux al apuntador de next
        aux = aux->next;
    }
    // imprimimos un salto de linea
    cout << endl << endl;
}

/*Método de la clase DoublyLinkedList que regresa el resultado booleano de checar
si el atributo size es igual a 0*/
template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

/*Método de la clase DoublyLinkedList que en cada posición de la lista, duplica su valor
insertando el dato en la posición siguiente (1,2,3) -> (1,1,2,2,3,3)*/
template<class T>
void DoublyLinkedList<T>::duplicate() {
    Node<T>* aux = head;
    int iter = 0;

    while (aux != nullptr) {
        DoublyLinkedList<T>::insertAfter(iter, aux->data);
        aux = aux->next;
        aux = aux->next;
        iter+=2;
    }
}

/*Método de la clase DoublyLinkedList que en cada posición revisa si el dato se repite en
en la siguiente posición, si sí, elimina uno de la lista*/
template<class T>
void DoublyLinkedList<T>::removeDuplicates() {
    Node<T>* aux = head;

    while (aux != nullptr && aux->next != nullptr) {
        if (aux->next->data == aux->data)
        {
            DoublyLinkedList<T>::deleteData(aux->data);
            aux = aux->next;
        }

        aux = aux->next;
    }
    
}

/*Método de la clase DoublyLinkedList que recibe dos punteros a nodos de la lista
e intercambia sus datos*/
template<class T>
void DoublyLinkedList<T>::swap(Node<T>* aux1, Node<T>* aux2) {
    if (aux1 != aux2) {
        T temp = aux1->data;
        aux1->data = aux2->data;
        aux2->data = temp;
    }
}

/*Función de ordenamiento con algoritmo Quick Sort:
    la función recibe dos valores enteros que representan los índices en los cuáles se va a realizar el algoritmo
    y un tercero que determina si se ordena por IPs o no
    no tiene valor de retorno, porque se ordena la lista original
*/
template <class T> 
void DoublyLinkedList<T>::quickSort(int left, int right, int ipOrNot) {  
    int aux = left-1;
    if (left < right) {
        if (ipOrNot) {
            // Ciclo for que itera desde left hasta right-1
            for (int index = left; index < right; index++) {
                // Se checa si la IP en la posición del índice es igual a el pivote
                if ((*this)[index].getIPValue() == (*this)[right].getIPValue()) {
                    // Las IPs son iguales, se checa la fecha y hora
                    if ((*this)[index] < (*this)[right]) {
                        // Si el elemento del índice es menor, se checa el índice auxiliar
                        // y se intercambian el elemento del pivote con el del índice auxiliar 
                        aux++; 
                        swap(getDataPTR(aux), getDataPTR(index));
                    }
                // Se checa si la IP en la posición del índice es menor a el pivote
                } else if ((*this)[index].getIPValue() < (*this)[right].getIPValue()) {
                    // Si el elemento del índice es menor, se aumenta el índice auxiliar
                    // y se intercambian el elemento del pivote con el del índice auxiliar 
                    aux++; 
                    swap(getDataPTR(aux), getDataPTR(index));
                }  
            }
        } else {
            // Ciclo for que itera desde left hasta right-1
            for (int index = left; index < right; index++) {
                // Se checa si el elemento en la posición del índice es menor a el pivote
                if ((*this)[index] < (*this)[right]) {
                    // Si el elemento del índice es menor, se aumenta el índice auxiliar
                    // y se intercambian el elemento del pivote con el del índice auxiliar 
                    aux++; 
                    swap(getDataPTR(aux), getDataPTR(index));
                }  
            }
        }
        // Al final del ciclo for se aumenta 1 al auxiliar, y se intercambia con el pivote.
        aux++;
        swap(getDataPTR(aux), getDataPTR(right));

        // Se manda a llamar la función quicksort para ambos lados del pivote ya ordenado   
        // del lado izquierdo se llama con el left original, con el pivote menos 1.
        (ipOrNot) ? quickSort(left, aux-1,1) : quickSort(left, aux-1,0); 
        // del lado derecho se llama con el pivote +1 y el right original
        (ipOrNot) ? quickSort(aux+1, right, 1) : quickSort(aux+1, right, 0);
    }
}

#endif