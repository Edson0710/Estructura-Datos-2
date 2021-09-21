#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>
#include "equipos.h"

using namespace std;

template<typename T>
class AVL{
    private:
        class Node{
            public:
                T data;
                shared_ptr<Node> der;
                shared_ptr<Node> izq;
                Node(const T& elem, shared_ptr<Node> d = nullptr, shared_ptr<Node> i = nullptr):
                    data(elem), der(d), izq(i){};
        };
        shared_ptr<Node> raiz;
        shared_ptr<Node> padre;
        shared_ptr<Node> temp1;
        shared_ptr<Node> temp2;
        void insert(shared_ptr<Node> & root, const T& elemen);
        void inorden(shared_ptr<Node> & root);
        void preorden(shared_ptr<Node> & root);
        void postorden(shared_ptr<Node> & root);
        void guardar(shared_ptr<Node> & root, fstream & archivo);
        T* buscar(shared_ptr<Node> & root, char *nombre);
    public:
        AVL(){
            raiz = nullptr;
            padre = nullptr;
            temp1 = nullptr;
            temp2 = nullptr;
        }
        // ~AVL(){}
        void insert(const T& element);
        void inorden();
        void preorden();
        void postorden();
        void guardar();
        void recuperar();
        T* buscar(char *nombre);
};

template<typename T>
void AVL<T>::insert(shared_ptr<Node> & root, const T& element){
    if(root == nullptr){
        root = make_shared<Node>(element);
    }
    else{
        if(element < root->data){
            insert(root->izq, element);
        }
        else if(element > root->data){
            insert(root->der, element);
        }
        else{
            cout << "El elemento ya existe dentro del Arbol" << endl;
        }
    }
}

template<typename T>
void AVL<T>::insert(const T& element){
    insert(raiz, element);
}

template<typename T>
void AVL<T>::inorden(){
    inorden(raiz);
}

template<typename T>
void AVL<T>::inorden(shared_ptr<Node> &root){
    if(root){
        inorden(root -> izq);
        cout << root -> data;
        inorden(root -> der);
    }
}

template<typename T>
void AVL<T>::preorden(){
    preorden(raiz);
}

template<typename T>
void AVL<T>::preorden(shared_ptr<Node> &root){
    if(root){
        cout << root -> data;
        preorden(root -> izq);
        preorden(root -> der);
    }
}

template<typename T>
void AVL<T>::postorden(){
    postorden(raiz);
}

template<typename T>
void AVL<T>::postorden(shared_ptr<Node> &root){
    if(root){
        postorden(root -> izq);
        postorden(root -> der);
        cout << root -> data;
    }
}

template<typename T>
T* AVL<T>::buscar(char *nombre){
    return buscar(raiz, nombre);
}

template<typename T>
T* AVL<T>::buscar(shared_ptr<Node> & root,char *nombre){
    T element;
    element.setNombre(nombre);
    if(!root){
        return nullptr;
    }
    else if(element < root->data){
        return buscar(root->izq, nombre);
    }
    else if(element > root->data){
        return buscar(root->der, nombre);
    }
    else{
        return &root->data;
    }
}

template<typename T>
void AVL<T>::guardar(){
    fstream archivo;
    archivo.open("file01.bin", ios::binary | ios::out | ios::trunc);
    if(!archivo.is_open()){
        cout << "Error al guardar el archivo" << endl;
    }else{
        this->guardar(raiz, archivo);
        archivo.close();
        cout << "Arbol guardado con exito" << endl;
    }
}

template<typename T>
void AVL<T>::guardar(shared_ptr<Node> & root, fstream & archivo){
    if(root){
        archivo.write((char *)&root->data, sizeof(T));
        guardar(root->izq, archivo);
        guardar(root->der, archivo);
    }
}

template<typename T>
void AVL<T>::recuperar(){
    fstream archivo;
    Equipos e, e2;
    archivo.open("file01.bin", ios::binary | ios::in);
    if(!archivo.is_open()){
        cout << "Error al recuperar el archivo" << endl;
    }
    else{
        // archivo.read((char *)&e, sizeof(Equipos));
        // archivo.read((char *)&e2, sizeof(Equipos));
        // cout << e << endl;
        // cout << e2 << endl;
        
        T equipo;
        archivo.seekg(0);
        while(true){
            archivo.read((char *)&equipo, sizeof(Equipos));
            this->insert(equipo);
            if(archivo.eof()){
                break;
            }
        }
        archivo.close();
    }
}


#endif