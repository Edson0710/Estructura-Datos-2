#ifndef FIFA_H
#define FIFA_H

#include "equipos.h"
#include "LSL.h"

class Fifa{
    private:
        LSL<Equipos> lista;
    public:
        Fifa();
        ~Fifa();
        void menu();
};

#endif