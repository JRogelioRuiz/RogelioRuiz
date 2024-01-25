#pragma once

template<class T>
struct TNode {
    T data;
    TNode<T>* left;
    TNode<T>* right;
    TNode();
    TNode(T data);
    TNode(T data, TNode<T>* right, TNode<T>* left);

};

/*Constructor default de la clase TNode que inicializa los punteros right y left como nullptr*/
template<class T>
TNode<T>::TNode(){
    left = nullptr;
    right = nullptr;
}

/*Constructor de la clase TNode que recibe un dato como parámetro, asignandole su valor al atributo data e 
inicializando los punteros right y left como nullptr*/
template<class T>
TNode<T>::TNode(T data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

/*Constructor de la clase TNode que recibe el valor del dato del nodo, el puntero al nodo de la derecha (right)
y el puntero al nodo de la izqueirda (left)*/
template<class T>
TNode<T>::TNode(T data, TNode<T>* right, TNode<T>* left){
    this->data = data;
    this->left = left;
    this->right = right;
}
