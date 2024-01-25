#pragma once

#include <string>
using namespace std;

template <class T>
struct EdgeC {
    T sourceCity;
    T targetCity;
    int TrainTimeMinutes;
    int TrainDistance;
    int CarTimeMinutes;
    int CarDistance;
    string weight;
    EdgeC<T>* nextElement;

    EdgeC();
    EdgeC(T sourceCity, T targetCity);
    EdgeC(T sourceCity, T targetCity, int TrainTimeMinutes, int TrainDistance, int CarTimeMinutes, int CarDistance);
    bool operator==(const EdgeC<T> EdgeC);
};

/*Constructor default de la clase EdgeC que inicializa todos los valores del peso en 0*/
template <class T>
EdgeC<T>::EdgeC() {
    int TrainTimeMinutes = 0;
    int TrainDistance= 0;
    int CarTimeMinutes= 0;
    int CarDistance= 0;
}

/*Constructor de la clase EdgeC que recibe una ciudad de origen y una ciudad de destino
y los inicializa en el objeto edge */
template <class T>
EdgeC<T>::EdgeC(T sourceCity, T targetCity) {
    this->sourceCity = sourceCity;
    this->targetCity = targetCity;
    this->TrainTimeMinutes = 0;
    this->TrainDistance = 0;
    this->CarTimeMinutes = 0;
    this->CarDistance = 0; 
}

/*Sobrecarga de operador igual a (==) que regresa Verdadero si todos los atributos de los edges comparados son iguales, y falso si no*/
template <class T>
bool EdgeC<T>::operator==(const EdgeC<T> Edge) {
    return Edge.sourceCity == sourceCity && Edge.targetCity == targetCity && Edge.TrainDistance == TrainDistance && Edge.TrainTimeMinutes == TrainTimeMinutes && Edge.CarDistance == CarDistance && Edge.CarTimeMinutes == CarTimeMinutes; 
}

/*Constructor de la clase EdgeC que inicializa el objeto Edge con los parametros que recibe: una ciudad de origen, la ciudad de destino,
el tiempo y distancia en tren, y el tiempo y distancia en carro*/
template <class T>
EdgeC<T>::EdgeC(T sourceCity, T targetCity, int TrainTimeMinutes, int TrainDistance, int CarTimeMinutes, int CarDistance) {
    this->sourceCity = sourceCity;
    this->targetCity = targetCity;
    this->TrainTimeMinutes = TrainTimeMinutes;
    this->TrainDistance = TrainDistance;
    this->CarTimeMinutes = CarTimeMinutes;
    this->CarDistance = CarDistance;
    weight = to_string(TrainTimeMinutes/60) + ":" + to_string(TrainTimeMinutes%60) + " " + to_string(TrainDistance) + " " + to_string(CarTimeMinutes/60) + ":" + to_string(CarTimeMinutes%60) + " " + to_string(CarDistance);
}