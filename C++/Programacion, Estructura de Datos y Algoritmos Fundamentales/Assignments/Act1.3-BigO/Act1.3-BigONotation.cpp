#include <iostream>
#include <vector>
using namespace std;

/*Función que suma los valores impares de un vector de manera iterativa
Es de Orden O(n)*/
int sumaImparesIterativa(vector<int>& vect) {   
    int sumaImpares=0;
    for (int i = 0;  i < vect.size(); i++) {
        if (vect[i]%2==1) {
            sumaImpares+=vect[i];
        }
    }
    return sumaImpares;
}


/*Función que suma los valores impares de un vector de manera recursiva
Es de orden O(n)*/

int sumaImparesRecursiva(vector<int>& vect, int size) {   
    if (size == 0) {
        return 0;
    }
    else {
        if (vect[size-1]%2==1) { 
            return vect[size-1] + sumaImparesRecursiva(vect, size-1);
        }
        else {
            return sumaImparesRecursiva(vect, size-1);
        }
    }
}

int main() {
    vector<int> vect{1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19};
    cout<<sumaImparesIterativa(vect)<<endl;
    cout<<sumaImparesRecursiva(vect,vect.size())<<endl<<"Las funciones sumaImparesIterativa y sumaImparesRecursiva ambas son de orden O(n)"<<endl;
    return 0;
}