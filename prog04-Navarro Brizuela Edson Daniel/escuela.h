#ifndef TICKETS_H
#define TICKETS_H

#include <iostream>
#include "hashtable.h"
#include "alumno.h"
#include <conio.h>
using namespace std;

class Escuela{
    private:
        Hashtable<Alumno> ht;
    public:
        Escuela(){
            ht = Hashtable<Alumno>();
        }
        void menu();
};

void Escuela::menu(){
    int op;
    do{
        system("cls");
        cout << "\tESCUELA MENU" << endl
             << "1) Agregar Alumno" << endl 
             << "2) Mostrar Alumnos" << endl
             << "3) Eliminar Alumno" << endl
             << "4) Buscar Alumno" << endl
             << "5) Guardar archivo" << endl
             << "6) Cargar archivo" << endl
             << "0) Salir" << endl
             << "Opcion: ";
        cin >> op; cin.ignore();
        switch(op){
            case 1:{
                Alumno a;
                cin >> a;
                ht.insertItem(a.getregistro(), a);
                break;
            }
            case 2:{
                ht.printTable();
                break;
            }
            case 3:{
                int key;
                cout << "Ingrese el registro del alumno a eliminar: ";
                cin >> key; cin.ignore();
                ht.removeItem(key);
                break;
            }
            case 4:{
                int key;
                cout << "Ingrese el registro del alumno a buscar: ";
                cin >> key; cin.ignore();
                Alumno* a = ht.searchTable(key);
                if(a == nullptr){
                    cout << "No se encontro el alumno" << endl;
                }
                else{
                    cout << *a << endl;
                }
                break;
            }
            case 5:{
                ht.saveTable();
                break;
            }
            case 6:{
                ht.loadTable();
                break;
            }
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        getch();
    } while(op != 0);
}


#endif