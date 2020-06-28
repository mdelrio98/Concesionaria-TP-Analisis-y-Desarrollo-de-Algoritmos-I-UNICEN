#ifndef AUTO_H
#define AUTO_H
#include<iostream>
#include"lista.h"
using namespace std;
class Auto
{
    public:
        Auto();
        Auto(int modelo,string patente, string marca, float precio);
        virtual ~Auto();

        int getmodelo()const; //OBS
        void setmodelo(int mod);//MOD
        string getmarca()const;// OBS
        string getpatente()const;// OBS
        void setpatente(string pat);//MOD
        float getprecio()const;// OBS
        const lista<string> & getcaracteristicas()const;//OBS
        void setcaracteristica(int posicion,string caracteristica);//MOD

        bool operator < (const Auto & A) const;
        bool operator > (const Auto & A) const;
        bool operator == (const Auto & A) const;
        bool operator != (const Auto & A) const;
        Auto & operator = (const Auto & A);

    private:
        int modelo;
        string patente;
        string marca;
        float precio;
        lista<string>caracteristicas;
};


ostream & operator << (ostream & salida , const Auto & a);
#endif // AUTO_H
