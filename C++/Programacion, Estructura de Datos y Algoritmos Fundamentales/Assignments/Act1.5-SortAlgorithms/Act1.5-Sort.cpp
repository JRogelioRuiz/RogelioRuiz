#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

// Función para imprimir una lista
template<class T>
void print(vector<T> &list, char current) {
    if (current == 'f' || current == 'i') {
    for (int i = 0; i < list.size(); i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
    }
    else {
    for (int i = 0; i < list.size(); i++) {
        printf("%c ", list[i]);
    }
    cout<<endl;
    }

}


// Función para intercambiar dos posiciones de una lista
template<class T>
void swap(vector<T> &list, int a, int b) {
    if (list[a] != list[b]) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }

    //print(list);
}

/*MÉTODOS DE BÚSQUEDA*/
template <class T>
int binarySearch (vector<T> list, T data) {
    
    int left = 0;
    int right = list.size()-1;

    while (left<=right) {
        int mid = left + (right-left)/2;
        if (list[mid]==data) {
            return mid;
        } else if (list[mid] > data) {
            right = mid-1;
        } else if (list[mid] < data) {
            left = mid+1;
        }
    }
    return -1;
}

template <class T>
int sequentialSearch (vector<T> list, T data) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }    
    return -1;
}
/*********************/

/*MÉTODOS DE ORDENAMIENTO*/
// Ordenamiento por intercambio
template<class T>
void swapSort(vector<T> &list) {
    int comparaciones = 0;
    int intercambios = 0;
    // Iterar la lista por cada una de las "pasadas" a toda la lista
    for (int i = 0; i < list.size(); i++) {
        // Iteramos para comparar el primer elemento con el resto
        for (int j = i+1; j < list.size(); j++) {
            //Incrementamos las comparaciones
            comparaciones++;
            // Checamos cual es menor
            if(list[i]>list[j]){
                // Intercambiamos valores en posicion i y j
                swap(list,i,j);
                // Incrementamos número de intercambios
                intercambios++;
            } 
        }
    }
    cout<<"\nLista Ordenada con Swap Sort:\n";
    cout<<"Comparaciones: "<<comparaciones<<" Intercambios: "<<intercambios<<endl;
}

// Intercambio por burbuja
template<class T>
void bubbleSort(vector<T> &list) {
    int comparisons = 0;
    int swaps = 0;
    int iter = 0;
    bool control = true;
    // Iteraciones de cada pasada
    while (control && iter < list.size()-1) {
        // Inicializamos al variable control en false
        control = false;
        // Iteraciones para comparar todos los elementos desde 0 hasta el size - iter
        for (int j=1; j<list.size()-iter; j++) {
            // Incrementamos las comparaciones
            comparisons++;
            // Comparamos j-1 con j
            if (list[j]<list[j-1]) {
                // Hacemos el intercambio
                swap(list, j-1,j);
                // Incrementamos los intercambios
                swaps++;
                // Si hubo intercambios
                control = true;
                
            }
        }
        // Incrementamos iter
        iter++;
    }
    cout<<"\nLista Ordenada con Bubble Sort:\n";
    cout<<"Comparaciones: "<<comparisons<<" Intercambios: "<<swaps<<endl;
}


// Intercambio por Inserción
template<class T>
void insertionSort(vector<T> &list) {
    int comparisons = 0;
    int swaps = 0;
    for (int i = 1; i < list.size(); i++) {
        int j = i-1;
        while (j >= 0) {
            // Incrementamos las comparaciones
            comparisons++;
            // comparamos j con j+1
            if (list[j+1] < list[j]){
                // Hacemos el intercambio
                swap(list, j, j+1);
                // Incrementamos los intercambios
                swaps++;
            } else {
                j = -1;
            }
        // decrementamos el valor de j
        j--;
        }
    } 
    cout<<"\nLista Ordenada con Insertion Sort:\n";
    cout<<"Comparaciones: "<<comparisons<<" Intercambios: "<<swaps<<endl;  
}


// Intercambio por Selección
template<class T>
void SelectionSort(vector<T> &list) {
    int comparisons = 0;
    int swaps = 0;
    // Ciclo por cada elemento excepto el último
    for (int i = 0; i <list.size()-1; i++) {
        // creamos una variable para identificar el indice con el valor más pequeño
        int min = i;

        // Iteramos en cada posición para encontrar el menor
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos las comparaciones
            comparisons++;
            // Comparamos j con min
            if (list[j]<list[min]) {
                // redefinimos el indice mínimo
                min = j; 
            }
        }   
        // Validamos que el intercambio sea necesario
        if (min != i) {
            // Se intercambia [i] con el valor más pequeño [min]
            swap(list,min,i);
            // incrementamos cantidad de swaps
            swaps++;
        }
    }
    cout<<"\nLista Ordenada con Selection Sort:\n";
    cout<<"Comparaciones: "<<comparisons<<" Intercambios: "<<swaps<<endl;
}


template <class T>
void merge(vector<T> &list, int left, int mid, int right) {
    // Creamos la lista del lado izquierdo (left -> mid)
    vector<T> tempListLeft;
    for (int i = left; i <= mid; i++) {
        tempListLeft.push_back(list[i]);
    }

    // Creamos la lista del lado derecho (mid+1 -> right)
    vector<T> tempListRight;
    for (int j = mid+1; j <= right; j++) {
        tempListRight.push_back(list[j]);
    }

    // Creamos un indice auxiliar igual a left
    int auxindex = left;

    // Creamos dos índices auxiliares, uno para cada lista
    int leftIndex = 0;
    int rightIndex = 0;

    // Iteramos mientras haya elementos por comparar en las dos listas
    while (leftIndex < tempListLeft.size() && rightIndex < tempListRight.size()) {
        // Comparamos el valor en el índice izquierdo de la lista izquierda
        // con el valor en el índice derecho de la lista derecha
        if (tempListLeft[leftIndex] < tempListRight[rightIndex]){
            // El valor del lado izquierdo es menor
            list[auxindex] = tempListLeft[leftIndex];
            // Incrementamos el índice izquierdo
            leftIndex++;
        }
        else {
            // El valor del lado derecho es menor o igual
            list[auxindex] = tempListRight[rightIndex];
            // Incrementamos el índice izquierdo
            rightIndex++;
        }
        // Incrementamos el valor del auxIndex
        auxindex++;
    }
    // Vaciar los elementos pendientes de la izquierda
    while (leftIndex < tempListLeft.size()) {
        // El valor del lado izquierdo es menor
        list[auxindex] = tempListLeft[leftIndex];
        // Incrementamos el índice izquierdo
        leftIndex++;
        // Incrementamos el valor del auxIndex
        auxindex++;
    }

    // Vaciar los elementos pendientes de la derecha
    while (rightIndex < tempListRight.size()) {
        // El valor del lado derecho es menor o igual
        list[auxindex] = tempListRight[rightIndex];
        // Incrementamos el índice izquierdo
        rightIndex++;
        // Incrementamos el valor del auxIndex
        auxindex++;
    }
}


template <class T> 
void mergeSort(vector<T> &list, int left, int right) {
    // condición de control
    if (left < right) {
        // obtenemos la mitad de los elementos
        int mid = left + (right - left)/2;
        // Odrenamos el lado izquierdo de la lista
        mergeSort(list, left, mid);
        // Ordenamos el lado derecho de la lista 
        mergeSort(list, mid+1, right);
        // El proceso de comparación entre las listas para ordenar la sublista
        merge(list, left, mid, right);
    } 
}

template <class T> 
void quickSort(vector<T> &list, int left, int right) {  
    int aux = left-1;
    if (left < right) {
    // Ciclo for que itera desde left hasta right-1
    for (int index = left; index < right; index++) {
        // Se checa si el elemento en la posición del índice es menor a el pivote
        if (list[index] < list[right]) {
            // Si el elemento del índice es menor, se aumenta el índice auxiliar
            // y se intercambian el elemento del pivote con el del índice auxiliar 
            aux++; 
            swap(list, aux, index);
        }  
    }
    // Al final del ciclo for se aumenta 1 al auxiliar, y se intercambia con el pivote.
    aux++;
    swap(list, aux, right);

    // Se manda a llamar la función quicksort para ambos lados del pivote ya ordenado   
    // del lado izquierdo se llama con el left original, con el pivote menos 1.
    quickSort(list, left,aux-1);
    // del lado derecho se llama con el pivote +1 y el right original
    quickSort(list, aux+1, right);
    }
}

/* QUICKSORT VISTO EN CLASE
template<class T>
int getPivot(vector<T> &list, int left, int right) {
    //definimos el pivote
    int pivot = right;
    //Inicializamos el indice Auxiliar
    int auxIndex = left-1;
    //Recorremos la lista desde left hasta right-1 para comparar cada elemento con el pivote
    for (int index = left; index < right; index++){
        if (list[index] < right[pivot]) {
            //Incrementamos el valor del Índice auxiliar
            auxIndex++;
            //Intercambiamos index con auxIndex
            swap(list, pivot, auxIndex);
        }
    }
    //Incrementamos el valor del índice auxiliar
    auxIndex++;
    //Intercambiamos el index con auxIndex
    swap(list,auxIndex,pivot);
    //Regresamoe el valor de la posición final del pivote
    return auxIndex;

}

template<class T>
void quickSort(vector<T> &list, int left, int right) {
    // Mi condición de control es cuandl la lista es de un elemento 
    if (left < rigjt) {
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        //quickSort(list, pivot+1, right);
    }
}
*/


template<class T>
void shellSort(vector<T> &list, int intervalo) {
    
    int index = 0;
    int aux = index + intervalo;
    int hold=0;
    bool needsToGoBackwards=0;
    
    while (intervalo >= 1) {
        if (!needsToGoBackwards) {
            if(aux > list.size()-1 || aux < 0){
                index = 0;
                intervalo = intervalo /2;
                aux = index + intervalo;
            } else if (list[index] > list[aux]) {
                swap(list, index, aux);
                needsToGoBackwards = 1;
                hold = index+1;
                aux = index-intervalo;
            } else {
                index++;
                aux++;
            }
    
        } else if (needsToGoBackwards) {
            if(aux > list.size()-1 || aux < 0 || list[index] > list[aux]){
                index = hold;
                aux = index + intervalo;
                needsToGoBackwards = 0;
            } else  {
                swap(list, index, aux);
                index = aux;
                aux = index-intervalo;
            } 
        }
    }
}

/***********************/

template <class T>
void createList(vector<T> &list, T quantity, T upperLimit, char type)
{
    list.clear();
  
    if (type == 'i' || type == 'c') {
        for (int i = 0; i < quantity; i++)
        {

            // Semilla para el generador de números aleatorios
            random_device rd;
            mt19937 generator(rd()); // Mersenne Twister engine

            // rango de números
            int minNumber;
            (type == 'c') ? minNumber = 33 : minNumber = 1;
            int maxNumber = upperLimit;

            // Distribución de enteros uniformes
            uniform_int_distribution<int> distribution(minNumber, maxNumber);

            int num = distribution(generator);

            list.push_back(num);
        }
    }
    if (type == 'f')
    {
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        
        int minNumber = 1.0;
        int maxNumber = upperLimit;

        std::uniform_real_distribution<> dis(minNumber, maxNumber);
        
        for (int n = 0; n < quantity; ++n)
        {
            // Use dis to transform the random unsigned int generated by gen into a 
            // double in [1, 2). Each call to dis(gen) generates a new random double
            float num = dis(gen);
            list.push_back(num);
        }
    }
}

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Runtime: %.9f seconds.\n", elapsed.count() * 1e-9);
}

int main() {

    int input = 1;
    int inputAux = 0;
    int wantPrint = 1;
    int position4Search=0;

    float inputF1 = 0;
    float inputF2 = 0;

    char current = 'i';

    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    
    printf("Algoritmos de Ordenamiento y Busqueda\nSeleccione una opcion:\n");
    vector<int> list{15,7,3,9,12,5,2,11};
    vector<float> listf;


    while (input) {
    printf("\n1. Opciones para Crear Lista\n2. Buscar un Valor en la Lista\n3. Opciones para Ordenar Lista\n4. Dejar de / Volver a imprimir lista Actual\n0. Terminar progama\n");
    
    if (wantPrint) {
    printf("Lista Actual: \n");
    if(current == 'f') {
        print(listf, current);
    } else  {
       print(list, current);
    }
    }

    cin>>input;

    if (input == 1 || input == 2 || input == 3 || input == 4) { 
        if (input == 1) {
            printf("-Opciones para Crear Lista\n1. Lista de Enteros\n2. Lista de Numeros Flotantes\n3. Lista de Caracteres\n");
            cin>>input;
            if(input == 1) {
                printf("Ingresar limite superior de lista de Enteros positivos:\n"); 
                cin>>input;
                printf("Ingresar Cantidad de Valores:\n"); 
                cin>>inputAux; 
                createList(list, inputAux, input,current);
            }
            else if (input == 2) {
                printf("Ingresar limite superior de lista de Numeros Flotantes positivos:\n"); 
                cin>>inputF1;
                printf("Ingresar Cantidad de Valores:\n"); 
                cin>>inputF2; 
                current = 'f';
                createList(listf, inputF2, inputF1, current);
            } 
            else if (input == 3) {
                printf("Ingresar Cantidad de Valores:\n"); 
                cin>>input; 
                current = 'c';
                createList(list, input, 126, current);
            } 
        } else if (input == 2) {
            printf("-Opciones de Busqueda\n1. Busqueda Secuencial\n2. Busqueda Binaria\n");
            cin>>input;
            if (input == 1) {
            printf("Ingresar el Valor que desea buscar:\n"); 
            if(current == 'f') {
                cin>>inputF1; 
                if(input == 1) {
                startTime(begin);    
                position4Search = sequentialSearch(listf, inputF1);
                getTime(begin, end); 

            }
            } else if (current == 'i'|| current == 'c') {
                cin>>inputAux;
                startTime(begin);    
                position4Search = sequentialSearch(list, inputAux);
                getTime(begin, end);  
            } 
            }
            else if (input == 2) {
            printf("Ingresar el Valor que desea buscar:\n"); 
            if(current == 'f') {
                cin>>inputF1; 
                if(input == 1) {
                startTime(begin);    
                position4Search = binarySearch(listf, inputF1);
                getTime(begin, end); 

            }
            } else if (current == 'i'|| current == 'c') {
                cin>>inputAux;
                startTime(begin);    
                position4Search = binarySearch(list, inputAux);
                getTime(begin, end);  
            } 
            }
            if (input == 1) {
                (position4Search == -1) ? cout<<"Valor No encontrado "<<endl : cout<<"Valor encontrado en posicion: "<<position4Search<<endl; 
            }  else if (input == 2) {
                (position4Search == -1) ? cout<<"Valor No encontrado, checar que la lista este ordenada "<<endl : cout<<"Valor encontrado en posicion: "<<position4Search<<endl; 
            } 

        } else if (input == 3) {
            printf("-Opciones para Ordenar La Lista\n");
            printf("1. Swap Sort\n2. Bubble Sort\n3. Selection Sort\n4. Insertion Sort\n5. Merge Sort\n6. Quick Sort\n7. Shell Sort\n");
            cin>>input;

            if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7 ) {
                if (input == 1) {
                    startTime(begin); 
                    (current == 'f') ? swapSort(listf) : swapSort(list) ;
                    getTime(begin, end);
                } else if (input == 2) {
                    startTime(begin); 
                    (current == 'f') ? bubbleSort(listf) : bubbleSort(list) ;
                    getTime(begin, end);
                } else if (input == 3) {
                    startTime(begin); 
                    (current == 'f') ? SelectionSort(listf) : SelectionSort(list) ;
                    getTime(begin, end);
                } else if (input == 4) {
                    startTime(begin); 
                    (current == 'f') ? insertionSort(listf) : insertionSort(list) ;
                    getTime(begin,end);
                } else if (input == 5) {
                    startTime(begin); 
                    (current == 'f') ? mergeSort(listf, 0, listf.size()-1) : mergeSort(list,0, list.size()-1) ;
                    cout<<"\nLista Ordenada con Merge Sort:\n";
                    getTime(begin, end);
                } else if (input == 6) {
                    startTime(begin); 
                    (current == 'f') ? quickSort(listf,  0, listf.size()-1) : quickSort(list,  0, list.size()-1) ;
                    cout<<"\nLista Ordenada con Quick Sort:\n";
                    getTime(begin, end);
                } else if (input == 7) {
                    startTime(begin); 
                    (current == 'f') ? shellSort(listf, listf.size()/2) : shellSort(list, list.size()/2) ;
                    cout<<"\nLista Ordenada con Shell Sort:\n";
                    getTime(begin, end);
                }
                if(wantPrint)
                (current == 'f') ? print(listf, current) : print(list, current);

            } 
        } else if (input == 4) {
                (wantPrint) ? wantPrint = 0 : wantPrint = 1;
        }

    } else if (input == 0) { 
       input = 0;
    }
    else {
        cout<<"Opcion no valida\n";
    } 

    }
    return 0;
}
