#include "auto.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

Auto::Auto(){
    //ctor
}

Auto::Auto(int modelo,string patente, string marca, float precio){
    this->modelo=modelo;
    this->patente=patente;
    this->marca=marca;
    this->precio=precio;
    //ctor
}

Auto::~Auto(){
    //dtor
}


int Auto::getmodelo()const{
    return this->modelo;
}

void Auto::setmodelo(int mod){
    this->modelo=mod;
}

string Auto::getmarca()const{
    return this->marca;
}

string Auto::getpatente()const{
    return this->patente;
}

void Auto::setpatente(string pat){
    this->patente=pat;
}

float Auto::getprecio()const{
    return this->precio;
}

const lista<string> & Auto::getcaracteristicas()const{
    return this->caracteristicas;
}

void Auto::setcaracteristica(int posicion,string caracteristica){
    caracteristicas.agregar_elemento(posicion,caracteristica);
}

ostream & operator << (ostream & salida , const Auto & a){
    salida << "---------------------------------" <<endl;
    salida << "[(Patente:" << a.getpatente()<<")"<<endl;
    salida << "(Marca:" << a.getmarca()<<")"<<endl;
    salida << "(Modelo:" << a.getmodelo()<<")"<<endl;
    salida << "(Precio:" << a.getprecio()<<")"<<endl;
    salida << "(Caracteristicas:";
    for(int i=0; i < a.getcaracteristicas().get_cantelementos() ;i++){
        salida <<  a.getcaracteristicas().recuperar_lista(i) << ",";
    }
    salida << ")]" << endl ;
    return salida;
}

bool Auto::operator < (const Auto & A) const {
    if ((this->patente < A.patente) || (this->modelo < A.modelo)){
        return true; //si es menor
    }
    return false;
}

bool Auto::operator > (const Auto & A) const {
    if ((this->patente > A.patente) || (this->modelo > A.modelo)){
        return true; //si es mayor
    }
    return false;
}

bool Auto::operator == (const Auto & A) const {
    if ((this->patente == A.patente) || (this->modelo == A.modelo)){
        return true; //si son iguales
    }
    return false;
}
bool Auto::operator != (const Auto & A) const {
    if ((this->patente != A.patente) || (this->modelo != A.modelo)){
        return true; //si son distintos
    }
    return false;
}

Auto & Auto::operator = (const Auto & A){
    modelo = A.getmodelo();
    marca = A.getmarca();
    patente = A.getpatente();
    precio = A.getprecio();
    caracteristicas = A.getcaracteristicas();
    return *this;
}

















