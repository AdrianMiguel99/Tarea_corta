#include<iostream>

#include "../include/Lista.h"

using namespace std;

int main()
{
    cout << "PRUEBAS DE LA PLANTILLA DE LA LISTA ENLAZADA:" << endl;
    
    Lista<double> mi_lista; //Lista de doubles.

    mi_lista.agregar_tras(4.0, 3.0);
    mi_lista.borrar(7.0);
    mi_lista.mostrar();
    mi_lista.agregar_primero(3.1);
    mi_lista.mostrar();
   
    Lista<char> mi_lista2('a'); //Lista de caracteres.

    mi_lista2.agregar_tras('d', 'a');
    mi_lista2.borrar('a');
    mi_lista2.agregar_final('I');
    mi_lista2.agregar_primero('M');
    mi_lista2.borrar('I');
    mi_lista2.mostrar();
    cout << "mi_lista2.get_tamanio(): " << mi_lista2.get_tamanyo() << endl;
    mi_lista2.mostrar();
    
    return 0;
}
