#ifndef GRAFO_H
#define GRAFO_H

#include "aeropuerto.h"
#include "vertice.h"

template <typename T>
class Grafo{
    private: 
        LSL<Vertice<T>> vertices;
    public:
        Grafo(){
            vertices = LSL<Vertice<T>>();
        }
        bool agregarVertice(T element);
        bool agregarArista(T origen, T destino, int peso);
        void mostrarGrafo();
        void mostrarVertices();
        bool eliminarVertice(T element);
        bool eliminarArista(T origen, T destino);
        bool guardar();
        bool cargar();
};

template <typename T>
bool Grafo<T>::agregarVertice(T element){
    if(vertices.buscar_dato(Vertice<T>(element))==nullptr){
        vertices.push_back(Vertice<T>(element));
        return true;
    }
    return false;
}

template <typename T>
bool Grafo<T>::agregarArista(T origen, T destino, int peso){
    Vertice<T> *vertice_origen = vertices.buscar_dato(origen);
    Vertice<T> *vertice_destino = vertices.buscar_dato(destino);
    if(vertice_origen == nullptr || vertice_destino == nullptr){
        return false;
    }
    
    return vertice_origen->agregarArista(vertice_destino, peso);
}

template <typename T>
void Grafo<T>::mostrarGrafo(){
    for(size_t i = 0; i < vertices.size(); i++){
        vertices.getData(i).mostrarDato();
    }
}

template <typename T>
void Grafo<T>::mostrarVertices(){
    for(size_t i = 0; i < vertices.size(); i++){
        T vertice = vertices.getData(i).get();
        cout << vertice.getId() << ": " << vertice.getCiudad() << ", " << vertice.getPais() << endl;
    }
}

template <typename T>
bool Grafo<T>::eliminarVertice(T element){
    if(vertices.buscar_dato(element) == nullptr){
        return false;
    }
    int pos = vertices.posicion(element);
    Vertice<T> vertice = vertices.getData(pos);
    for(size_t i = 0; i < vertices.size(); i++){
        vertices.getData(i).borrarCoincidencias(&vertice);
    }
    vertices.erase(pos);
    return true;
}

template<typename T>
bool Grafo<T>::eliminarArista(T origen, T destino){
    int pos_o = vertices.posicion(origen);
    int pos_d = vertices.posicion(destino);

    if(pos_o == -1 || pos_d == -1){
        return false;
    }

    return vertices.getData(pos_o).eliminarArista(&vertices.getData(pos_d));
}

template<typename T>
bool Grafo<T>::guardar(){
    fstream archivo;
    archivo.open("file01.txt", ios::out);
    if(archivo.is_open()){
        archivo << vertices.size() << endl;
        for(size_t i = 0; i < vertices.size(); i++){
            archivo << vertices.getData(i).get();
        }
        archivo << "\n";
        for(size_t i = 0; i < vertices.size(); i++){
            archivo << vertices.getData(i).listaAristas();
        }
        archivo.close();
        return true;
    }
    return false;
}

template<typename T>
bool Grafo<T>::cargar(){
    fstream archivo;
    archivo.open("file01.txt", ios::in);
    if(archivo.is_open()){
        int size;
        string aux;
        T dato;
        getline(archivo, aux, '\n');
        size = stoi(aux);
        int id;
        string ciudad, pais;
        for(size_t i = 0; i < size; i++){
            getline(archivo, aux, '|');
            getline(archivo, ciudad, '|');
            getline(archivo, pais, '*');
            dato.setId(stoi(aux));
            dato.setCiudad(ciudad);
            dato.setPais(pais);
            vertices.push_back(dato);
        }
        getline(archivo, aux, '\n');
        while(true){
            getline(archivo, aux, '|');
            if(aux.empty()){
                break;
            }
            else{
                int origen, destino, peso;
                origen = stoi(aux);
                getline(archivo, aux, '|');
                destino = stoi(aux);
                getline(archivo, aux, '*');
                peso = stoi(aux);
                agregarArista(Aeropuerto(origen), Aeropuerto(destino), peso);
            }
        }
        archivo.close();
        return true;
    }
    return false;
}

#endif