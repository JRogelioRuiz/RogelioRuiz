#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
using namespace std;

class Usuario {
    private:
        int misVideos[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
        int contadorVideos;
        string cuenta, nombre;
    public: 
        Usuario();
        
        void setCuenta(string);
        void setNombre(string);    

        string getCuenta();
        string getNombre();
        int getContadorVideos();
        int getUnIdMisVideos(int id);
        void operator+= (int id);
};

#endif