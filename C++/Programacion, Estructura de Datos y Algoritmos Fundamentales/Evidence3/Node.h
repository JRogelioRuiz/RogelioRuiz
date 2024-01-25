#pragma once

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node();
    Node(T data);
    Node(T data, Node<T>* next);

};

/*Constructor default de la clase Node que inicializa el puntero next como nullptr*/
template<class T>
Node<T>::Node(){
    next = nullptr;
}

/*Constructor de la clase Node que recibe el dato de el nodo para inicializarlo, e iguala el puntero next a nullptr*/
template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
}

/*Constructor de la clase Node que recibe el dato del nodo y el puntero hacia el nodo que sigue*/
template<class T>
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}
