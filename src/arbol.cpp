#include "arbol.h"
#include "auto.h"
#include "lista.h"
#include <iostream>
#include <cstddef>
using namespace std;

arbol::arbol(){
    Arbol = NULL;
    //ctor
}

arbol::~arbol(){
    //dtor
}

/*
void arbol::imprimirarbol(){
    if(Arbol!=NULL){
        Arbol->izq->imprimirarbol();
        Arbol->raiz.imprimirauto();
        Arbol->der->imprimirarbol();
    }
}
*/

bool arbol::arbolVacio(){
    if(Arbol == NULL){
        return true;
    }
    else
        return false;
}


void arbol::agregar_Nodo(const Auto & elemento){
    Arbol=new Nodo();
    Arbol->raiz=elemento;
    Arbol->izq = new arbol();
    Arbol->der = new arbol();
}


void arbol::agregar(const Auto &elemento){
        if(Arbol == NULL){
            agregar_Nodo(elemento);
        }
        else{
            if (elemento > Arbol->raiz){
                Arbol->der->agregar(elemento);
            }
            else{
                if (elemento < Arbol->raiz){
                    Arbol->izq->agregar(elemento);
                }
            }
        }
}


bool arbol::existe_elemento(const Auto &elemento){
    if(Arbol == NULL){
        return false;
    }else
        if( Arbol->raiz == elemento)
            return true;
        else{
            if( Arbol->raiz > elemento){
                return Arbol->izq->existe_elemento(elemento);
            }else
                return Arbol->der->existe_elemento(elemento);
        }
}


int arbol::cantidad_Elementos(){
    if (Arbol!=NULL){
            return 1+ Arbol->der->cantidad_Elementos() + Arbol->izq->cantidad_Elementos();
       }else
            return 0;
}


void arbol::listarElementos(int & iteraciones,lista<Auto*> & listaElementos){

    if(Arbol != NULL){
        Auto * a= &(Arbol->raiz);
        listaElementos.agregar_elemento(iteraciones,a);
        Arbol->izq->listarElementos(iteraciones,listaElementos);
        Arbol->der->listarElementos(iteraciones,listaElementos);
    }
}
/*template<typename T>
T * arbol<T>::getElemento(const T &elemento){
    if(Arbol == NULL)
        return NULL;
    else
    {
        if( Arbol->raiz == elemento)
            return &(Arbol->raiz);
        else{
            if( Arbol->raiz > elemento){
                return Arbol->izq->getElemento(elemento);
            }else
                return Arbol->der->getElemento(elemento);
        }
    }
}
*/

