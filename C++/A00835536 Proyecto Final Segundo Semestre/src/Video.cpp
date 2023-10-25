# include "Video.h"

Video::Video() {
    idVideo = 0;
    titulo = "N/A";
    genero = "N/A";
    duracion = 0;
    calificacion = 0;
}

Video::Video(int ID_VID, string Title, string Genre, int Duration, int Score) {
    idVideo = ID_VID;
    titulo = Title;
    genero = Genre;
    duracion = Duration;
    calificacion = Score;
}

void Video::muestra() {
    cout << "v " << idVideo << " " + titulo + " " + genero + " " << duracion << " " << calificacion << endl;  
}

void Video::setIdVideo(int ID_VID) {
    idVideo = ID_VID;
}
void Video::setDuracion(int duration) {
    duracion = duration;
}
void Video::setCalificacion(int score) {
    calificacion = score;
}
void Video::setTitulo(string title) {
    titulo = title;
}
void Video::setGenero(string genre) {
    genero = genre;
}

int Video::getIdVideo() {
    return idVideo;
}
int Video::getDuracion() {
    return duracion;
}
int Video::getCalificacion() {
    return calificacion;
}
string Video::getTitulo() {
    return titulo;
}
string Video::getGenero() {
    return genero;
}