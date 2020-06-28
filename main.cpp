#include <iostream>
#include "Concesionaria.h"
using namespace std;

int main()
{
    Concesionaria c;
    c.procesar_archivo_entrada("prueba.csv");
    c.mostrar_lista();
    Auto * arreglo[2];
    c.consulta_mayor_menor(arreglo,5,6); //[0]=caro;[1]=barato
    cout<<"/ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ /"<<endl;
    cout << "[Auto mas caro en ese rango: "<<endl;
    cout << arreglo[0]->getpatente() <<"// Precio: "<< arreglo[0]->getprecio()<<"]"<<endl;
    cout << "[Auto mas barato en ese rango: "<<endl;
    cout << arreglo[1]->getpatente() <<"// Precio: "<< arreglo[1]->getprecio()<<"]"<<endl;
    cout<<endl;
    return 0;
}
