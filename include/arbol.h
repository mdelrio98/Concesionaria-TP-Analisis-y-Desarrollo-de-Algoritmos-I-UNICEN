#ifndef ARBOL_H
#define ARBOL_H
#include "lista.h"
#include "Auto.h"


class arbol
{
    public:
        arbol();
        virtual ~arbol();
        void agregar_Nodo(const Auto & elemento);
        bool arbolVacio();
        void agregar(const Auto &  elemento);
        bool existe_elemento(const Auto &elemento);
        int cantidad_Elementos();
        void listarElementos(int &iteraciones,lista<Auto*> & listaElementos);
        //T * getElemento(const T &elemento);
        void imprimirarbol();
    private:
        struct Nodo{
            Auto raiz;
            arbol*izq;
            arbol*der;
            };
        Nodo*Arbol;
};

#endif // ARBOL_H
