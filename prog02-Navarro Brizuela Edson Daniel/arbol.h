#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <stdexcept>
#include <windows.h>  
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
                int alt;
                Node(const T& elem, shared_ptr<Node> d = nullptr, shared_ptr<Node> i = nullptr):
                    data(elem), der(d), izq(i){};
        };
        shared_ptr<Node> insert(shared_ptr<Node> & root, const T& element){
            if(root == nullptr){
                root = make_shared<Node>(element);
            }
            else{
                if(element < root->data){
                    root->izq = insert(root->izq, element);
                }
                else if(element > root->data){
                    root->der = insert(root->der, element);
                }
                else{
                    cout << "El elemento ya existe dentro del Arbol" << endl;
                }
            }
            root->alt = 1 +max(altura(root->izq), altura(root->der));
            int fe = factorEquilibrio(root);
            if(fe > 1 && element < root->izq->data){
                cout << "Rotacion derecha" << endl;
                return this->SRR(root);
            }
            if(fe < -1 && element > root->der->data){
                cout << "Rotacion izquierda" << endl;
                return this->SLR(root);
            }
            if(fe > 1 && element > root->izq->data){
                cout << "Rotacion izquierda derecha" << endl;
                root->izq = this->SLR(root->izq);
                return this->SRR(root);
            }
            if(fe < -1 && element < root->der->data){
                cout << "Rotacion derecha izquierda" << endl;
                root->der = this->SRR(root->der);
                return this->SLR(root);
            }
            return root;
        }
        void inorden(shared_ptr<Node> & root);
        void preorden(shared_ptr<Node> & root);
        void postorden(shared_ptr<Node> & root);
        void guardar(shared_ptr<Node> & root, fstream & archivo);
        T* buscar(shared_ptr<Node> & root, char *nombre);
        int altura(shared_ptr<Node> & root);
        int max(int a, int b);
        int factorEquilibrio(shared_ptr<Node> & root);
        shared_ptr<Node> SLR(shared_ptr<Node> & A){
            shared_ptr<Node> B = A->der;
            shared_ptr<Node> C = B->izq;
            B->izq = A;
            A->der = C;
            A->alt = max(altura(A->izq), altura(A->der))+1;
            B->alt = max(altura(B->izq), altura(B->der))+1;
            return B;
        }
        shared_ptr<Node> SRR(shared_ptr<Node> & A){
            shared_ptr<Node> B = A->izq;
            shared_ptr<Node> C = B->der;
            B->der = A;
            A-> izq = C;
            A->alt = max(altura(A->izq), altura(A->der))+1;
            B->alt = max(altura(B->izq), altura(B->der))+1;
            return B;
        }
    public:
        shared_ptr<Node> raiz;
        AVL(){
            raiz = nullptr;
        }
        
        shared_ptr<Node> insert(const T& element){
            return insert(raiz, element);
        }
        void inorden();
        void preorden();
        void postorden();
        void guardar();
        void recuperar();
        T* buscar(char *nombre);
};

template<typename T>
int AVL<T>::altura(shared_ptr<Node> & root){
    if(root == nullptr){
        return 0;
    }
    return root->alt;
}

template<typename T>
int AVL<T>::max(int a, int b){
    return a > b ? a : b;
}

template<typename T>
int AVL<T>::factorEquilibrio(shared_ptr<Node> & root){
    if(root == nullptr){
        return 0;
    }
    return altura(root->izq) - altura(root->der);
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
    archivo.open("file01.bin", ios::binary | ios::in);
    if(!archivo.is_open()){
        cout << "Error al recuperar el archivo" << endl;
    }
    else{
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