#include <iostream>
#include <vector>
using namespace std;
#include "List.h"

int main() {

    List<int> list;

    // insertamos datos en la lista
    cout<<"Valores instertados: {5,10}"<<endl;
    list.insert(5);
    list.insert(10);
    list.print();
    //list.insert(15);

    /* Probamos el método removeLast con su caso de error*/  
    try {
        
        cout<<"valor removido:"<<endl;
        list.removeLast();
        cout<<endl;
        cout<<"se imprime la lista para corroborar"<<endl;
        list.print();

        cout<<"valor removido:"<<endl;
        list.removeLast();
        cout<<endl;
        cout<<"se imprime la lista para corroborar"<<endl;
        list.print();

        list.removeLast();

    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    
    cout<<endl;

    cout<<"Nueva lista para probar getMax()"<<endl;
    List<int> listM;
    // insertamos datos en la lista
    listM.insert(90);
    listM.insert(100);
    listM.insert(95);
    listM.insert(101);
    listM.print();
    cout <<"Maximo de la lista"<<endl<<listM.getMax()<<endl<<endl;
    
    cout<<"Probamos getData() con el indice [2] de la lista anterior"<<endl;
    cout<<listM.getData(2)<<endl<<endl;

    cout<<"Probamos getSize() con la lista anterior"<<endl;
    cout<<listM.getSize()<<endl<<endl;

    List<float> listF;
    cout<<"Más listas: "<<endl;
    // insertamos datos en la lista
    listF.insert(5.5);
    listF.insert(10.5);
    listF.insert(15.5);

    // imprimimos los datos de la lista
    listF.print();

    List<string> listS;

    // insertamos datos en la lista
    listS.insert("Hola");
    listS.insert("Crayola");
    listS.insert("Tu cajita de colores");

    // imprimimos los datos de la lista
    listS.print();
    
    return 0;
}