#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H
#include <iostream>
#include <string>
using namespace std;
struct NodoSolicitud { string cliente, servicio; NodoSolicitud* sig; NodoSolicitud(const string&c,const string&s):cliente(c),servicio(s),sig(nullptr){} };
struct NivelPrioridad { int prioridad; NodoSolicitud* frente; NodoSolicitud* fin; NivelPrioridad* sig; NivelPrioridad(int p):prioridad(p),frente(nullptr),fin(nullptr),sig(nullptr){} };
class ColaPrioridad {
    NivelPrioridad* niveles;
public:
    ColaPrioridad():niveles(nullptr){}
    ~ColaPrioridad(){ while(niveles){ NivelPrioridad*n=niveles; niveles=niveles->sig; while(n->frente){NodoSolicitud*t=n->frente;n->frente=t->sig;delete t;} delete n;} }
    void encolar(const string& c,const string&s,int p){
        NivelPrioridad** q=&niveles; while(*q && (*q)->prioridad<=p) q=&((*q)->sig);
        if(!*q || (*q)->prioridad!=p){NivelPrioridad*n=new NivelPrioridad(p);n->sig=*q;*q=n;}
        NivelPrioridad*n=*q; NodoSolicitud*x=new NodoSolicitud(c,s);
        if(!n->fin)n->frente=n->fin=x;else{n->fin->sig=x;n->fin=x;}
    }
    bool atender(string& c,string&s,int&p){
        if(!niveles) return false;
        NivelPrioridad*n=niveles; NodoSolicitud*x=n->frente;
        c=x->cliente;s=x->servicio;p=n->prioridad;n->frente=x->sig;if(!n->frente)n->fin=nullptr;delete x;
        if(!n->frente){niveles=n->sig;delete n;} return true;
    }
    void mostrar()const{
        if(!niveles){cout<<"No hay solicitudes prioritarias.\\n";return;}
        for(NivelPrioridad*n=niveles;n;n=n->sig){cout<<"Prioridad "<<n->prioridad<<": ";for(NodoSolicitud*x=n->frente;x;x=x->sig)cout<<x->cliente<<" ("<<x->servicio<<") -> ";cout<<"FIN\\n";}
    }
};
#endif
