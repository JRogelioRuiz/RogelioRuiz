#ifndef BST_h
#define BST_h

#include "TNode.h"
#include "Queue.h"

template<class T>
class BST {
    private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);

    public:
    
    BST();
    void insert(T data);
    void deleteData(T data);
    void print();
    
    int find(T data);
    bool isEmpty();
    int whatLevelAmI(T data);
    void ancestors(T data);
    int height();
    int heightRecursive(TNode<T>* leRoot);
    void visit(int order);
    void allOrders(TNode<T>* node, int whatOrder);
};

/*Constructor de la clase BST que inicializa la raíz del árbol como nullptr*/
template<class T>
BST<T>::BST(){
    root = nullptr;
}

/*Método insert de la clase BST que recibe un dato, 
 se recorre el árbol binario para hasta llegar a una posición donde se puede 
 añadir el dato siguiendo las reglas de un árbol binario de búsqueda*/
template <class T>
void BST<T>::insert(T data) {
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
            if (data.ipValue < aux->data.ipValue) {
                // Si es menor
                // validamos si el apuntador del lado izquierdo de aux es nullptr
                if (aux->left == nullptr) {
                    // si es nulo
                    // apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
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
                    return;
                } else {
                    // no es nulo
                    // recorremos aux al lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

/*Método allOrders que recibe un puntero y un entero para desplegar los datos en uno de los órdenes posibles
- el puntero es el nodo raíz del árbol que se quiere desplegar
- el entero representa uno de los 4 órdenes para desplegar los datos (Preorder, Inorder, Postorder, LevelByLevel)*/
template <class T>
void BST<T>::allOrders(TNode<T>* node, int orderType){
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

/*Método de la clase BST que recibe un entero entre 1-4 como parámetro
- El entero representa uno de los modos de desplegar los datos del método allOrders()*/
template<class T>
void BST<T>::visit(int order){
    if (order == 1 || order == 2 || order == 3 || order == 4) {
        allOrders(root, order);   
        cout<<endl;
    }
    else {
        throw out_of_range("Opción no válida"); 
    }     
}

/*Método de la clase BST que recibe un dato y regresa el la profundidad de 
este dato en el árbol binario, si no existe regresa -1*/
template<class T>
int BST<T>::whatLevelAmI(T data) {
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

/*Método de la clase BST que muestra en la pantalla los ancestros del dato recibido como parámetro*/
template<class T>
void BST<T>::ancestors(T data) {
    if (find(data)) {
        TNode<T>* aux = root;
        while (aux != nullptr) {
            if (data == aux->data) {
                cout<<data<<endl;
                aux = nullptr;
            }
            else {
                cout<<aux->data<<"->";
                (data < aux->data) ? aux = aux->left : aux = aux->right;
            }
        }
    }
}

/*Método de la clase BST que recibe como parámetro un dato y regresa la cantidad de veces 
que se encuentra en el árbol binario de búsqueda*/
template<class T>
int BST<T>::find(T data) {
    int ip = data.ipValue;
    // cout<<ip<<endl;
    TNode<T>* aux = root;
    int numTimesDataInBST=0;
    
    while (aux != nullptr) {
        if (ip == aux->data.ipValue) {
            numTimesDataInBST++;
        }
        // cout<<aux->data.ipValue<<endl;
        (ip < aux->data.ipValue) ? aux = aux->left : aux = aux->right;
    }
    return numTimesDataInBST;
}

/*Método de la clase BST que recibe un puntero de clase nodo que 
represetna la raiz o un punto den un arbol binario y regresa la altura de este*/
template<class T>
int BST<T>::heightRecursive(TNode<T>* leRoot) {
    if (leRoot == nullptr) {
        return 0;
    }
    
    int leftHeight = heightRecursive(leRoot->left);
    int rightHeight = heightRecursive(leRoot->right);
    
    return 1 + std::max(leftHeight, rightHeight);
}

/*Método de la clase BST que utiliza el método heightRecursive() para regresar 
la altura total del árbol binario actual*/
template<class T>
int BST<T>::height() {
    return heightRecursive(root)-1;
}

/*Método de la clase BST que recibe un puntero de la clase TNode y regresa
la cantidad de hijos que este nodo tiene*/
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

/*Método de la clase BST que recibe un dato como parámetro y lo busca en el
arbol binario para borrarlo si existe*/
template<class T>
void BST<T>::deleteData(T data) {

    if (root->data == data) {
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
            if (auxHH == nullptr) {
                // Se debe tomar en cuenta el caso donde el hijo derecho del hijo izquierdo del nodo a borrar (auxHH) es nulo: 
                root->data = auxPP->data;
                (auxPP->left == nullptr ) ? root->left = nullptr : root->left = auxPP->left;
                delete auxPP;
            } else {
                // recorremos todos los nodos que tengan un apuntador derecho diferente a nulo, hasta encontrar el que tenga right = nullptr
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
        
}

/*Método de la clase BST que utiliza el método printTree() para
imprimir todo el árbol binario en la pantalla*/
template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

/*Método de la clase BST que recibe un puntero TNode y un entero
el puntero representa el nodo a partir del cuál se imprimen los datos
el entero representa la profundidad de este nodo
el método se llama recursivamente para imprimir todos los nodos y sus hijos
con un formato*/
template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data.ipValue << endl;
        printTree(aux->left,level+1);
    }
}

/*Método de la clase BST que regresa verdadero 
si el árbol no tiene datos y falso si el árbol si tiene datos*/
template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif
