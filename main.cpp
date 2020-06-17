#include <iostream>
#include "Concesionaria.h"
using namespace std;

int main()
{
    Concesionaria c;
    c.procesar_archivo_entrada("prueba.csv");
    c.mostrar_lista();
    return 0;
}
