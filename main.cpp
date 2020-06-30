#include <iostream>
#include "Concesionaria.h"
using namespace std;

int main()
{
    Concesionaria c;
    c.procesar_archivo_entrada("prueba.csv");
    //c.mostrar_lista();
    Auto * arreglo[2];
    bool termino = false;
    while (termino != true){
        int i,f;
        cout<<endl;
        cout<<"Ingrese modelo inicial(0,20):"<<endl;
        cin>>i;
        cout<<"Ingrese modelo final(0,20):"<<endl;
        cin>>f;
        if( (i <= f) && (0 <= i) && (f <= 20)){
            c.consulta_mayor_menor(arreglo,i,f); //[0]=caro;[1]=barato
            cout<<endl;
            cout<<"/ $$$$$$$$$$$$$$$$$$   SERVICIO DE CONSULTA DE AUTOS MAS CAROS Y BARATOS POR RANGO DE MODELO   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ /"<<endl;
            cout<<endl;
            cout << "Auto mas caro en el rango ("<<i<<";"<<f<<"): "<<endl;
            cout <<"[ "<<" Patente: "<< arreglo[0]->getpatente() <<" //  Precio: "<< arreglo[0]->getprecio()<<endl;
            cout <<" //  Modelo: "<<arreglo[0]->getmodelo()<<" //  Marca: "<<arreglo[0]->getmarca()<<endl;
            cout <<" //  Caracteristicas: ";
            for(int j=0; j < arreglo[0]->getcaracteristicas().get_cantelementos() ;j++){
                cout <<  arreglo[0]->getcaracteristicas().recuperar_lista(j) << ",";
            }
            cout<<" ]"<<endl;
            cout<<endl;
            cout << "Auto mas barato en el rango ("<<i<<";"<<f<<"): "<<endl;
            cout <<"[ "<<" Patente: "<< arreglo[1]->getpatente() <<" //  Precio: "<< arreglo[1]->getprecio()<<endl;
            cout <<" //  Modelo: "<<arreglo[1]->getmodelo()<<" //  Marca: "<<arreglo[1]->getmarca()<<endl;
            cout <<" //  Caracteristicas: ";
            for(int r=0; r < arreglo[1]->getcaracteristicas().get_cantelementos() ;r++){
                cout <<  arreglo[1]->getcaracteristicas().recuperar_lista(r) << ",";
            }
            cout<<" ]"<<endl;
            cout<<endl;
            cout<<"/ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ /"<<endl;
            cout<<endl;
        }
        else
            cout<<"Rango no valido!!!"<<endl;
        cout<<endl;
        char c;
        cout<<"Termino de solicitar consultas?(Y/N)"<<endl;
        cin>>c;
        if(c == 'y')
            termino = true;
    }

    cout<<"Termina programa"<<endl;
    return 0;
}
