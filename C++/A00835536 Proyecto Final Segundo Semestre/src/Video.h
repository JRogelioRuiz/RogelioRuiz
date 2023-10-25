#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;

class Video {
    private:
        int idVideo, duracion, calificacion;
        string titulo, genero;
    public: 
        Video();
        Video(int ID_VID, string Title, string Genre, int Duration, int Score);
        virtual void muestra();
        virtual string info() = 0;
        
        void setIdVideo(int);
        void setDuracion(int);
        void setCalificacion(int);
        void setTitulo(string);
        void setGenero(string);

        int getIdVideo();
        int getDuracion();
        int getCalificacion();
        string getTitulo();
        string getGenero();

};

#endif