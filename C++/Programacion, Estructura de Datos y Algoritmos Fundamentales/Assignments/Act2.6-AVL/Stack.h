#ifndef Stack_h
#define Stack_h

#include "Node.h"

template<class T>
class Stack {
private:
    Node<T>* top;
    int size;
public:
    Stack();
    void push(T data);  //Agrego un elemento a la pila
    T pop(); // Elimina el elemento de arriba de la pila
    T getTop(); // Regresa el elemento de arriba de la pila
    bool isEmpty();
    void print();
    int getSize();

};

template<class T>
Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}

template<class T> 
void Stack<T>::push(T data) {
    // Creamos un nuevo nodo con data y nullptr parámetros
    Node<T>* nodo = new Node<T>(data,nullptr);

    // revisamos si hay más datos en la pila
    if (top != nullptr) {
        // si sí los hay, actualizamos el apuntador del nuevo nodo de la cima
        nodo->next = top;
    }

    // Actualizamos top con el nuevo valor en la cima del stack
    top = nodo;

    // aumentamos size
    size++;
}


template<class T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        // Creamos un apuntador auxiliar igual a front
        Node<T>* aux = top;
        // Cambiamos el valor de front
        top = top->next;
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

template<class T>
T Stack<T>::getTop() {
    if (!isEmpty()) {
        // regresamos el dato del elemento de enfrente en la lista
        return top->data; 
    }
    else {
        throw out_of_range("No hay elementos en el Stack");
    }
} 

template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
} 

template<class T>
int Stack<T>::getSize() {
    return size;
} 

template<class T> 
void Stack<T>::print() { 
    // Definimos un apuntador auxiliar que sea igual a head
    Node<T>* aux = top;
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