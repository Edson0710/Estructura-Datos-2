#include "fifa.h"
#include <conio.h>

Fifa::Fifa(){}

// Fifa::~Fifa(){
//     arbol.clear();
// }

void Fifa::menu(){
    int op = 1;
    while(op != 0){
        system("cls");
        Equipos e;
        size_t pos;
        cout << "\tMENU" << endl
             << "1. Insertar equipo"<< endl
             << "2. Inorden" << endl
             << "3. Preorden" << endl
             << "4. Postorden" << endl
             << "5. Buscar equipo" << endl
             << "6. Guardar" << endl
             << "7. Cargar" << endl
             << "0. Salir" << endl
             << "Opcion: ";
        cin >> op;
        cin.ignore();
        switch (op){
            case 1:
                cin >> e;
                arbol.raiz = arbol.insert(e);
                cout << "Insertado con exito" << endl;
                break;
            case 2:
                arbol.inorden();
                break;
            case 3:
                arbol.preorden();
                break;
            case 4:
                arbol.postorden();
                break;
            case 5:{
                char nombre[20];
                cin.getline(nombre, 20);
                Equipos* e = arbol.buscar(nombre);
                if(e == nullptr){
                    cout << "El equipo no ha sido encontrado"<< endl;
                }
                else{
                    cout << *e;
                }
                break;
            }
            case 6:
                arbol.guardar();
                break;
            case 7:
                arbol.recuperar();
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