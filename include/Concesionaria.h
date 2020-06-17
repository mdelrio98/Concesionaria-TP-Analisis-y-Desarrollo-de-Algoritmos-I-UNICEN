#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include "lista.h"
#include "auto.h"
using namespace std;

class Concesionaria
{
    public:
        Concesionaria();//CB
        virtual ~Concesionaria();
        void nuevo_auto(Auto a);//MOD
        void procesar_archivo_entrada(string origen);
        void  mostrar_lista();
    private:
        lista<Auto>modelos[21];
};

#endif // CONCESIONARIA_H
