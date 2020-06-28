#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#include "auto.h"
#include "lista.h"
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstddef>

class SegmentTree
{
    public:
        SegmentTree();
        SegmentTree(lista<Auto> modelos[]);

        virtual ~SegmentTree();
        Auto * getMenor(lista<Auto> modelos[], int mod);
        Auto * getMayor(lista<Auto> modelos[], int mod);
        Auto * get_Menor_Rango(int ini,int fin);
        Auto * get_Mayor_Rango(int ini,int fin);
        void set_SegmentTree(lista<Auto> modelos[]);

    private:
        struct NodoTree{
            NodoTree * left;
            NodoTree * right;
            Auto * mayor;
            Auto * menor;
            int modelo_inicio;
            int modelo_fin;
        };
        NodoTree * raiz;
        NodoTree * armar_SegmentTree(lista<Auto> modelos[],int ini,int fin);
        NodoTree * crea_NodoTree(int ini,int fin);
        Auto * encontrar_Menor(NodoTree* &s,int ini,int fin);
        Auto * encontrar_Mayor(NodoTree* &s,int ini,int fin);
};

#endif // SEGMENTTREE_H
