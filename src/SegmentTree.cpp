#include "SegmentTree.h"

using namespace std;

SegmentTree::SegmentTree(){
        raiz = NULL;
}

SegmentTree::SegmentTree(lista<Auto> modelos[]){
        raiz = armar_SegmentTree(modelos,0,20);
}
SegmentTree::~SegmentTree(){
  //
}

void SegmentTree::set_SegmentTree(lista<Auto> modelos[]){
    cout<<"entra al set"<<endl;
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
        cout<<"entro al armar";
        if(ini < fin){
            cout<<"entra if"<<endl;
            int mid = (ini+fin)/2;
            NodoTree * l =  armar_SegmentTree(modelos,ini,mid);
            NodoTree * r =   armar_SegmentTree(modelos,mid + 1,fin);
            NodoTree  * nuevo = crea_NodoTree(ini,fin);
            nuevo->left = l;
            nuevo->right = r;

            // busca el de mayor y menor precio de sus hijos
            Auto * caro = NULL;
            Auto * barato = NULL;

            if(l->mayor > r->mayor)
                caro = l->mayor;
            else
                caro = r->mayor;

            if(l->menor < r->menor)
                barato = l->menor;
            else
                barato = r->menor;

            nuevo->mayor = caro;
            nuevo->menor = barato;
            return nuevo;
        }
        else{//ini == fin
            cout<<"entra else"<<endl;
            NodoTree * nuevo = crea_NodoTree(ini,fin); // crea la hoja
            cout<<"creo"<<endl;
            nuevo->mayor = getMayor(modelos,ini);
            nuevo->menor = getMenor(modelos,ini);
            return nuevo;
        }
}

Auto * SegmentTree::getMayor(lista<Auto> modelos[],int mod){
    int i=1;
    cout<<" entro get mayor: "<<"["<<mod<<"]"<<endl;
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
    cout<<" entro get menor: "<<"["<<mod<<"]"<<endl;
    modelos[mod].cursor_al_principio();
    Auto * menor = &(modelos[mod].recuperar_elemento());
    modelos[mod].avanzar_cursor();
    while(i < modelos[mod].get_cantelementos()){

        Auto * aux1 = &(modelos[mod].recuperar_elemento());
        if(menor->getprecio() < aux1->getprecio()){
            menor = aux1;
            return menor;
        }
        modelos[mod].avanzar_cursor();
        i++;
    }
    return menor;
}

Auto * SegmentTree::get_Menor_Rango(int ini,int fin){
    Auto * barato;
    barato = encontrar_Menor(this->raiz,ini,fin);

    return barato;
}

Auto * SegmentTree::encontrar_Menor(NodoTree* &s,int ini,int fin){
        //cout<<"MENOR"<<endl;
        //cout<<"[ini:"<<ini<<"; fin:"<<fin<<"]"<<endl;
        //cout<<"[Sini:"<<s->modelo_inicio<<"; Sfin:"<<s->modelo_fin<<"]"<<endl;
        if((s->modelo_inicio == ini) && (s->modelo_fin == fin))
            return s->menor;//HOJA

        int mid = (s->modelo_inicio + s->modelo_fin)/2;//MITAD

        if((ini <= mid) && (fin <= mid)) //IZQUIERDA
            s->left->menor = encontrar_Menor(s->left,ini,fin);

        if((ini > mid) && (fin > mid)) //DERECHA
            s->right->menor = encontrar_Menor(s->right,ini,fin);

        if(( (ini <= mid) && (fin > mid) ) || ( (ini > mid) && (fin <= mid)) );
            s->left->menor = encontrar_Menor(s->left,ini,fin);
            s->right->menor = encontrar_Menor(s->right,ini,fin);

        return min(s->left->menor,s->right->menor);
        //MINIMO DE UN RANGO
}

Auto * SegmentTree::get_Mayor_Rango(int ini,int fin){
    Auto * caro;
    caro = encontrar_Mayor(this->raiz,ini,fin);
    return caro;
}

Auto * SegmentTree::encontrar_Mayor(NodoTree* &s,int ini,int fin){
        cout<<"MAYOR"<<endl;
        cout<<"[ini:"<<ini<<"; fin:"<<fin<<"]"<<endl;
        cout<<"[Sini:"<<s->modelo_inicio<<"; Sfin:"<<s->modelo_fin<<"]"<<endl;

        if((s->modelo_inicio == ini) && (s->modelo_fin == fin))
            return s->mayor;//DENTRO DEL RANGO
        else if(((s->modelo_inicio < ini) && (s->modelo_fin < ini)) ||((s->modelo_inicio > fin) && (s->modelo_fin > fin)))
            return NULL;// FUERA DE RANGO
        else{
            int mid = (s->modelo_inicio + s->modelo_fin)/2;//MITAD

            if((ini <= mid) && (fin <= mid)) //IZQUIERDA
                s->left->mayor = encontrar_Mayor(s->left,ini,fin);

            if((ini > mid) && (fin > mid)) //DERECHA
                s->right->mayor = encontrar_Mayor(s->right,ini,fin);

            if(( (ini <= mid) && (fin > mid) ) || ( (ini > mid) && (fin <= mid)) ){// CASO DOS NODOS SEPARADOS POR LA MITAD
                s->left->mayor = encontrar_Mayor(s->left,ini,fin);
                s->right->mayor = encontrar_Mayor(s->right,ini,fin);
            }
            return min(s->left->mayor,s->right->mayor);//MINIMO DE UN RANGO
        }
}


