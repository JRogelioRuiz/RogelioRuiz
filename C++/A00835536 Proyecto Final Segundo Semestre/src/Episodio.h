#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
#include <iostream>

class Episodio: public Video {
    private:
        int numeroEp, numeroTemporada;
        string serie;
    public: 
        Episodio();
        Episodio(int ID_VID, string Title, string Genre, int Duration, int Score, string tituloSerie, int episodio, int temporada);
        void muestra();
        string info();

        void setNumeroEp(int);
        void setNumeroTemporada(int);
        void setSerie(string);
        int getNumeroEp();
        int getNumeroTemporada();
        string getSerie();
        
};

#endif