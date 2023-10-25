#pragma once

template<class T>
struct DNode {
    T data;
    DNode<T>* next;
    DNode<T>* previous;
    DNode();
    DNode(T data);
    DNode(T data, DNode<T>* previous, DNode<T>* next);

};

template<class T>
DNode<T>::DNode(){
    next = nullptr;
    previous = nullptr;
}

template<class T>
DNode<T>::DNode(T data){
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

template<class T>
DNode<T>::DNode(T data, DNode<T>* prevoius, DNode<T>* next){
    this->data = data;
    this->next = next;
    this->previous = prevoius;
}
