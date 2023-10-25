#ifndef List_h
#define List_h

template <class T>
class List {
    private:
    vector <T> data;
    int size;

    public:
     List();
     void print();
     void insert(T dato);
     void removeLast();
     T getData(int index);
     int getSize();
     T getMax();
};
template <class T>
List<T>::List() {
    size = 0;
}

template <>
List<float>::List() {
    size = 0;
    //cout << "Lista de flotantes" << endl;
}

template <>
List<int>::List() {
    size = 0;
    //cout << "Lista de enteros" << endl;
}

// Recibe el valor que se desea insertar; si hay espacio disponible, se coloca al final de la lista y se incrementa en 1 size.
template <class T>
void List<T>::insert(T dato) {
    data.push_back(dato);
    size++;
}

// En caso de que la lista no esté vacía, despliega el último elemento de la lista (el que está en la posición size-1) y disminuye
// en 1 el tamaño de size. En caso de que la lista esté vacía, despliega "La lista está vacía".
template <class T>
void List<T>::removeLast() {
    // Validamos que tenga elementos
    if (size > 0) { 
    // data.pop(size-1);
    cout<<data[size-1]<<endl;
    // eliminamoes el último elemento de la lista
    data.pop_back();
    // Decrementamos el tamaño de la lista
    size--;
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

// Recibe la posición de donde se desea obtener la información, y regresa el contenido de la lista en esa posición. 
// La precondición es que la posición sea un valor existente dentro de los datos (0 <= pos < size).
template <class T>
T List<T>::getData(int index) {
    if (0 <= index && index < size) { 
        return data[index];
    } else {
        throw out_of_range("El indice esta fuera del rango");
    }
}

// Regresa el valor del atributo size.
template <class T>
int List<T>::getSize() {
    return size;
}

// Regresa el valor mayor que se encuentra en la lista.
template <class T>
T List<T>::getMax() {
    if (size > 0) {
        T max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

// imprime los elementos de la lista
template <class T>
void List<T>::print() {

    for (int i = 0; i < size; i++) {
        cout<< "["<<i<<"] - "<<data[i]<<endl;
    }
    cout << endl;
}


#endif