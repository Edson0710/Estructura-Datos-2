#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <iostream>
#include <iomanip>
using namespace std;

class Equipos{
    private:
        string nombre;
        string liga;
        string pais;
    public:
        Equipos();
        Equipos(const string &nombre, const string &liga, const string &pais);
        void setNombre(const string &nombre);
        string getNombre();
        void setLiga(const string &liga);
        string getLiga();
        void setPais(const string &pais);
        string getPais();

        friend ostream& operator<<(ostream &out, const Equipos &e){
            out << left;
            out << setw(20) << e.nombre;
            out << setw(20) << e.liga;
            out << setw(20) << e.pais << endl;
            return out;
        }

        friend istream& operator>>(istream &in, Equipos(&e)){
            cout << "Nombre: ";
            getline(cin, e.nombre);
            cout << "Liga: ";
            getline(cin, e.liga);
            cout << "Pais: ";
            getline(cin, e.pais);

            return in;
        }

        bool operator==(const Equipos& e){
            return nombre == e.nombre;
        }

        bool operator==(const Equipos& e) const{
            return nombre == e.nombre;
        }
};

#endif