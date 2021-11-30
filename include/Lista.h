#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"

using namespace std;

template <typename T>
class Lista
{
   public:
      Lista(); //Constructor por omisión.
      Lista(T); //Constructor con parámetro.
      virtual ~Lista(); //Destructor.

      unsigned int get_tamanyo() const;
      T get_primero() const;

      void agregar_primero(T);
      void agregar_tras(T, T);
      void agregar_final(T);

      void borrar(T);
      void mostrar() const;

   private:
      Nodo<T>* primero; //Puntero al primer Nodo de la Lista. 
};

#endif

//Implementaciones de los métodos de la lista:
template <typename T>
Lista<T>::Lista()
{
   this -> primero = nullptr;
}

template <typename T>
Lista<T>::Lista(T elemento)
{
   Nodo<T>* nuevo_nodo = new Nodo<T>(elemento); //Se crea un nuevo nodo.
   primero = nuevo_nodo; //El nuevo nodo se asigna como el primero de la lista.
}

template <typename T>
Lista<T>::~Lista()
{
   Nodo<T>* iter = primero;
   Nodo<T>* aux_1 = primero;

   while (iter != nullptr)
   {
      aux_1 = iter; 
      delete aux_1;
      iter = iter -> get_siguiente();
   }

   delete iter;
}

template <typename T>
unsigned int Lista<T>::get_tamanyo() const
{
   if (primero == nullptr)
   {
      cout << "---La lista esta vacia, por lo que no tiene tamanyo---" << endl << endl;
      return 0;
   }

   else
   {
      Nodo<T>* nodo_iter = primero; //Iterador que va a ir recorriendo los nodos de la lista.
      int cont = 0; //Contador de los nodos incluidos en la lista.

      while (nodo_iter != nullptr)
      {
         cont += 1;
         nodo_iter = nodo_iter -> get_siguiente();
      }

      return cont;
   }   
}

template <typename T>
T Lista<T>::get_primero() const
{
   if (primero == nullptr) //Si la lista esta vacia:
   {
      cout << "---La lista esta vacia, por lo que no tiene un primer elemento---" << endl << endl;
      return 0;
   }

   else //Si la lista no esta vacia:
   {
      return primero -> get_elemento();
   }
}

template <typename T>
void Lista<T>::agregar_primero(T elemento)
{
   Nodo<T>* nuevo_nodo = new Nodo<T>(elemento);

   if (primero == nullptr) //Si la lista esta vacia:
   {
      primero = nuevo_nodo;
   }

   else //Si la lista por lo menos tiene 1 elemento:
   {
      Nodo<T>* nodo_aux = primero;

      nuevo_nodo -> set_siguiente(nodo_aux);

      primero = nuevo_nodo;
   }
}

template <typename T>
void Lista<T>::agregar_final(T elemento)
{
   Nodo<T>* nuevo_nodo = new Nodo<T>(elemento);

   if (primero == nullptr) //Si la lista esta vacia:
   {
      primero = nuevo_nodo;
      primero -> set_siguiente(nullptr);
   }

   else //Si la lista no esta vacia:
   {
      Nodo<T>* nodo_iter = primero;

      while (nodo_iter -> get_siguiente() != nullptr)
      {
         nodo_iter = nodo_iter -> get_siguiente();
      }

      nodo_iter -> set_siguiente(nuevo_nodo);
   } 
}

template <typename T>
void Lista<T>::agregar_tras(T nuevo, T anterior)
{
   if (primero == nullptr) //Si la lista no esta vacia:
   {
      cout << "---La lista esta vacia, por lo que " << nuevo << " no se puede agregar tras " << anterior << "---" << endl << endl;
   }

   else //Si la lista no esta vacia:
   {
      Nodo<T>* iter {primero};
      bool agregado {false};

      while (iter != nullptr && !agregado)
      {
         if (iter -> get_elemento() == anterior)
         {
            Nodo<T>* nodo {new Nodo<T>(nuevo)};
            nodo -> set_siguiente(iter -> get_siguiente());
            iter -> set_siguiente(nodo);
            agregado = true;
         }   
      
         else 
         {
            iter = iter -> get_siguiente();
         }
      }   
   }
}

template <typename T>
void Lista<T>::borrar(T elemento)
{
   if (primero == nullptr) //Si la lista esta vacia:
   {
      cout << "---La lista esta vacia, por lo que el elemento " << elemento << " no se puede borrar---" << endl << endl;    
   }

   else //Si la lista no esta vacia:
   {
      Nodo<T>* aux_borrar = primero;
      Nodo<T>* anterior = nullptr;

      while ((aux_borrar != nullptr) && (aux_borrar -> get_elemento() != elemento))
      {
         anterior = aux_borrar;
         aux_borrar = aux_borrar -> get_siguiente();    
      }
      
      if (aux_borrar == nullptr)
      {
         cout << "---El elemento no existe---" << endl;
      }

      else if (anterior == nullptr)
      {
         primero = primero->get_siguiente();
         delete aux_borrar;
      }

      else
      {
         anterior -> set_siguiente(aux_borrar -> get_siguiente());
         delete aux_borrar;
      }
   }
}

template <typename T>
void Lista<T>::mostrar() const
{
   cout << "ELEMENTOS DE LA LISTA:" << endl;

   if (primero == nullptr) //Si la lista esta vacia:
   {
      cout << "---Lista vacia---" << endl << endl;
   }

    else //Si la lista no esta vacia:
    { 
      Nodo<T>* iterador = primero; //Nodo iterador encargado de recorrer la lista.
      unsigned int cont = 1; //Contador de nodos.

      while (iterador != nullptr) //Mientras no se llegue al final de la lista.
      {
         cout << "Pos " << cont << ": " << iterador -> get_elemento() << endl;
         iterador = iterador -> get_siguiente();
         cont += 1; //Se va incrementando el contador de nodos.
      }

      cout << endl;       
   }
}
