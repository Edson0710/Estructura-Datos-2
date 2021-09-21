#include "equipos.h"

Equipos::Equipos(){}

Equipos::Equipos(const string &nombre, const string &liga, const string &pais){
    this->nombre = nombre;
    this->liga = liga;
    this->pais = pais;
}

void Equipos::setNombre(const string &nombre){
    this->nombre = nombre;
}

string Equipos::getNombre(){
    return nombre;
}

void Equipos::setLiga(const string &liga){
    this->liga = liga;
}

string Equipos::getLiga(){
    return liga;
}

void Equipos::setPais(const string &pais){
    this->pais = pais;
}

string Equipos::getPais(){
    return pais;
}