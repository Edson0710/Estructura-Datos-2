#include "equipos.h"

Equipos::Equipos(){}

Equipos::Equipos(char *nombre, char *liga, char *pais){
    strcpy(this->nombre, nombre);
    strcpy(this->liga, liga);
    strcpy(this->pais, pais);
}

void Equipos::setNombre(char *nombre){
    strcpy(this->nombre, nombre);
}

char* Equipos::getNombre(){
    return nombre;
}

void Equipos::setLiga(char *liga){
    strcpy(this->liga, liga);
}

char* Equipos::getLiga(){
    return liga;
}

void Equipos::setPais(char *pais){
    strcpy(this->pais, pais);
}

char* Equipos::getPais(){
    return pais;
}