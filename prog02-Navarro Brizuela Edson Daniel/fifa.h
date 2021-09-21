#ifndef FIFA_H
#define FIFA_H

#include "equipos.h"
#include "arbol.h"

class Fifa{
    private:
        AVL<Equipos> arbol;
    public:
        Fifa();
        // ~Fifa();
        void menu();
};

#endif