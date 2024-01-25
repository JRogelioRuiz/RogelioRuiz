#ifndef MinHeap_h
#define MinHeap_h

#include <vector>

template <class T>
class MinHeap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    MinHeap();
    MinHeap(vector<T> list);
    MinHeap(initializer_list<T> list);
    T pop(); // Elimina al elemento de mayor prioridad
    T top();
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
};

/*Constructor default de la clase MinHeap*/
template <class T>
MinHeap<T>::MinHeap()
{
}

/*Método de la clase heap que intercambia dos datos del vector-atributo heap*/
template <class T>
void MinHeap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

/*Método de la clase MinHeap que ordena los datos de la lista que representa el heap 
empezando desde el primer elemento padre recibido como parámetro*/
template <class T>
void MinHeap<T>::downSort(int father)
{
    // definimos variables para los hijos
    int son1;
    int son2;
    int smol;
    // Recorremos mientras father tenga hijos
    while (father * 2 + 1 < heap.size())
    {
        // Calculamos el índice del primer
        son1 = father * 2 + 1;
        // Validamos si hay un segundo hijo
        if (father * 2 + 2 < heap.size())
        {
            // Asignamos el índice del segundo hijo
            son2 = father * 2 + 2;
            // Validamos cual de los dos hijos es menor
            heap[son1] < heap[son2] ? smol = son1 : smol = son2;
        }
        else
        {
            // el único hijo es el mas grande
            smol = son1;
        }
        // Validamos si el mpás pequeño de los hijos es menor al padre
        if (heap[smol] < heap[father])
        {
            // Los intercambiamos
            swap(father, smol);
            // Hacemos el padre igual al mayor de los hijos
            father = smol;
        }
        else
        {
            // Nos salimos del ciclo
            father = heap.size();
        }
    }
}

/*Constructor de la clase MinHeap que recibe como parámetro un vector y lo ordena utilizando el método downSort()*/
template <class T>
MinHeap<T>::MinHeap(vector<T> list)
{
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Hago el ordenamiento hacia abajo
        downSort(father);
        // recorremos al siguiente padre de derecha a izquierda
        father--;
    }
}

/*Constructor de la clase MinHeap que recibe como parámetro una lista inicializadora y la ordena utilizando el método downSort()*/
template <class T>
MinHeap<T>::MinHeap(initializer_list<T> list)
{
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Hago el ordenamiento hacia abajo
        downSort(father);
        // recorremos al siguiente padre de derecha a izquierda
        father--;
    }
}

/*Método de la clase MinHeap que elimina el elemento de mayor prioridad del minHeap y lo regresa*/
template <class T>
T MinHeap<T>::pop()
{
    if (!heap.empty())
    {
        // Creamos una variable auxiliar para regresar el elemento de mayor prioridad del heap
        T aux = heap[0];
        // Intercambiamos el elemento de mayor prioridad con el último elemento
        swap(0, heap.size() - 1);
        // Borramos el último elemento de la lista
        heap.pop_back();
        // Reacomodamos hacia abajo el primer elemento
        downSort(0);
        // regresamos el valor de mayor prioridad
        return aux;
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

/*Método de la clase MinHeap que regresa elemento de mayor prioridad del minHeap*/
template <class T>
T MinHeap<T>::top()
{
    if (!heap.empty())
    {
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}


/*Método de la clase MinHeap que ingresa un dato recibido como parámetro al MinHeap*/
template <class T>
void MinHeap<T>::push(T data) {
    // Insertamos un elemento al heap
    heap.push_back(data);
    // creamos un a variabla hijo con la posición del elemento recién agregado
    int son = heap.size()-1;
    // recorremos sus ancestros
    while (son > 0) {
        // Calculamos la posición del padre
        int father = (son - 1) / 2;
        // Comparamos el valor de hijo con el padre
        if (heap[son] < heap[father]) {
            // Los intercambiamos
            swap(son, father);
            // Ahora el hijo va a tener el valor padre
            son = father;
        } else {
            // Nos salimos del ciclo
            son = 0;
        }
    }
}

/*Método de la clase MinHeap que despliega en la pantalla los valores del vector-atributo heap*/
template <class T>
void MinHeap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << endl;
    }
    cout << endl;
}

/*Método de la clase MinHeap que regresa verdadero si el heap está vacío y falso si el heap tiene elementos*/
template <class T>
bool MinHeap<T>::isEmpty()
{
    return heap.empty();
}

/*Método de la clase MinHeap que regresa la cantidad de valores en el heap*/
template<class T>
int MinHeap<T>::getSize() {
    return heap.size();
}


#endif /* MinHeap_h */