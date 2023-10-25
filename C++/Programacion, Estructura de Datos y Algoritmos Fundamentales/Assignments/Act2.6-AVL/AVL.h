#ifndef AVL_h
#define AVL_h

#include "Stack.h"
#include "TNode.h"
#include "Queue.h"

template<class T>
class AVL {
    private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);

    public:
    
    AVL();
    void insert(T data);
    void deleteData(T data);
    void print();
    
    bool find(T data);
    bool isEmpty();
    int whatLevelAmI(T data);
    Stack<TNode<T>*> ancestors(T data);
    int height();
    int heightRecursive(TNode<T>* leRoot);
    int nodeHeight(TNode<T>* node);
    void visit(int order);
    void allOrders(TNode<T>* node, int whatOrder);
    int getBalance(TNode<T>* nodo);
    void rightRotate(TNode<T>* nodoARotar);
    void leftRotate(TNode<T>* y);
};


template<class T>
AVL<T>::AVL(){
    root = nullptr;
}

template <class T>
void AVL<T>::insert(T data) {
    // Checamos si el arbol está vacío
    if (isEmpty()) {
        // está vacío
        // le asignamos a root un nuevo nodo con el valor de data
        root = new TNode<T>(data);
    } else { 
        // el no está vacío
        // creamos un apuntador auxiliar iguala root
        TNode<T>* aux = root;
        // recorremos el árbol hasta insertar el valor nuevo (aux != nullptr)
        while (aux != nullptr) {
            // Validamos si data es menor a aux->data
            if (data < aux->data) {
                // Si es menor
                // validamos si el apuntador del lado izquierdo de aux es nullptr
                if (aux->left == nullptr) {
                    // si es nulo
                    // apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    //return;
                    aux = nullptr;
                } else {
                    // no es nulo
                    // recorremos aux al lado izquierdo de aux
                    aux = aux->left;
                }
            } else {
                // es mayor o igual
                // validamos si el apuntador del lado derecho de aux es nullptr
                if (aux->right == nullptr) {
                    // si es nulo
                    // apuntamos al lado derecho de aux a un nuevo nodo con el valor de data
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    //return;
                    aux = nullptr;
                } else {
                    // no es nulo
                    // recorremos aux al lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }

    /*Balanceo*/
    // Ponemos los ancestros en una pila para ir checando de abajo hacia arriba
    Stack<TNode<T>*> ancestorsData = ancestors(data);

    // Ciclo que itera en todos los elementos del Stack de ancestros del dato recién agregado y los balancea 
    while (!ancestorsData.isEmpty()) {
        TNode<T>* currentAncestor = ancestorsData.getTop();
        ancestorsData.pop();
        TNode<T>* fatherOfCurrentAncestor;
        if (!ancestorsData.isEmpty()) {
            fatherOfCurrentAncestor = ancestorsData.getTop();
        }

        int balance = getBalance(currentAncestor);
        if (balance < -1) {
            int sonBalance = getBalance(currentAncestor->left);
            if (sonBalance == 1) {
                TNode<T>* auxNode = currentAncestor->left->right;
                leftRotate(currentAncestor->left);
                currentAncestor->left = auxNode;
                // fatherOfCurrentAncestor->left = currentAncestor->left;
                // rightRotate(currentAncestor);
            } 
            if(!ancestorsData.isEmpty()) (currentAncestor->data < fatherOfCurrentAncestor->data) ? fatherOfCurrentAncestor->left = currentAncestor->left : fatherOfCurrentAncestor->right = currentAncestor->left;
            rightRotate(currentAncestor); 
        }
        else if (balance > 1) {
            int sonBalance = getBalance(currentAncestor->right);
            if (sonBalance < 0) {
                TNode<T>* auxNode = currentAncestor->right->left;;
                rightRotate(currentAncestor->right);
                currentAncestor->right = auxNode;
                // fatherOfCurrentAncestor->right = currentAncestor->right;
                // leftRotate(currentAncestor);
            }
            if(!ancestorsData.isEmpty()) (currentAncestor->data < fatherOfCurrentAncestor->data) ? fatherOfCurrentAncestor->left = currentAncestor->right : fatherOfCurrentAncestor->right = currentAncestor->right;
            leftRotate(currentAncestor);
        }
    }

}

template<class T>
void AVL<T>::deleteData(T data) {
    // // Stack con los punteros a los ancestros del dato a borrar
    Stack<TNode<T>*> ancestorsData = ancestors(data);
    bool wasRoot = (data == root->data); 
    // (wasRoot) ? cout<<"ROOT "<<children(root)<<endl :cout<<"NOT ROOT\n" ;
    if (wasRoot) {
        TNode<T>* aux = root;
        int numChildren = children(root);
        if (numChildren == 0) {
            delete aux;
        }
        else if (numChildren == 1) {
            (root->left != nullptr) ? root = root->left : root = root->right;
            delete aux;
        } else if (numChildren == 2) {
            TNode<T>* auxPP = root->left;
            TNode<T>* auxHH = auxPP->right;
            // recorremos todos los nodos que tengan un apuntador derecho diferente a nulo, hasta encontrar el que tenga right = nullptr
            if (auxHH == nullptr) {
                // Se debe tomar en cuenta el caso donde el hijo derecho del hijo izquierdo del nodo a borrar (auxHH) es nulo: 
                root->data = auxPP->data;
                (auxPP->left == nullptr ) ? root->left = nullptr : root->left = auxPP->left;
                delete auxPP;
            } else {
                while (auxHH->right != nullptr) { 
                    // recorremos los apuntadores auxiliares
                    // el apuntador auxiliar padre va a ser igual al apuntador auxiliar hijo
                    auxPP = auxHH;
                    // el apuntador auxiliar hijo va a ser igual al apuntador del lado derecho del apuntador auxiliar hijo
                    auxHH = auxHH->right;
                }
                // El valor del nodo a borrar va a ser igual al valor del apuntador auxiliar hijo
                root->data = auxHH->data;
                // El apuntador del lado derecho del auxiliar padre va a ser igual al apuntador del lado izquierdo del apuntador auxiliar hijo
                auxPP->right = auxHH->left;
                // Borramos el apuntador auxiliar hijo
                delete auxHH;
            }
            
        }
    } else {
    // Cuando el dato a borrar no es igual a root->data
    // buscar el nodo a borrar (debemos mantener el apuntador al papá del nodo a borrar)
    TNode<T>* auxP = root;
    TNode<T>* auxH;
    // auxH es el hijo menor o mayor a apuntador padre
    (data < auxP->data) ? auxH = auxP->left : auxH = auxP->right;

    // Iteramos mientras que el dato del auxiliar hijo no sea el dato que buscamos o sea diferente a nulo
    while (auxH->data != data && auxH != nullptr) {
        auxP = auxH;
        (data < auxH->data) ? auxH = auxH->left : auxH = auxH->right;
        // si aux hijo es nulo, no está el dato en la lista
        if (auxH == nullptr) throw invalid_argument("Dato no encontrado");
    }

    // Buscamos cuantos hijos tiene el nodo
    int numChildren = children(auxH);

    if (numChildren==0) {
    // 0 hijos
        // si el valor a borrar es menor al valor del padre
            // le asignamos nulos al apuntador del lado izquierdo del padre
        // si el valor es mayor o igual
            // le asignamos nulos al apuntador del lado derecho del padre
        (auxH->data < auxP->data) ? auxP->left = nullptr : auxP->right = nullptr;
        
        // borramos el nodo
        delete auxH;

    } else if (numChildren == 1) {
    // 1 hijo
        if (auxH->data < auxP->data) {
        // si el valor a borrar es menor al valor del padre
            // si el apuntador del lado izquierdo del nodo a borrar no es nulo
                // le asignamos al apuntador del lado izquierdo del padre el apuntador izquierdo del hijo
            // si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                // el apuntador del lado izquierdo del padre va a ser igual al apuntador de lado derecho del nodo a borrar        
            (auxH->left != nullptr) ? auxP->left = auxH->left : auxP->left= auxH->right;
        } else {
        // si el valor es mayor o igual al valor del padre
            // si el apuntador del lado izquierdo del nodo a borrar no es nulo    
                // le asignamos al apuntador del lado derecho del padre el apuntador izquierdo del hijo
            // si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                // el apuntador del lado derecho del padre va a ser igual al apuntador de lado derecho del nodo a borrar    
            (auxH->left != nullptr) ? auxP->right = auxH->left : auxP->right= auxH->right;
        }
        // borramos el nodo
        delete auxH;
    } else {
    // 2 hijos
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar es nulo (El hijo del lado izquierdo es el mayor)
        if (auxH->left->right == nullptr) {   
            // El valor del nodo a borrar va a ser igual al valor del hijo del lado izquierdo
            // El apuntador del lado izquierdo del nodo a borrar va a ser igual al apuntador del lado izquierdo del hijo del lado izquierdo
            // Borramos el hijo del lado izquierdo del nodo a borrar
            auxH->data = auxH->left->data;
            TNode<T>* aux = auxH->left;
            auxH->left = auxH->left->left;
            delete aux;
        } else {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar no es nullptr (el hijo izquierdo no es el mayor)
            // creamos un apuntador auxiliar padre igual al hijo del lado izquierdo del nodo a borrar
            // Creamos un apuntador auxiliar hijo igual al apuntador del lado derecho del nodo auxiliar padre
            TNode<T>* auxPP = auxH->left;
            TNode<T>* auxHH = auxPP->right;
            // recorremos todos los nodos que tengan un apuntador derecho diferente a nulo, hasta encontrar el que tenga right = nullptr
            while (auxHH->right != nullptr) { 
                // recorremos los apuntadores auxiliares
                // el apuntador auxiliar padre va a ser igual al apuntador auxiliar hijo
                auxPP = auxHH;
                // el apuntador auxiliar hijo va a ser igual al apuntador del lado derecho del apuntador auxiliar hijo
                auxHH = auxHH->right;
            }
            // El valor del nodo a borrar va a ser igual al valor del apuntador auxiliar hijo
            auxH->data = auxHH->data;
            // El apuntador del lado derecho del auxiliar padre va a ser igual al apuntador del lado izquierdo del apuntador auxiliar hijo
            auxPP->right = auxHH->left;
            // Borramos el apuntador auxiliar hijo
            delete auxHH;
        }
    }
    }

    // Ciclo que itera en todos los elementos del Stack de ancestros del dato recién borrado, y los balancea 
    while (!ancestorsData.isEmpty()) {
        TNode<T>* currentAncestor = ancestorsData.getTop();
        ancestorsData.pop();
        TNode<T>* fatherOfCurrentAncestor;
        if (!ancestorsData.isEmpty()) {
            fatherOfCurrentAncestor = ancestorsData.getTop();
        }

        int balance = getBalance(currentAncestor);
        if (balance < -1) {
            int sonBalance = getBalance(currentAncestor->left);
            if (sonBalance == 1) {
                TNode<T>* auxNode = currentAncestor->left->right;
                leftRotate(currentAncestor->left);
                currentAncestor->left = auxNode;
                // fatherOfCurrentAncestor->left = currentAncestor->left;
                // rightRotate(currentAncestor);
            }
            // fatherOfCurrentAncestor->left = currentAncestor->left;
            if(!ancestorsData.isEmpty()) (currentAncestor->data < fatherOfCurrentAncestor->data) ? fatherOfCurrentAncestor->left = currentAncestor->left: fatherOfCurrentAncestor->right = currentAncestor->left;
            rightRotate(currentAncestor); 
        }
        else if (balance > 1) {
            int sonBalance = getBalance(currentAncestor->right);
            if (sonBalance < 0) {
                TNode<T>* auxNode = currentAncestor->right->left;;
                rightRotate(currentAncestor->right);
                currentAncestor->right = auxNode;
                // fatherOfCurrentAncestor->right = currentAncestor->right;
                // leftRotate(currentAncestor);
            } 
            // if(!ancestorsData.isEmpty()) fatherOfCurrentAncestor->right = currentAncestor->right;
            if(!ancestorsData.isEmpty()) (currentAncestor->data < fatherOfCurrentAncestor->data) ? fatherOfCurrentAncestor->left = currentAncestor->right : fatherOfCurrentAncestor->right = currentAncestor->right;
            leftRotate(currentAncestor);
        }
    }    
        
}

template<class T>
void AVL<T>::rightRotate(TNode<T>* nodoARotar) {  
    TNode<T>* nodoIzquierda = nodoARotar->left;  
    if (nodoARotar == root) root = nodoIzquierda;
    TNode<T>* nodoIzquierda_right = nodoIzquierda->right;  
  
    // Rotación  
    nodoIzquierda->right = nodoARotar;  
    nodoARotar->left = nodoIzquierda_right;    
}

template<class T>
void AVL<T>::leftRotate(TNode<T>* nodoARotar) {  
    TNode<T>* nodoDerecha = nodoARotar->right;
    if (nodoARotar == root) root = nodoDerecha;   
    TNode<T>* nodoDerecha_left = nodoDerecha->left;  
  
    // Rotación  
    nodoDerecha->left = nodoARotar;  
    nodoARotar->right = nodoDerecha_left;    
}

template<class T>
int AVL<T>::getBalance(TNode<T>* nodo) {  
    if (nodo == NULL)  
        return 0;  
    return - nodeHeight(nodo->left) + nodeHeight(nodo->right);  
} 

template <class T>
void AVL<T>::allOrders(TNode<T>* node, int orderType){
    /*PREORDER*/
    if (orderType == 1) {
        /*Si el apuntador a un nodo no es nullptr*/
        if (node != nullptr) {
            // se imprime el dato del nodo
            cout<<node->data<<" ";
            // se imprimen los nodos hijos a su izquierda
            allOrders(node->left, orderType);
            // se imprimen los nodos hijos a su derecha
            allOrders(node->right, orderType);
        }
    }
    /*INORDER*/
    if (orderType == 2) {
        /*Si el apuntador a un nodo no es nullptr*/
        if (node != nullptr) {
            // se imprimen los nodos hijos a su izquierda
            allOrders(node->left, orderType);
            // se imprime el dato del nodo
            cout<<node->data<<" ";
            // se imprimen los nodos hijos a su derecha
            allOrders(node->right, orderType);
        }
    }
    /*POSTORDER*/
    if (orderType == 3) {
        /*Si el apuntador a un nodo no es nullptr*/
        if (node != nullptr) {
            // se imprimen los nodos hijos a su izquierda
            allOrders(node->left, orderType);
            // se imprimen los nodos hijos a su derecha
            allOrders(node->right, orderType);
            // se imprime el dato del nodo
            cout<<node->data<<" ";
        }
    }
    /*LEVEL BY LEVEL*/
    if (orderType == 4) {
        if (node != nullptr) {
            Queue<TNode<T>*> fila;
            fila.push(node);

            while(!fila.isEmpty()) {
                TNode<T>* aux = fila.getFront();
                fila.pop();

                cout<<aux->data<<" ";

                if (aux->left != nullptr) { 
                fila.push(aux->left);
                }
                
                if (aux->right != nullptr) { 
                fila.push(aux->right);
                }
            }
        }
    }
}

template<class T>
void AVL<T>::visit(int order){
    if (order == 1 || order == 2 || order == 3 || order == 4) {
        allOrders(root, order);   
        cout<<endl;
    }
    else {
        throw out_of_range("Opción no válida"); 
    }     
}

template<class T>
int AVL<T>::whatLevelAmI(T data) {
    TNode<T>* aux = root;
    int contador = 0;

    while (aux != nullptr) {
        if (data == aux->data) {
            return contador;
        }
        else {
            (data < aux->data) ? aux = aux->left : aux = aux->right;
            contador++;
        }
    }
    return -1;
}

template<class T>
Stack<TNode<T>*> AVL<T>::ancestors(T data) {
    Stack<TNode<T>*> theAncestors;
    if (find(data)) {
        TNode<T>* aux = root;
        while (aux != nullptr) {
            if (data == aux->data) {
                theAncestors.push(aux);
                aux = nullptr;
            }
            else {
                theAncestors.push(aux);
                (data < aux->data) ? aux = aux->left : aux = aux->right;
            }
        }
    }
    return theAncestors;
}

template<class T>
bool AVL<T>::find(T data) {
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (data == aux->data) {
            return true;
        }
        else {
            (data < aux->data) ? aux = aux->left : aux = aux->right;
        }
    }
    return false;
}

template<class T>
int AVL<T>::heightRecursive(TNode<T>* leRoot) {
    if (leRoot == nullptr) {
        return 0;
    }
    
    int leftHeight = heightRecursive(leRoot->left);
    int rightHeight = heightRecursive(leRoot->right);
    
    return 1 + std::max(leftHeight, rightHeight);
}

template<class T>
int AVL<T>::nodeHeight(TNode<T>* node) {
    return heightRecursive(node)-1;
} 

template<class T>
int AVL<T>::height() {
    return heightRecursive(root)-1;
}

template <class T>
int children(TNode<T>* aux) {
    // regresa la cantidad de hijos que tiene el nodo
    // Buscamos cuantos hijos tiene el nodo
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    } else if (aux->left != nullptr || aux->right != nullptr) {
        return 1;
    } else return 0;
}

template<class T>
void AVL<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The AVL is empty" << endl << endl;
    }
} 

template<class T>
void AVL<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template <class T>
bool AVL<T>::isEmpty() {
    return root == nullptr;
}

#endif
