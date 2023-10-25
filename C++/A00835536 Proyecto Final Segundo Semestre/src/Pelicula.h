#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula: public Video{ 
    private:
    
    public: 
        Pelicula();
        Pelicula(int ID_VID, string Title, string Genre, int Duration, int Score);

        void muestra();
        string info();
};

#endif