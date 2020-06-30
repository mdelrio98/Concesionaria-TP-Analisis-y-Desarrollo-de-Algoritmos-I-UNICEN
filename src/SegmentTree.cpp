#include "SegmentTree.h"
using namespace std;

SegmentTree::SegmentTree(){
        raiz = NULL;
}

SegmentTree::SegmentTree(lista<Auto> modelos[]){
        raiz = armar_SegmentTree(modelos,0,20);
}

SegmentTree::~SegmentTree(){
        //podar(raiz);
}

void SegmentTree::podar(NodoTree * &nodo){
    // Algoritmo recursivo, recorrido en postorden
    if(nodo) {
        podar(nodo->left); // Podar izquierdo
        podar(nodo->right);   // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}

void SegmentTree::set_SegmentTree(lista<Auto> modelos[]){
    this->raiz = armar_SegmentTree(modelos,0,20);
}

SegmentTree::NodoTree * SegmentTree::crea_NodoTree(int ini,int fin){
    NodoTree * nuevo = new NodoTree();
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->mayor = NULL;
        nuevo->menor = NULL;
        nuevo->modelo_inicio = ini;
        nuevo->modelo_fin = fin;
    return nuevo;
}

SegmentTree::NodoTree *  SegmentTree::armar_SegmentTree(lista<Auto> modelos[],int ini,int fin){

        if(ini < fin){

            int mid = (ini+fin)/2;
            NodoTree * l =  armar_SegmentTree(modelos,ini,mid);
            NodoTree * r =   armar_SegmentTree(modelos,mid + 1,fin);
            NodoTree  * nuevo = crea_NodoTree(ini,fin);
            nuevo->left = l;
            nuevo->right = r;

            // busca el de mayor y menor precio de sus hijos
            Auto * caro = NULL;
            Auto * barato = NULL;

            if(l->mayor->getprecio() > r->mayor->getprecio())
                caro = l->mayor;
            else
                caro = r->mayor;

            if(l->menor->getprecio() < r->menor->getprecio())
                barato = l->menor;
            else
                barato = r->menor;

            nuevo->mayor = caro;
            nuevo->menor = barato;
            return nuevo;
        }
        else{//ini == fin

            NodoTree * nuevo = crea_NodoTree(ini,fin); // crea la hoja
            nuevo->mayor = getMayor(modelos,ini);
            nuevo->menor = getMenor(modelos,ini);
            return nuevo;
        }
}

Auto * SegmentTree::getMayor(lista<Auto> modelos[],int mod){
    int i=1;
    //cout<<" entro get mayor: "<<"["<<mod<<"]"<<endl;
    modelos[mod].cursor_al_principio();
    Auto * mayor = &(modelos[mod].recuperar_elemento());
    modelos[mod].avanzar_cursor();
    while(i < modelos[mod].get_cantelementos()){

        Auto * aux1 = &(modelos[mod].recuperar_elemento());
        if(mayor->getprecio() < aux1->getprecio()){
            mayor = aux1;
            return mayor;
        }
        modelos[mod].avanzar_cursor();
        i++;
    }
    return mayor;
}

Auto * SegmentTree::getMenor(lista<Auto> modelos[],int mod){
    int i=1;
    //cout<<" entro get menor: "<<"["<<mod<<"]"<<endl;
    modelos[mod].cursor_al_principio();
    Auto * menor = &(modelos[mod].recuperar_elemento());
    modelos[mod].avanzar_cursor();
    while(i < modelos[mod].get_cantelementos()){

        Auto * aux1 = &(modelos[mod].recuperar_elemento());
        if(menor->getprecio() > aux1->getprecio()){
            menor = aux1;
            return menor;
        }
        modelos[mod].avanzar_cursor();
        i++;
    }
    return menor;
}

void SegmentTree::get_MayorMenor(Auto * autos[],int ini_user,int fin_user){
    Auto * caro = new Auto(0,"1","asd",0);
    Auto * barato= new Auto(0,"0","asd",9999);
    encontrar_MayorMenor(this->raiz,caro,barato,ini_user,fin_user);
    //cout<<"setea caro "<<caro->getpatente()<<"/"<<caro->getmodelo()<<"/"<<caro->getprecio()<<endl;
    autos[0] = caro;
    //cout<<"setea barato"<<barato->getpatente()<<"/"<<barato->getmodelo()<<"/"<<barato->getprecio()<<endl;
    autos[1] = barato;
}

void SegmentTree::combina(NodoTree* &s, Auto * &actual_mayor, Auto * &actual_menor)const{
    if(s->mayor->getprecio() > actual_mayor->getprecio()){
        actual_mayor = s->mayor;
        //cout<<"Cambio mayor en combina"<<endl;
    }
    if(s->menor->getprecio() < actual_menor->getprecio()){
        actual_menor = s->menor;
        //cout<<"Cambio menor en combina"<<endl;
    }
}

void SegmentTree::encontrar_MayorMenor(NodoTree* s,Auto * &actual_mayor,Auto * &actual_menor,int ini_user,int fin_user)const{
    if(s != NULL){
        //cout<<"[(iniuser: "<<ini_user<<"; finuser: "<<fin_user<<")"<<endl;
        //cout<<"(stini: "<<s->modelo_inicio<<"; stfin: "<<s->modelo_fin<<")]"<<endl;

        if( (ini_user == s->modelo_inicio) && (fin_user == s->modelo_fin) ){ // NODO IGUAL AL RANGO
            //cout<<"(Parado en el rango1)"<<endl;
            actual_mayor = s->mayor;
            actual_menor = s->menor;
            //cout<<"(Parado en el rango2)"<<endl;
        }
        else{
                if((  ini_user <= s->modelo_inicio ) && ( s->modelo_fin <= fin_user )){
                    //cout<<"Entra combina"<<endl;
                    combina(s,actual_mayor,actual_menor);
                }
                else{
                    int mid = ( s->modelo_inicio + s->modelo_fin ) / 2 ;
                    if( ini_user <= mid ){//IZQUIERDA
                        //cout<<"izquierda"<<endl;
                        encontrar_MayorMenor(s->left,actual_mayor,actual_menor,ini_user,fin_user);
                         //cout<<"sale izquierda"<<endl;
                    }
                    if( fin_user > mid ){//DERECHA
                        //cout<<"derecha"<<endl;
                        encontrar_MayorMenor(s->right,actual_mayor,actual_menor,ini_user,fin_user);
                        //cout<<"sale derecha"<<endl;
                    }
                }
        }
        //cout<<"[(actual mayor: "<<actual_mayor->getpatente()<<"; actual menor: "<<actual_menor->getpatente()<<")]"<<endl;
    }
}


