#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Equipos{
    private:
        char nombre[20];
        char liga[20];
        char pais[20];
    public:
        Equipos();
        Equipos(char *nombre, char *liga, char *pais);
        void setNombre(char *nombre);
        char* getNombre();
        void setLiga(char *liga);
        char* getLiga();
        void setPais(char *pais);
        char* getPais();

        friend ostream& operator<<(ostream &out, const Equipos &e){
            out << left;
            out << setw(20) << e.nombre;
            out << setw(20) << e.liga;
            out << setw(20) << e.pais << endl;
            return out;
        }

        // friend ostream& operator<<(ostream &out, const Equipos &e){
        //     out.write((char *) &e.nombre, 20*sizeof(char));
        //     out.write((char *) &e.nombre, 20*sizeof(char));
        //     out.write((char *) &e.nombre, 20*sizeof(char));  
        //     return out;
        // }

        friend istream& operator>>(istream &in, Equipos(&e)){
            cout << "Nombre: ";
            cin.getline(e.nombre, 20);
            cout << "Liga: ";
            cin.getline(e.liga, 20);
            cout << "Pais: ";
            cin.getline(e.pais, 20);

            return in;
        }

        bool operator==(const Equipos& e){
            return nombre == e.nombre;
            return strcmp(nombre, e.nombre) == 0;
        }

        bool operator==(const Equipos& e) const{
            return strcmp(nombre, e.nombre) == 0;
        }

        bool operator>(const Equipos& e){
            return strcmp(nombre, e.nombre) > 0;
        }

        bool operator>(const Equipos& e) const{
            return strcmp(nombre, e.nombre) > 0;
        }

        bool operator<(const Equipos& e){
            return strcmp(nombre, e.nombre) < 0;
        }

        bool operator<(const Equipos& e) const{
            return strcmp(nombre, e.nombre) < 0;
        }
};

#endif