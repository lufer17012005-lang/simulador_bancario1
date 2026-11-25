#ifndef PILA_HISTORIAL_H
#define PILA_HISTORIAL_H
#include <iostream>
#include <string>
using namespace std;
struct NodoHistorial { string dato; NodoHistorial* sig; NodoHistorial(const string& d):dato(d),sig(nullptr){} };
class PilaHistorial {
    NodoHistorial* tope;
public:
    PilaHistorial():tope(nullptr){}
    ~PilaHistorial(){ string x; while(pop(x)){} }
    bool estaVacia() const { return tope==nullptr; }
    void push(const string& s){ NodoHistorial* n=new NodoHistorial(s); n->sig=tope; tope=n; }
    bool pop(string& s){ if(!tope)return false; NodoHistorial* t=tope; s=t->dato; tope=t->sig; delete t; return true; }
    bool cima(string& s) const { if(!tope)return false; s=tope->dato; return true; }
    void mostrar() const { if(!tope){cout<<"El historial esta vacio.\\n";return;} int i=1; for(NodoHistorial*p=tope;p;p=p->sig) cout<<i++<<". "<<p->dato<<"\\n"; }
};
#endif
