#include "Episodio.h"

Episodio::Episodio():Video() {
    numeroEp = 0;
    serie = "N/A";
    numeroTemporada = 0;
}

Episodio::Episodio(int ID_VID, string Title, string Genre, int Duration, int Score, string tituloSerie, int episodio, int temporada):Video(ID_VID,Title,Genre,Duration,Score) {
    numeroEp = episodio;
    serie = tituloSerie;
    numeroTemporada = temporada;
}

void Episodio::muestra() {
    cout << "e " << Video::getIdVideo() << " " +  Video::getTitulo() + " " + Video::getGenero() + " " << Video::getDuracion() << " " << Video::getCalificacion()<<" "+ serie + " "<< numeroEp<< " " << numeroTemporada<< endl;
}

void Episodio::setNumeroEp(int episode) {
    numeroEp = episode;
}
void Episodio::setNumeroTemporada(int season) {
    numeroTemporada = season;
}
void Episodio::setSerie(string series) {
    serie = series;
}
int Episodio::getNumeroEp() {
    return numeroEp;
}
int Episodio::getNumeroTemporada() {
    return numeroTemporada;
}
string Episodio::getSerie() {
    return serie;
}

string Episodio::info() {
    return serie;
}