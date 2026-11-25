#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <string>
using namespace std;
struct VerticeG {string nombre;VerticeG*sig;struct Arista*ady;VerticeG(const string&n):nombre(n),sig(nullptr),ady(nullptr){}};
struct Arista {VerticeG*destino;Arista*sig;Arista(VerticeG*d):destino(d),sig(nullptr){}};
class Grafo {
    VerticeG*vertices; bool dirigido;
    VerticeG*buscarV(const string&n)const{for(VerticeG*v=vertices;v;v=v->sig)if(v->nombre==n)return v;return nullptr;}
    void conectar(VerticeG*a,VerticeG*b){for(Arista*x=a->ady;x;x=x->sig)if(x->destino==b)return;Arista*x=new Arista(b);x->sig=a->ady;a->ady=x;}
public:
    Grafo(bool d=false):vertices(nullptr),dirigido(d){}
    ~Grafo(){while(vertices){VerticeG*v=vertices;vertices=v->sig;while(v->ady){Arista*a=v->ady;v->ady=a->sig;delete a;}delete v;}}
    bool agregarVertice(const string&n){if(buscarV(n))return false;VerticeG*v=new VerticeG(n);v->sig=vertices;vertices=v;return true;}
    bool agregarArista(const string&a,const string&b){VerticeG*x=buscarV(a),*y=buscarV(b);if(!x||!y)return false;conectar(x,y);if(!dirigido)conectar(y,x);return true;}
    void mostrar()const{if(!vertices){cout<<"Grafo vacio.\\n";return;}for(VerticeG*v=vertices;v;v=v->sig){cout<<v->nombre<<" -> ";for(Arista*a=v->ady;a;a=a->sig)cout<<a->destino->nombre<<" ";cout<<"\\n";}}
    bool esDirigido()const{return dirigido;}
};
#endif
