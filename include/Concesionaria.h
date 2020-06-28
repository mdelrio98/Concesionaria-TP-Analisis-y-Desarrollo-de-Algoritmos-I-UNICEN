#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include "lista.h"
#include "auto.h"
#include "SegmentTree.h"
using namespace std;

class Concesionaria
{
    public:
        Concesionaria();//CB
        virtual ~Concesionaria();
        void nuevo_auto(Auto a);//MOD
        void procesar_archivo_entrada(string origen);
        void  mostrar_lista();
        void consulta_mayor_menor(Auto * arreglo[],int inicio,int fin);
    private:
        lista<Auto>modelos[21];
        SegmentTree s ;
};

#endif // CONCESIONARIA_H
