#include "Concesionaria.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstddef>
#include <string>
using namespace std;

Concesionaria::Concesionaria(){
    //ctor
}

Concesionaria::~Concesionaria(){
    //dtor
    //delete mas_caro;
    //autos.eliminar_lista();
}

void Concesionaria::consulta_mayor_menor(Auto * autos[],int inicio,int fin){

    autos[0] = s.get_Mayor_Rango(inicio,fin);
    autos[1] = s.get_Menor_Rango(inicio,fin);
}

void  Concesionaria::mostrar_lista(){
    for(int i =0 ;i < 20 ;i++){
        cout<<"modelo: "<< i <<endl;
        modelos[i].mostrar_elementos();
    }
}

void  Concesionaria::nuevo_auto(Auto a){

    int j=2000;
    int mod =a.getmodelo() - j;

    if(modelos[mod].get_cantelementos()== 0)
        modelos[mod].agregar_principio(a);
    else{
        modelos[mod].agregar_ultimo(a);
    }
}

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void Concesionaria::procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_autos = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_autos << " autos." << endl;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            int modelo = atoi(linea.substr(pos_inicial, pos_final).c_str());

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string marca = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string patente = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << modelo << "-"<<marca<<"-"<<patente<<"-"<<precio<<endl;
            //TO DO: Informacion general del auto.

            Auto  a1(modelo,patente,marca,precio);
            int contador=1;

            //Desde esta posición hasta el final se encuentra un número variable de caracteristicas.
            string caracteristicas = linea.substr(pos_final + 1, linea.size());
            int pos_inicial_guion = 0, pos_final_guion = 0;
            while (pos_final_guion != -1) {
                pos_final_guion = caracteristicas.find('-', pos_inicial_guion);
                string caracteristica = caracteristicas.substr(pos_inicial_guion, pos_final_guion - pos_inicial_guion);
                pos_inicial_guion = pos_final_guion + 1;
                a1.setcaracteristica(contador,caracteristica);
                contador++;
                //TO DO: Nueva caracteristica encontrada.
            }
            nuevo_auto(a1);
        }
        cout<<"no cargo segmentre"<<endl;
        s.set_SegmentTree(modelos);
        cout<<"cargo segmentre"<<endl;
    }
}


