#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
       int content;
       struct nodo *sig;
}*List;

void inicio(List &lista,  int num_2){
    List a;
    a = new nodo;
    a->content = num_2;
    a->sig = lista;
    lista  = a;
}

void Fin(List &lista, int val){
    List a, c = new nodo;
    c->content  = val;
    c->sig = NULL;

    if(lista==NULL){
        lista = c;
    }
    else{
        a = lista;
        while(a->sig!=NULL){
            a = a->sig;
        }
        a->sig = c;
    }
}


void Lista(List lista){
    int i = 0;
    while(lista != NULL){
        cout <<' '<< i+1 <<") " << lista->content << endl;
        lista = lista->sig;
        i++;
    }
}


void menu(){
    cout<<" 1. Inserar al inicio "<<endl;
    cout<<" 2. Insertar al final "<<endl;
    cout<<" 3. Mostrar "<<endl;
    cout<<"Opcion a elegir: ";
}


int main(){
    List lista = NULL;
    int opc;
    int num;

    do{
        menu();
        cin>> opc;

        switch(opc){
            case 1:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> num;
                 inicio(lista, num);
            break;

            case 2:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> num;
                 Fin(lista, num );
            break;

            case 3:
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 Lista(lista);
            break;

        }

        cout<<endl<<endl;
    }while(opc!=4);
    return 0;
}


