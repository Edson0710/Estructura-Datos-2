#ifndef TICKETS_H
#define TICKETS_H

#include <iostream>
#include "grafo.h"
#include "aeropuerto.h"
#include <conio.h>
using namespace std;

class Tickets{
    private:
        Grafo<Aeropuerto> grafo;
    public:
        Tickets(){
            grafo = Grafo<Aeropuerto>();
        }
        void menu();
        void agregarAeropuerto();

};

void Tickets::menu(){
    int op;
    do{
        system("cls");
        cout << "\tTICKETS MENU" << endl
             << "1) Agregar aeropuerto/vertice" << endl 
             << "2) Agregar viaje/arista" << endl
             << "3) Ver aeropuertos y viajes" << endl
             << "4) Eliminar aeropuerto/vertice" << endl
             << "5) Eliminar viaje/arista" << endl
             << "6) Guardar archivo" << endl
             << "7) Cargar archivo" << endl
             << "0) Salir" << endl
             << "Opcion: ";
        cin >> op; cin.ignore();
        switch(op){
            case 1:{
                Aeropuerto a = Aeropuerto();
                cin >> a;
                if(grafo.agregarVertice(a)){
                    cout << "Aeropuerto agregado con exito" << endl;
                }
                else{
                    cout << "Este aeropuerto ya existe" << endl;
                }
                break;
            }
            case 2:{
                int origen, destino, peso;
                cout << "Elija el id de origen" << endl;
                grafo.mostrarVertices();
                cin >> origen;
                cout << "Elija el id de destino" << endl;
                grafo.mostrarVertices();
                cin >> destino;
                cout << "Escriba los km entre ambos aeropuerto" << endl;
                cin >> peso;

                if(grafo.agregarArista(Aeropuerto(origen), Aeropuerto(destino), peso)){
                    cout << "Vuelo agregado" << endl;
                }
                else{
                    cout << "Error. Puede que no exista el origen o el destino, o ya exista un vuelo" << endl;
                }
                break;
            }
            case 3:
                grafo.mostrarGrafo();
                break;
            case 4:{
                int id;
                cout << "Elija el id del aeropuerto a eliminar" << endl;
                grafo.mostrarVertices();
                cin >> id;
                if(grafo.eliminarVertice(Aeropuerto(id))){
                    cout << "Aeropuerto eliminado" << endl;
                }
                else{
                    cout << "El aeropuerto no existe" << endl;
                }
                break;
            }
            case 5:{
                int origen, destino;
                cout << "Elija el id de origen" << endl;
                grafo.mostrarVertices();
                cin >> origen;
                cout << "Elija el id de destino" << endl;
                grafo.mostrarVertices();
                cin >> destino;
                if(grafo.eliminarArista(Aeropuerto(origen), Aeropuerto(destino))){
                    cout << "Vuelo cancelado" << endl;
                }
                else{
                    cout << "No existe ese vuelo" << endl;
                }
                break;
            }
            case 6:
                if(grafo.guardar()){
                    cout << "Aeropuertos guardados" << endl;
                }
                else{
                    cout << "Fallo al guardar" << endl;
                }
                break;
            case 7:
                if(grafo.cargar()){
                    cout << "Se cargaron los vuelos" << endl;
                }
                else{
                    cout << "Fallo al cargar" << endl;
                }
            case 0:
                break;
            default:
                break;
        }
        getch();
    } while(op != 0);
}


#endif