#ifndef ARBOL_B_H
#define ARBOL_B_H
#include <iostream>
using namespace std;
class ArbolB {
    struct Nodo { int n; bool hoja; int k[3]; Nodo* hijo[4]; Nodo(bool h):n(0),hoja(h){for(int i=0;i<4;i++)hijo[i]=nullptr;} };
    Nodo* raiz;
    void dividir(Nodo*x,int i,Nodo*y){
        Nodo*z=new Nodo(y->hoja); z->n=1; z->k[0]=y->k[2];
        if(!y->hoja){z->hijo[0]=y->hijo[2];z->hijo[1]=y->hijo[3];}
        y->n=1;
        for(int j=x->n;j>=i+1;j--)x->hijo[j+1]=x->hijo[j];
        x->hijo[i+1]=z;
        for(int j=x->n-1;j>=i;j--)x->k[j+1]=x->k[j];
        x->k[i]=y->k[1];x->n++;
    }
    void insertarNoLleno(Nodo*x,int v){
        int i=x->n-1;
        if(x->hoja){while(i>=0&&v<x->k[i]){x->k[i+1]=x->k[i];i--;}x->k[i+1]=v;x->n++;}
        else{while(i>=0&&v<x->k[i])i--;i++;if(x->hijo[i]->n==3){dividir(x,i,x->hijo[i]);if(v>x->k[i])i++;}insertarNoLleno(x->hijo[i],v);}
    }
    bool buscar(Nodo*x,int v)const{if(!x)return false;int i=0;while(i<x->n&&v>x->k[i])i++;if(i<x->n&&v==x->k[i])return true;return x->hoja?false:buscar(x->hijo[i],v);}
    void recorrer(Nodo*x)const{if(!x)return;for(int i=0;i<x->n;i++){if(!x->hoja)recorrer(x->hijo[i]);cout<<x->k[i]<<" ";}if(!x->hoja)recorrer(x->hijo[x->n]);}
    void liberar(Nodo*x){if(!x)return;if(!x->hoja)for(int i=0;i<=x->n;i++)liberar(x->hijo[i]);delete x;}
public:
    ArbolB():raiz(nullptr){} ~ArbolB(){liberar(raiz);}
    bool buscar(int v)const{return buscar(raiz,v);}
    void insertar(int v){if(buscar(v))return;if(!raiz){raiz=new Nodo(true);raiz->k[0]=v;raiz->n=1;return;}if(raiz->n==3){Nodo*s=new Nodo(false);s->hijo[0]=raiz;dividir(s,0,raiz);raiz=s;}insertarNoLleno(raiz,v);}
    void mostrar()const{if(!raiz){cout<<"Arbol B vacio.\\n";return;}recorrer(raiz);cout<<"\\n";}
};
#endif
