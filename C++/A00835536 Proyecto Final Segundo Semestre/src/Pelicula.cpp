#include "Pelicula.h"
#include <iostream>
#include <string>
using namespace std;

Pelicula::Pelicula():Video() {
 int a = 0;
}

Pelicula::Pelicula(int ID_VID, string Title, string Genre, int Duration, int Score):Video(ID_VID,Title,Genre,Duration,Score) {

}

void Pelicula::muestra() {
    cout << "p " << Video::getIdVideo() << " " +  Video::getTitulo() + " " + Video::getGenero() + " " << Video::getDuracion() << " " << Video::getCalificacion() << endl;  
}

string Pelicula::info() {
    return "N/A";
}
