#ifndef ARISTA_H
#define ARISTA_H

#include "vertice.h"

template <typename T> class Vertice;

template <typename T>
class Arista{
    public:
        Vertice<T> *destino;
        int peso;
        Arista(Vertice<T> *destino, int peso){
            this->destino = destino;
            this->peso = peso;
        }
        Arista(Vertice<T> *destino){
            this->destino = destino;
        }
        bool operator==(const Arista &rhs) const;
        bool operator!=(const Arista &rhs) const;
        T& get();

};

template<typename T>
bool Arista<T>::operator==(const Arista &rhs) const {
    return *destino == *rhs.destino;
}

template<typename T>
bool Arista<T>::operator!=(const Arista &rhs) const {
    return !(rhs == *this);
}

template<typename T>
T &Arista<T>::get() {
    return destino->get();
}


#endif