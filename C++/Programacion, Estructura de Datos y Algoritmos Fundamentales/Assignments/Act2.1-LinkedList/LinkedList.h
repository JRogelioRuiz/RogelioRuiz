#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class LinkedList {
    private: 
    Node<T>* head;
    int size;
    public:
    LinkedList();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    void insertAfter(int posicion, T data);
    bool deleteData(T dato);
    int findData(T data);
    void updateData(T data, T newData);
    T getData(int indice);
    void updateAt(int index, T newData);
    bool deleteAt(int index);
    T& operator[](int indice);
    void operator=(LinkedList<T> lista);
    void print();
    bool isEmpty();
    void clear();

};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<class T> 
int LinkedList<T>::getSize() {
    return size;
}

template<class T> 
void LinkedList<T>::addFirst(T data) {
    // Asignamos a head un nuevo nodo con data y head de parámetros
    head = new Node<T>(data,head);
    // Incrementamos el valor de size
    size++;
}


template<class T> 
void LinkedList<T>::addLast(T data) {
    if (isEmpty()) {
        head = new Node<T>(data, head);
    } else {
    // Definamos un apuntador auxiliar igual 
    Node<T>* aux = head;
    // Recorremos la lista
    while (aux->next != nullptr) {
        // recorrer aux
        aux = aux->next;
    }
    // Agregamos un nuevo nodo a aux
    aux->next = new Node<T>(data);
    }
    // Incrementamos size
    size++;
}

template<class T>
void LinkedList<T>::insertAfter(int posicion, T data){
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
    aux->next = new Node<T>(data, aux->next);
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

template <class T>
bool LinkedList<T>::deleteData(T data) {
    if(LinkedList::findData(data) != -1) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // Validamos si el elemento a borrar es el primero de la lista
        if (head->data == data) {
            // Creamos un apuntador auxiliar igual a head
            Node<T>* aux = head;
            // Cambiamos el valor de head
            head = head->next;
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
                // Validamos que aux->data sea igual a data
                if (aux->data == data) {
                    // Actualizamos el valor de next el nodo auxiliar anterior
                    auxPrev->next = aux->next;
                    // Decrementamos el valor de size
                    size--;
                    // Liberamos de memoria el nodo que esta en aux
                    delete aux;
                    // regresamos verdadero
                    return true;
                }
                // Recorremos los nodos auxiliares
                auxPrev->next = aux;
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

template<class T>
bool LinkedList<T>::deleteAt(int index) {
   // Validamos que el índice sea válido
   if (index>= 0 && index < size) {
        //Validamos si se quiere borrar el primer elemento
        if(index == 0) {
            // Creamos un apuntador auxiliar = head
            Node<T>* aux = head;
            // Cambiamos el valor de head
            head = head->next;
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

template<class T>
T LinkedList<T>::getData(int indice) {
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

template<class T>
void LinkedList<T>::updateData(T data, T newData){
    Node<T>* aux = head;

    // se recorre la lista
    while (aux->data != data && aux->next != nullptr) {
        aux = aux->next;
    }
    if (aux->data == data) {
        aux->data = newData;
    }
}

template<class T>
void LinkedList<T>::

updateAt(int index, T newData) {
    Node<T>* aux = head;
    if (index >= 0 && index <= size) {
        for (int i = 0; i <= index; i++) { 
            aux = aux->next;
        }
        aux->data = newData;
    } else {
        cout<<"Indice fuera de rango\n";
    } 
}

template<class T>
int LinkedList<T>::findData(T data) {
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

template<class T>
T& LinkedList<T>::operator[](int indice) {
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

template<class T>
void  LinkedList<T>::operator=(LinkedList<T> lista) {
    for (int i = size-1; i >= 0; i--) { 
        LinkedList<T>::deleteAt(i);
    }
    for (int i = 0; i < lista.getSize(); i++) {
        LinkedList<T>::addLast(lista[i]);
    }
}

template<class T>
void LinkedList<T>::clear() {
    for (int i = size-1; i >= 0; i--) { 
        LinkedList<T>::deleteAt(i);
    }
}

template<class T> 
void LinkedList<T>::print() { 
    // Definimos un apuntador auxiliar que sea igual a head
    Node<T>* aux = head;
    while(aux != nullptr) {
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << "->";
        }
        // recorremos aux al apuntador de next
        aux = aux->next;
    }
    // imprimimos un salto de linea
    cout << endl << endl;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}


#endif