# include "Usuario.h"

Usuario::Usuario() { 
    contadorVideos = 0;
    nombre = "N/A";
    cuenta = "N/A";
}

void Usuario::setCuenta(string account) {
    cuenta = account;
}
void Usuario::setNombre(string name) {
    nombre = name;
}    

string Usuario::getCuenta() {
    return cuenta; 
}
string Usuario::getNombre() {
    return nombre;
}

int Usuario::getContadorVideos() {
    return contadorVideos;
}
int Usuario::getUnIdMisVideos(int idVid) {
    if ((idVid < contadorVideos) && (idVid >= 0)) {
        return misVideos[idVid];
    }
    else {
        cout << "Índice no válido";
        return 0;
    }
}

void Usuario::operator+=(int idVid) {
    if (contadorVideos < 20) {
        int inVideos = 1;
        for (int i = 0; i < contadorVideos; i++) {
            if (misVideos[i] == idVid) {
                inVideos = 0;
                cout << "El video que se quiere añadir ya existe"<<endl;
            } else {
                continue;
            }
        } 
        if(inVideos) {
            misVideos[contadorVideos] = idVid;
            cout<<"Video Agregado"<<endl;
            contadorVideos++;
        } 
    } else {
        cout<<"Lista de Usuario Llena"<<endl;
    }
}