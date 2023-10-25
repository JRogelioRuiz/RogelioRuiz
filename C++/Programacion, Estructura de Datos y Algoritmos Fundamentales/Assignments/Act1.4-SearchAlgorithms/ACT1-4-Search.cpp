#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

// Búsqueda Binaria

int binarySearch (vector<int> list, int data) {
    
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

int sequentialSearch (vector<int> list, int data) {
    for (string::size_type i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }    
    return -1;
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

    printf("Runtime: %.8f seconds.\n", elapsed.count() * 1e-9);
}
// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {

    // Semilla para el generador de números aleatorios
    std::random_device rd;
    std::mt19937 generator(rd()); // Mersenne Twister engine

    // rango de números
    int minNumber = 1;
    int maxNumber = 1000000;

    // Distribución de enteros uniformes
    std::uniform_int_distribution<int> distribution(minNumber, maxNumber);

    int num = distribution(generator);

    list.push_back(num);
  }
}

int main() {

// Variables para calcular el tiempo de ejecución
chrono::high_resolution_clock::time_point begin;
chrono::high_resolution_clock::time_point end;

// Crear una lista de 1000000 de enteros
vector<int> list;
//startTime(begin);
createListInt(list, 1000000);
//getTime(begin, end);
sort(list.begin(), list.end());
//cout<<endl;

int input;
cout<<"Ingresa un numero entre 1 y 1000000: ";
cin>>input;

while (input) {
    
    startTime(begin);
    int binary = binarySearch(list,input);
    if (binary != -1) {
        cout<<"Indice obtenido con el metodo binario: " <<binary<<endl;
        getTime(begin, end); 
    } else {
        cout<<"El numero no esta en la lista"<< endl<<"Metodo Binario ";
        getTime(begin, end); 
    }

    startTime(begin);
    int sequential = sequentialSearch(list,input);
    if (sequential != -1) {
        cout<<"Indice obtenido con el metodo secuencial: " <<sequential<<endl;
        getTime(begin, end); 
    }
    else{
        cout<<"El numero no esta en la lista"<< endl<<"Metodo Secuencial ";
        getTime(begin, end);
    }
    cout<<endl<<"Ingresa un numero entre 1 y 1000000: ";
    cin>>input;
}

return 0;

}
