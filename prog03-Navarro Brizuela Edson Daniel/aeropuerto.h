#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aeropuerto{
    private:
        int id;
        string ciudad;
        string pais;
    public:
        Aeropuerto(){}

        Aeropuerto(int id){
            this->id = id;
        }

        Aeropuerto(int id, const string &ciudad, const string &pais){
            this->id = id;
            this->ciudad = ciudad;
            this->pais = pais;
        }

        void setId(int id){
            this->id = id;
        }

        int getId(){
            return id;
        }

        void setCiudad(const string &ciudad){
            this->ciudad = ciudad;
        }

        string getCiudad(){
            return ciudad;
        }

        void setPais(const string &pais){
            this->pais = pais;
        }

        string getPais(){
            return pais;
        }

        friend istream& operator>>(istream &in, Aeropuerto(&a)){
            cout << "Id: ";
            cin >> a.id; cin.ignore();
            cout << "Ciudad: ";
            getline(cin, a.ciudad);
            cout << "Pais: ";
            getline(cin, a.pais);

            return in;
        }
        
        friend ostream& operator<<(ostream &out, const Aeropuerto &a){
            if(&out == &cout){
                out << left;
                out << setw(4) << a.id;
                out << setw(20) << a.ciudad;
                out << setw(20) << a.pais << endl;
            }
            else{
                out << a.id << '|' << a.ciudad << '|' << a.pais << '*';
            }
            return out;
        }

        bool operator==(const Aeropuerto& a){
            return id == a.id;
        }

        bool operator==(const Aeropuerto& a) const{
            return id == a.id;
        }



};

#endif