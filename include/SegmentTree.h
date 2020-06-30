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
        void get_MayorMenor(Auto * autos[],int ini_user,int fin_user);
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
        void combina(NodoTree* &s, Auto * &actual_mayor, Auto * &actual_menor)const;
        void encontrar_MayorMenor(NodoTree * s,Auto * &actual_mayor,Auto * &actual_menor,int ini_user,int fin_user)const;
        void podar(NodoTree * &nodo);
};

#endif // SEGMENTTREE_H
