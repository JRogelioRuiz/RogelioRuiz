#ifndef Heap_h
#define Heap_h
#include <vector>

template <class T>
class Heap {
  private:
    vector<T> heap;
    void swap(int a, int b);
  public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T pop(); // Elimina el elemento de mayor prioridad
    T top();
    void push(T dato);
    void downSort(int father);
    void upSort(int Son);
    int getSize();
    void print();
    bool isEmpty();
      
};

template <class T>
Heap<T>::Heap()
{
}

template<class T>
void Heap<T>::downSort(int father) {
    // definimos variables para los hijos
    int son1;
    int son2;
    int big;
    // Recorremos la mientras father tenga hijos
    while (father * 2 + 1 < heap.size()) {
        // calculamos el indice del primer
        son1 = father * 2 + 1;
        // validamos si hay un segundo hijo
        if (father * 2 + 2 < heap.size()) {
            // Asignamos el índice del segundo hijo
            son2 = father * 2 + 2;
            // Validamos cual de los dos hijos es mayor
            heap[son1] > heap[son2] ? big = son1 : big = son2;
        } else {
            // el único hijo es el más grande
            big = son1;
        }
        if (heap[big] > heap[father]){
            // Los intercambiamos
            swap(father, big);
            // hacemos el padre igual al mayor de los hijos
            father = big;
        } else {
            father = heap.size();
        }
    }
}

template<class T>
void Heap<T>::upSort(int Son) {
    // definimos variables para los hijos
    int father;
    // Recorremos la mientras father tenga hijos
    while (Son > 0) {
        // calculamos el indice del padre 
        father = (Son - 1)/2;
        // igualamos big al padre
        if (heap[Son] > heap[father]){
            // Los intercambiamos
            swap(father, Son);
            // hacemos el indice hijo a revisar igual al la posición del padre actual
            Son = father;
        } else {
            // si el hijo no es mayor a su padre, se sale del ciclo
            Son = 0;
        }
    }
}


template <class T>
Heap<T>::Heap(vector<T> list) {
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int auxFather = heap.size()/2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (auxFather >= 0) {
        /*Ordenamiento del maxHeap*/
        downSort(auxFather);
        auxFather--;
    } 
}

template <class T>
Heap<T>::Heap(initializer_list<T> list) {
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int auxFather = heap.size()/2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (auxFather >= 0) {
        /*Ordenamiento del maxHeap*/
        downSort(auxFather);
        auxFather--;
    }
}

template<class T>
T Heap<T>::pop() { 
    if (!heap.empty()) {
    // Se toma el útlimo valor de la lista heap y se intercambia este valor con el de la raiz
    // Creamos una variable auxiliar para regresar el elemento de mayor prioridad del heap
    T aux = heap[0];
    // Intercambiamos el elemento de mayor prioridad con el último elemento
    swap(0,heap.size()-1);
    // Heap Borramos el últiom elemento de la lista
    heap.pop_back();
    // Reacomodamos hacia abajo el primer elemento
    downSort(0);
    // Regresamos el valor de mayor prioridad
    return aux;
    } else {
        throw out_of_range("Heap está vacio");
    }
}

template<class T>
T Heap<T>::top() { 
    if (!heap.empty()) {
    // Regresamos el valor de mayor prioridad
    return heap[0];
    } else {
        throw out_of_range("Heap está vacio");
    }
}

template<class T>
void Heap<T>::push(T dato) { 
    // Añadimos el dato al final de la vector del heap
    heap.push_back(dato);
    // Posición del hijo añadido al final de la lista
    int indexSon= heap.size()- 1;
    // Utilizamos upsort para poner el hijo en su posición correcta
    upSort(indexSon);
}

template <class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::print() {
    for (int i = 0; i < heap.size(); i++) {
        cout<<heap[i]<<endl;
    }
    cout<<endl;
}

template<class T>
bool Heap<T>::isEmpty() {
    return heap.empty();
}

template<class T>
int Heap<T>::getSize() {
    return heap.size();
}

#endif /*Heap_h*/