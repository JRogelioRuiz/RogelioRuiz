#pragma once

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node();
    Node(T data);
    Node(T data, Node<T>* previous, Node<T>* next);

};

/*Constructor default de la estructura Node que inicializa sus punteros como nullptr*/
template<class T>
Node<T>::Node(){
    next = nullptr;
    previous = nullptr;
}

/*Constructor de la estructura Node que recibe un dato y lo actualiza*/
template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

/*Constructor de la clase Node que recibe un dato y sus punteros a los datos siguiente y anterior*/
template<class T>
Node<T>::Node(T data, Node<T>* prevoius, Node<T>* next){
    this->data = data;
    this->next = next;
    this->previous = prevoius;
}
