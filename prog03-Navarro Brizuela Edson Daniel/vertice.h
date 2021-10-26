#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include "LSL.h"
#include "arista.h"
using namespace std;

template <typename T>
class Vertice{
    private:
        T dato;
        LSL<Arista<T>> aristas;
    public:
        Vertice(T dato){
            this->dato = dato;
            aristas = LSL<Arista<T>>();
        }
        bool operator==(const Vertice &rhs) const;
        bool operator!=(const Vertice &rhs) const;
        void mostrarDato();
        bool agregarArista(Vertice *destino, int peso);
        T& get();
        void borrarCoincidencias(Vertice *vertice);
        bool eliminarArista(Vertice *Vertice);
        string listaAristas();

};

template<typename T>
bool Vertice<T>::operator==(const Vertice &rhs) const {
    return dato == rhs.dato;
}

template<typename T>
bool Vertice<T>::operator!=(const Vertice &rhs) const {
    return !(rhs == *this);
}

template<typename T>
void Vertice<T>::mostrarDato(){
    cout << dato;
    cout << "\tVuelos: " << endl;
    for(size_t i = 0; i < aristas.size(); i++){
        Arista<T> arista = aristas.getData(i);
        T data = arista.get();
        cout << "\t" << data.getCiudad() << ", " << data.getPais() << " (" << arista.peso << " Km)" << endl;
    }
}

template<typename T>
bool Vertice<T>::agregarArista(Vertice *destino, int peso){
    if(aristas.buscar_dato(destino) == nullptr){
        aristas.push_back(Arista<T>(destino, peso));
        return true;
    }
    return false;
}

template<typename T>
T& Vertice<T>::get() {
    return dato;
}

template<typename T> 
void Vertice<T>::borrarCoincidencias(Vertice *vertice){
    if(aristas.buscar_dato(Arista<T>(vertice)) != nullptr){
        aristas.erase(aristas.posicion(Arista<T>(vertice)));
    }
}

template<typename T>
bool Vertice<T>::eliminarArista(Vertice *vertice){
    int pos = aristas.posicion(Arista<T>(vertice));
    if(pos == -1){
        return false;
    }
    aristas.erase(pos);
    return true;
}

template<typename T>
string Vertice<T>::listaAristas(){
    string out = "";
    for(size_t i = 0; i < aristas.size(); i++){
        out += to_string(dato.getId());
        out += "|";
        out += to_string(aristas.getData(i).get().getId());
        out += "|";
        out += to_string(aristas.getData(i).peso);
        out += "*";
    }
    return out;
}


#endif