#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "DNode.h"
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
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int findData(T data);
    T& operator[](int indice);
    void operator=(DoublyLinkedList<T> lista);
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
    void print();
    bool isEmpty();
    void swap(int a, int b);

};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    size = 0;
}

template<class T> 
int DoublyLinkedList<T>::getSize() {
    return size;
}

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

template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> lista) {
    // T something;
    // DoublyLinkedList<T>::addLast(something);
    DoublyLinkedList<T>::clear();
    
    for (int i = 0; i < lista.getSize(); i++) {
        DoublyLinkedList<T>::addLast(lista[i]);
    }
    // DoublyLinkedList<T>::deleteAt(0);
}

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

template<class T> 
void DoublyLinkedList<T>::print() { 
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
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

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

template<class T>
void DoublyLinkedList<T>::swap(int a, int b) {
    if (DoublyLinkedList<T>::getData(a) != DoublyLinkedList<T>::getData(b)) {
        T aux = DoublyLinkedList<T>::getData(a);
        DoublyLinkedList<T>::updateAt(a, DoublyLinkedList<T>::getData(b));
        DoublyLinkedList<T>::updateAt(b,aux);
    }

    //print(list);
}

// Método sort utilizando Shellsort
template<class T>
void DoublyLinkedList<T>::sort() { 
    int intervalo = size/2;
    int index = 0;
    int aux = index + intervalo;
    int hold=0;
    bool needsToGoBackwards=0;
    
    while (intervalo >= 1) {
        if (!needsToGoBackwards) {
            if(aux > size-1 || aux < 0){
                index = 0;
                intervalo = intervalo /2;
                aux = index + intervalo;
            } else if (DoublyLinkedList<T>::getData(index) > DoublyLinkedList<T>::getData(aux)) {
                swap(index, aux);
                needsToGoBackwards = 1;
                hold = index+1;
                aux = index-intervalo;
            } else {
                index++;
                aux++;
            }
    
        } else if (needsToGoBackwards) {
            if(aux > size-1 || aux < 0 || DoublyLinkedList<T>::getData(index) > DoublyLinkedList<T>::getData(aux)){
                index = hold;
                aux = index + intervalo;
                needsToGoBackwards = 0;
            } else  {
                swap(index, aux);
                index = aux;
                aux = index-intervalo;
            } 
        }
    }
}



#endif