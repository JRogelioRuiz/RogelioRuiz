#ifndef Stack_h
#define Stack_h

#include "Node.h"

template<class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* tail;
    int size;
public:
    Queue();
    void push(T data);  //Inserta un elemento a la fila
    T pop(); // Elimina el elemento al principio de la fila
    T getFront(); // Regresa el elemento al principio de la fila
    bool isEmpty(); 
    void print();
};

/*Constructor default de la clase Queue que inicialza los punteros front y tail como nullptr
y el tamaño de la fila como 0*/
template<class T>
Queue<T>::Queue() {
    front = nullptr;
    tail = nullptr;
    size = 0;
}

/*Método de la clase Queue que recibe un dato como parámetro y lo ingresa a la última posición de la fila*/
template<class T> 
void Queue<T>::push(T data) {
    // Creamos un nuevo nodo con data y nullptr parámetros
    Node<T>* nodo = new Node<T>(data,nullptr);

    if (front == nullptr) {
        front = nodo;
    }
    // Actualizamos el apuntador next de el elemento final anterior 
    if (tail != nullptr) {
    tail->next = nodo;
    }
    // Actualizamos el apuntador de elemento final
    tail = nodo;

    size++;
}

/*Método de la clase Queue que elimina el valor front de la fila y lo regresa*/
template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        // Creamos un apuntador auxiliar igual a front
        Node<T>* aux = front;
        // Cambiamos el valor de front
        front = front->next;
        // Decrementamos el valor de size
        size--;
        // Guardamos el valor del valor eliminado en una variable
        T dato = aux->data;
        // Liberamos de memoria el node que esta en aux
        delete aux;
        // regresamos verdadero
        return dato; 
    }
    else {
        throw out_of_range("No se pudo borrar elemento");
    }
}

/*Método de la clase Queue que regresa el dato del primer valor de la fila (front)*/
template<class T>
T Queue<T>::getFront() {
    if (!isEmpty()) {
        // regresamos el dato del elemento de enfrente en la lista
        return front->data; 
    }
    else {
        throw out_of_range("No hay elementos en el Queue");
    }
} 

/*Método de la clase Queue que regresa True si la fila está vacía y False si la fila tiene elementos*/
template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
} 

/*Método de la clase Queue que despliega los elementos de la fila en la pantalla*/
template<class T> 
void Queue<T>::print() { 
    // Definimos un apuntador auxiliar que sea igual a head
    Node<T>* aux = front;
    while(aux != nullptr) {
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << "->";
        }
        // recorremos aux al apuntador de next
        aux = aux->next;
    }
    // imprimimos un salto de linea
    cout << endl;
}

#endif