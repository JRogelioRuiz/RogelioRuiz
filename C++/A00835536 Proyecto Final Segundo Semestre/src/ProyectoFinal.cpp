#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Usuario.h"

using namespace std;

// Equivalente a función explode(), crea vector de strings separando el original con el caracter del parámetro "delim" 
std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
        
    }
    return result;
}

int main()
{
ifstream inputFile1("Ejemplo-2.txt");

int numLineasArchivo = 0;
string noUsar;
if (inputFile1.is_open()){
while (!inputFile1.eof()) {
    getline(inputFile1, noUsar);    
    numLineasArchivo++;
}
inputFile1.close(); 
}

ifstream inputFile("Ejemplo-2.txt");

Video *Videos[numLineasArchivo];
Usuario elUsuario;

if (inputFile.is_open())
{
    string line;
    //cout<<"si abrio"<<endl;
    int a = 0;
   while (getline(inputFile, line))
   {
    auto vectorConStrings = explode(line, ' ');

    // checar si es "e" o "p", ingresar datos correspondientes
    if (vectorConStrings[0] == "p") {
        //convertir VectorConStrings[1] a int
        int IDVIDEO = stoi(vectorConStrings[1]);
        //usar explode con VectorConStrings[2] "titulo", checar size() y juntarlo todo en un string
        auto Vectitulo = explode(vectorConStrings[2], '_');
        string titulo = "";
        for (int i = 0; i < Vectitulo.size(); i++) {
            if (i == 0) {
            titulo = titulo + Vectitulo[i];
            } else {
                titulo = titulo + " " + Vectitulo[i];
            }
        }

        // el género VectorConStrings[3] es una sola palabra, pasar como tal al constructor
        string genero = vectorConStrings[3];

        // convertir VectorConStrings[4] duracion a int
        int duration = stoi(vectorConStrings[4]);
        
        // convertir VectorConStrings[5] calificación a int 
        int score = stoi(vectorConStrings[5]);

        Videos[a] = new Pelicula(IDVIDEO,titulo,genero,duration,score); /*PONER DATOS CORRESPONDIENTES PARA PELICULA*/
    } else if (vectorConStrings[0] == "e") {
        //convertir VectorConStrings[1] a int
        int IDVIDEO = stoi(vectorConStrings[1]);

        //usar explode con VectorConStrings[2] "titulo", checar size() y juntarlo todo en un string
        auto Vectitulo = explode(vectorConStrings[2], '_');
        string titulo = "";
        for (int i = 0; i < Vectitulo.size(); i++) {
            if (i == 0) {
            titulo = titulo + Vectitulo[i];
            } else {
                titulo = titulo + " " + Vectitulo[i];
            }
        }

        // el género VectorConStrings[3] es una sola palabra, pasar como tal al constructor
        string genero = vectorConStrings[3];

        // convertir VectorConStrings[4] duracion a int
        int duration = stoi(vectorConStrings[4]);
        
        // convertir VectorConStrings[5] calificación a int 
        int score = stoi(vectorConStrings[5]);

        // usar explode con VectorConStrings[6] "titulo_serie", checar size() y juntarlo todo en un string
        auto Vectitulo_serie = explode(vectorConStrings[6], '_');
        string titulo_serie = "";
        for (int i = 0; i < Vectitulo_serie.size(); i++) {
            if (i == 0) {
            titulo_serie = titulo_serie + Vectitulo_serie[i];
            } else {
                titulo_serie = titulo_serie + " " + Vectitulo_serie[i];
            }
        }

        // convertir VectorConStrings[7] episodio a int
        int episodio = stoi(vectorConStrings[7]);
        
        // convertir VectorConStrings[8] temporada a int
        int temporada = stoi(vectorConStrings[8]);

        Videos[a] = new Episodio(IDVIDEO,titulo,genero,duration,score,titulo_serie,episodio,temporada); /*PONER DATOS CORRESPONDIENTES PARA EPISODIO*/
    }

    //cout<<line<<endl;
    a++;
   }
}
else
{
cout<<"No se abrio el archivo de datos";
}

int opcionElegida;

// Ciclo while para la ejecución del programa. Despliega el menu y sus respectivas
// operaciones hasta que se ingrese como opcionElegida el número 0.
while (opcionElegida != 0) {
cout<<endl;
cout<< "----MENU DE OPCIONES----"<<endl;
cout<< "0. Terminar operacion"<<endl;
cout<< "1. Consultar lista de videos disponibles"<<endl;
cout<< "2. Consultar lista de videos por calificacion"<<endl;
cout<< "3. Consultar lista de videos por genero"<<endl;
cout<< "4. Ver datos del Usuario"<<endl;
cout<< "5. Modificar perfil del Usuario"<<endl;
cout<< "6. Agregar video a la lista del Usuario"<<endl;
cout<< "7. Buscar videos por Serie"<<endl;
cout<<"--Ingrese el numero de la operacion que desea realizar--"<<endl;
cin>>opcionElegida;

//Implementación de cada caso
if (opcionElegida == 1) {
    cout<<"LISTA DE VIDEOS DISPONIBLES: "<<endl<<endl;
    // ciclo for que itera en todos los videos y los despliega
    for (int i = 0; i < numLineasArchivo; i++) {
        Videos[i]->muestra();
    }
} else if (opcionElegida == 2) {
    int calificacionDeseada = 0;
    cout<<"Ingrese Calificacion deseada: "<<endl;
    cin>>calificacionDeseada;
    cout<<endl; 
    int noExisteCalificacion = 1;

    // ciclo for que itera en todos los videos y checa si tienen la calificacion deseada
    // antes de desplegarlos
    for (int i = 0; i < numLineasArchivo; i++) {
        if (Videos[i]->getCalificacion() == calificacionDeseada) {
            Videos[i]->muestra();
            noExisteCalificacion = 0;
    }  
    }
    // Casos de error 
    if (!((calificacionDeseada ==0)||(calificacionDeseada ==1)||(calificacionDeseada ==2)||(calificacionDeseada ==3)||(calificacionDeseada ==4)||(calificacionDeseada ==5))){
        cout << "La calificacion tiene que ser entre 0 y 5"<<endl;    
    }
    else if (noExisteCalificacion) {
        cout << "No hay videos con la Calificacion ingresada"<<endl;
    }

} else if (opcionElegida == 3) {
    string generoDeseado = "N/A";
    cout<<"Ingrese nombre de Genero deseado: "<<endl;
    cin>>generoDeseado;
    cout<<endl;
    int noExisteGenero = 1;
    // ciclo for que itera en todos los videos y checa si son del género deseado
    // antes de desplegarlos
    for (int i = 0; i < numLineasArchivo; i++) {
        if (Videos[i]->getGenero() == generoDeseado) {
            if(noExisteGenero) {noExisteGenero = 0;}
            Videos[i]->muestra();
        }
    }
    if (noExisteGenero) {
        cout << "No hay videos del genero ingresado"<<endl;
    }
      
} else if (opcionElegida == 4) {
    cout<<"DATOS DEL USUARIO: "<<endl;
    cout<<" Cuenta del Usuario: " + elUsuario.getCuenta()<<endl;
    cout<<" Nombre de Usuario: " + elUsuario.getNombre()<<endl;
    cout<<" Cantidad de videos en lista del Usuario: "<<elUsuario.getContadorVideos()<<endl<<endl;
    cout<<" Lista del Usuario: "<<endl;
    
    if (elUsuario.getContadorVideos() == 0) {
        cout<<" El usuario no tiene Videos"<<endl;
    }
    else {
        // ciclo for que itera en todos los videos del usuario 
        for (int i = 0; i < elUsuario.getContadorVideos(); i++) {
            // ciclo for que itera en todos los videos y checa si corresponden
            // al video del usuario actual, si sí, los despliega
            for(int j = 0; j < numLineasArchivo; j++) {
                if (elUsuario.getUnIdMisVideos(i) == Videos[j]->getIdVideo()) {
                    Videos[j]->muestra();
                } 
            }
        }
    }
} else if (opcionElegida == 5) {
    // se piden con getline los atributos de cuenta y nombre para el usuario
    string nombreUsuario, cuentaUsuario;
    cout<<"Ingrese la Cuenta: "<<endl;
    string elEnter;
    getline(cin, elEnter);
    getline(cin,cuentaUsuario);
    cout<<endl<<"Ingrese el nombre de Usuario"<<endl;
    getline(cin,nombreUsuario);
    elUsuario.setCuenta(cuentaUsuario);
    elUsuario.setNombre(nombreUsuario);       
} else if (opcionElegida == 6) {
    int idVideoAgregar = 1;
    int videoAgregado = 0;
    cout<<"INGRESE EL ID DEL VIDEO QUE SE AGREGARA A LA LISTA: "<<endl;

    // Ciclo while que recibe un valor entero hasta que el usuario termine la operacion
    // o hasta que se ingrese un ID de un video válido, para agregarlo a la lista del usuario
    while ((idVideoAgregar != 0)&&(!videoAgregado)) {
        cin>>idVideoAgregar;
        int noExisteID_VIDEO = 1;
        
        // ciclo for que itera en todos los videos y checa si su ID corresponde al ID ingresado
        // por el usuario, si sí, lo agrega a la lista con el operador +=
        for (int i = 0; i < numLineasArchivo; i++) {
            if (Videos[i]->getIdVideo() == idVideoAgregar) {
                if(noExisteID_VIDEO) {noExisteID_VIDEO = 0;}
                elUsuario+=idVideoAgregar;
                videoAgregado = 1;
            }
        } 
        if (idVideoAgregar == 0) {
            cout << "Operacion Terminada "<<endl; 
        } else if (noExisteID_VIDEO) {
            cout << "La ID ingresada no existe "<<endl;
        }
    }
} else if (opcionElegida == 7){
    string serieDeseada;
    cout<<"Ingrese nombre de la Serie deseada: "<<endl;
    string elEnter;
    getline(cin, elEnter);
    getline(cin, serieDeseada);
    
    cout<<endl;
    int noExisteSerie = 1;
    // ciclo for que itera en todos los videos y checa si son de la serie deseada
    // antes de desplegarlos
    for (int i = 0; i < numLineasArchivo; i++) {
        if (Videos[i]->info() == serieDeseada) {
            if(noExisteSerie) {noExisteSerie = 0;}
            Videos[i]->muestra();
        }
    }
    if (noExisteSerie) {
        cout << "No hay videos del genero ingresado"<<endl;
    }
      
} else if (opcionElegida == 0) {
    cout<<"Operacion Terminada "<<endl<<endl;
}
else {
    cout<<"Opcion invalida"<<endl;
}


}


return 0;
}
