#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Alumno{
    private:
        int registro;
        string nombre;
        string carrera;
    public:
        Alumno(){}

        Alumno(int registro){
            this->registro = registro;
        }

        Alumno(int registro, const string &nombre, const string &carrera){
            this->registro = registro;
            this->nombre = nombre;
            this->carrera = carrera;
        }

        void setregistro(int registro){
            this->registro = registro;
        }

        int getregistro(){
            return registro;
        }

        void setnombre(const string &nombre){
            this->nombre = nombre;
        }

        string getnombre(){
            return nombre;
        }

        void setcarrera(const string &carrera){
            this->carrera = carrera;
        }

        string getcarrera(){
            return carrera;
        }

        friend istream& operator>>(istream &in, Alumno(&a)){
            cout << "registro: ";
            cin >> a.registro; cin.ignore();
            cout << "nombre: ";
            getline(cin, a.nombre);
            cout << "carrera: ";
            getline(cin, a.carrera);
            return in;
        }
        
        friend ostream& operator<<(ostream &out, const Alumno &a){
            if(&out == &cout){
                out << a.registro << " " << a.nombre << " " << a.carrera;
            }
            else{
                out << a.registro << '|' << a.nombre << '|' << a.carrera << '*';
            }
            return out;
        }

        bool operator==(const Alumno& a){
            return registro == a.registro;
        }

        bool operator==(const Alumno& a) const{
            return registro == a.registro;
        }



};

#endif