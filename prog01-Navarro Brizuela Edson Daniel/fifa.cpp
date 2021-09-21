#include "fifa.h"
#include <conio.h>

Fifa::Fifa(){}

Fifa::~Fifa(){
    lista.clear();
}

void Fifa::menu(){
    int op = 1;
    while(op != 0){
        system("cls");
        Equipos e;
        size_t pos;
        cout << "\tMENU" << endl
             << "1. Insertar equipo al inicio" << endl
             << "2. Insertar equipo al final" << endl
             << "3. Insertar equipo por posicion" << endl
             << "4. Mostrar equipo front" << endl
             << "5. Mostrar equipo back" << endl
             << "6. Eliminar equipo front" << endl
             << "7. Eliminar equipo back" << endl
             << "8. Eliminar equipo por posicion" << endl
             << "9. Buscar equipo" << endl
             << "10. Guardar equipos" << endl
             << "11. Cargar equipos" << endl
             << "12. Mostrar" << endl 
             << "13. Anterior" << endl
             << "14. Siguiente" << endl
             << "15. Modificar" << endl
             << "0. Salir" << endl
             << "Opcion: ";
        cin >> op;
        cin.ignore();
        switch (op){
            case 1:
                cin >> e;
                lista.push_front(e);
                cout << "Insertado con exito" << endl;
                break;
            case 2:
                cin >> e;
                lista.push_back(e);
                cout << "Insertado con exito" << endl;
                break;
            case 3:
                cin >> e;
                cout << "Posicion: ";
                cin >> pos;
                lista.insert(pos, e);
                cout << "Insertado con exito" << endl;
                break;
            case 4:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Elemento al frente: " << endl;
                    cout << lista.front();
                }
                
                break;
            case 5:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Elemento al final: " << endl;
                    cout << lista.back();
                }
                break;
            case 6:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    lista.pop_front();
                    cout << "Elemento eliminado" << endl;
                }
                break;
            case 7:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    lista.pop_back();
                    cout << "Elemento eliminado" << endl;
                }
                break;
            case 8:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Posicion: ";
                    cin >> pos;
                    lista.erase(pos);
                }
                break;
            case 9:{
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Elemento a buscar:" << endl;
                    cin >> e;
                    Equipos* dato = lista.buscar_dato(e);
                    if(dato == nullptr){
                        cout << "El elemento que busca no existe" << endl;
                    } else{ 
                        cout << "Direccion del elemento: " << endl << dato << endl;
                        cout << "Data:" << endl << *dato << endl;
                    }
                }
                break;}
            case 10:
                lista.guardar();
                cout << "Lista guardada" << endl;
                break;
            case 11:
                lista.cargar();
                cout << "Lista cargada" << endl;
                break;
            case 12:
                lista.mostrar();
                break;
            case 13:{
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Posicion: ";
                    cin >> pos;
                    Equipos* dato = lista.anterior(pos);
                    cout << "Direccion anterior: " << endl << dato << endl;
                    cout << "Data: " << endl << *dato;
                }
                break;
            }
            case 14:{
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Posicion: ";
                    cin >> pos;
                    Equipos* dato = lista.siguiente(pos);
                    cout << "Direccion siguiente: " << endl << dato << endl;
                    cout << "Data: " << endl << *dato;
                }
                break;
            }
            case 15:
                if(lista.empty()){
                    cout << "La lista esta vacia" << endl;
                }
                else{
                    cout << "Elemento a modificar:" << endl;
                    cin >> e;
                    lista.modificar(e);
                }
                break;
            case 0:
                cout << "Saliendo...";
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
        getch();
    }
}