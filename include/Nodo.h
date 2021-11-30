#ifndef NODO_H
#define NODO_H

#include<iostream>

using namespace std;

/**
 * Archivo Header de la clase Nodo.
 */
template <typename T>
class Nodo
{
   public:
      Nodo(T);
      virtual ~Nodo();
      void set_elemento(T);
      T get_elemento() const;
      void set_siguiente(Nodo*);
      Nodo<T>* get_siguiente() const;

   private:
      T elemento; // Valor de tipo T almacenado en el Nodo.
      Nodo<T>* siguiente; // Puntero al siguiente Nodo.
};

#endif

template <typename T>
Nodo<T>::Nodo(T elemento)
{
   this -> elemento = elemento;
   this -> siguiente = nullptr;
}

template <typename T>
Nodo<T>::~Nodo()
{
   cout << "Nodo " << this -> elemento << " destruido" << endl << endl;
}

template <typename T>
void Nodo<T>::set_elemento(T elemento)
{
   this -> elemento = elemento;
}

template <typename T>
T Nodo<T>::get_elemento() const
{
   return this -> elemento;
}

template <typename T>
void Nodo<T>::set_siguiente(Nodo<T>* siguiente)
{
   this -> siguiente = siguiente;
}

template <typename T>
Nodo<T>* Nodo<T>::get_siguiente() const
{
   return this -> siguiente;
}
