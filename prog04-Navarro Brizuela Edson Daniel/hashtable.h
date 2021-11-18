#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <array>
#include <cstring>
#include <fstream>
using namespace std;

template <typename T>
class Hashtable{
    private:
        static const int hashGroup = 10;
        array<list<pair<int,T>>, hashGroup> table;  //list 1, index 0, list 2, index 1
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key,T value);
        void removeItem(int key);
        T* searchTable(int key);
        void printTable();
        void saveTable();
        void loadTable();
};

template <typename T>
bool Hashtable<T>::isEmpty() const{
    int sum{};
    for(int i = 0; i < hashGroup; i++){
        sum += table[i].size();
    }
    if(!sum){
        return true;
    }
    return false;
}

template <typename T>
int Hashtable<T>::hashFunction(int key){
    return key % hashGroup;
}

template <typename T>
void Hashtable<T>::insertItem(int key,T value){
    int hashValue = hashFunction(key);
    bool found = false;
    for(auto& item : table[hashValue]){
        if(item.first == key){
            found = true;
            cout << "Este registro ya existe." << endl;
            break;
        }
    }
    if(!found){
        table[hashValue].emplace_back(key, value);
        cout << "Alumno agregado" << endl;
    }
}

template <typename T>
void Hashtable<T>::removeItem(int key){
    int hashValue = hashFunction(key);
    bool flag = false;
    for(auto it = table[hashValue].begin(); it != table[hashValue].end(); it++){
        if(it->first == key){
            table[hashValue].erase(it);
            cout << "Alumno eliminado" << endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "No se encontro el alumno" << endl;
    }
}

template <typename T>
T* Hashtable<T>::searchTable(int key){
    int hashValue = hashFunction(key);
    for(auto it = table[hashValue].begin(); it != table[hashValue].end(); it++){
        if(it->first == key){
            return &it->second;
        }
    }
    return nullptr;
}

template <typename T>
void Hashtable<T>::printTable(){
    for(int i = 0; i < hashGroup; i++){
        cout << "Key " << i << "-> ";
        for(auto& it : table[i]){
            cout << it.second << " -> ";
        }
        cout << endl;
    }
    return;
}

template <typename T>
void Hashtable<T>::saveTable(){
    ofstream file;
    file.open("file01.txt");
    for(int i = 0; i < hashGroup; i++){
        for(auto& it : table[i]){
            file << it.second << endl;
        }
    }
    file.close();
    cout << "Tabla guardada" << endl;
    return;
}

template <typename T>
void Hashtable<T>::loadTable(){
    ifstream file;
    file.open("file01.txt");
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }
    else{
        string registro, nombre, carrera;
        T alumno;
        while(true){
            getline(file, registro, '|');
            if(file.eof()){
                break;
            }
            getline(file, nombre, '|');
            getline(file, carrera, '*');
            int key = stoi(registro);
            alumno.setregistro(key);
            alumno.setnombre(nombre);
            alumno.setcarrera(carrera);
            this->insertItem(key, alumno);
        }
        cout << "Tabla cargada" << endl;
        file.close();
    }
    return;
}

#endif // HASHTABLE_H