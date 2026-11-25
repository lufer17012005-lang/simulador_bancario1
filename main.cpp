#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "ListaCuentas.h"
#include "ColaTurnos.h"
#include "PilaHistorial.h"
#include "Operaciones.h"
#include "ArbolBinario.h"
#include "ColaPrioridad.h"
#include "ArbolB.h"
#include "Grafo.h"
using namespace std;
int leerEntero(const string&m){int x;cout<<m;while(!(cin>>x)){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"Entrada invalida. "<<m;}cin.ignore(numeric_limits<streamsize>::max(),'\n');return x;}
double leerMonto(const string&m){double x;cout<<m;while(!(cin>>x)){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"Entrada invalida. "<<m;}cin.ignore(numeric_limits<streamsize>::max(),'\n');return x;}
string leerTexto(const string&m){string s;cout<<m;getline(cin,s);return s;}
int main(){
 ListaCuentas cuentas;ColaTurnos turnos;PilaHistorial historial;ArbolBinario abb;ArbolB arbolB;ColaPrioridad prioridad;Grafo dirigido(true),noDirigido(false);
 int op;
 do{
 cout<<"\n===== SIMULADOR BANCARIO COMPLETO =====\n"
 <<"1 Abrir cuenta\n2 Consultar cuenta\n3 Depositar\n4 Retirar\n5 Transferir\n"
 <<"6 Mostrar cuentas adelante\n7 Mostrar cuentas atras\n8 Solicitar turno FIFO\n9 Atender turno FIFO\n10 Ver turnos\n"
 <<"11 Ver historial\n12 ABB inorden\n13 ABB preorden\n14 ABB postorden\n15 Buscar en ABB\n16 Datos ABB\n17 Eliminar cuenta\n"
 <<"18 Solicitud prioritaria\n19 Atender prioridad\n20 Mostrar cola prioritaria\n"
 <<"21 Insertar ID en arbol B\n22 Buscar ID en arbol B\n23 Mostrar arbol B\n"
 <<"24 Agregar vertice a ambos grafos\n25 Agregar arco dirigido\n26 Agregar arista no dirigida\n27 Mostrar grafo dirigido\n28 Mostrar grafo no dirigido\n0 Salir\n";
 op=leerEntero("Opcion: ");
 switch(op){
 case 1:{Cuenta c;c.id=leerEntero("ID: ");c.titular=leerTexto("Titular: ");c.tipo=leerTexto("Tipo (Ahorros/Corriente): ");c.saldo=leerMonto("Saldo inicial: ");if(c.id<=0||c.saldo<0)cout<<"ID debe ser positivo y saldo no negativo.\n";else if(!cuentas.agregar(c))cout<<"ID duplicado.\n";else{abb.insertar(c.id);arbolB.insertar(c.id);historial.push("Apertura de cuenta "+to_string(c.id));cout<<"Cuenta creada.\n";}break;}
 case 2:{Cuenta*c=cuentas.buscar(leerEntero("ID: "));if(c)cout<<c->titular<<" | "<<c->tipo<<" | $"<<fixed<<setprecision(2)<<c->saldo<<"\n";else cout<<"Cuenta no encontrada.\n";break;}
 case 3:case 4:{int id=leerEntero("ID: ");double m=leerMonto("Monto: ");bool ok=(op==3)?depositar(cuentas.buscar(id),m):retirar(cuentas.buscar(id),m);if(ok){cout<<"Operacion realizada.\n";historial.push(string(op==3?"Deposito ":"Retiro ")+to_string(m)+" cuenta "+to_string(id));}else cout<<"Operacion invalida.\n";break;}
 case 5:{int a=leerEntero("Cuenta origen: "),b=leerEntero("Cuenta destino: ");double m=leerMonto("Monto: ");if(transferir(cuentas.buscar(a),cuentas.buscar(b),m)){cout<<"Transferencia realizada.\n";historial.push("Transferencia "+to_string(m)+" de "+to_string(a)+" a "+to_string(b));}else cout<<"Transferencia invalida.\n";break;}
 case 6:cuentas.mostrarAdelante();break;case 7:cuentas.mostrarAtras();break;
 case 8:{string c=leerTexto("Cliente: "),s=leerTexto("Servicio: ");int n=turnos.encolar(c,s);cout<<"Turno "<<n<<"\n";historial.push("Turno registrado "+to_string(n));break;}
 case 9:{Turno t;if(turnos.desencolar(t))cout<<"Atendiendo "<<t.numero<<" - "<<t.cliente<<" - "<<t.servicio<<"\n";else cout<<"No hay turnos.\n";break;}
 case 10:turnos.mostrar();break;case 11:historial.mostrar();break;
 case 12:abb.mostrarInorden();break;case 13:abb.mostrarPreorden();break;case 14:abb.mostrarPostorden();break;
 case 15:{int id=leerEntero("ID: ");cout<<(abb.buscar(id)?"Encontrado.\n":"No encontrado.\n");break;}
 case 16:cout<<"Altura: "<<abb.altura()<<" | Nodos: "<<abb.cantidadNodos()<<"\n";break;
 case 17:{int id=leerEntero("ID a eliminar: ");if(cuentas.eliminar(id)){abb.eliminar(id);cout<<"Cuenta eliminada. (El arbol B conserva su indice historico; no implementa borrado.)\n";historial.push("Eliminacion cuenta "+to_string(id));}else cout<<"Cuenta inexistente.\n";break;}
 case 18:{string c=leerTexto("Cliente: "),s=leerTexto("Servicio: ");int p=leerEntero("Prioridad (1 urgente, numero mayor menos urgente): ");if(p<1)cout<<"Prioridad invalida.\n";else{prioridad.encolar(c,s,p);cout<<"Solicitud registrada.\n";}break;}
 case 19:{string c,s;int p;if(prioridad.atender(c,s,p))cout<<"Atendiendo "<<c<<" | "<<s<<" | prioridad "<<p<<"\n";else cout<<"No hay solicitudes.\n";break;}
 case 20:prioridad.mostrar();break;
 case 21:{int id=leerEntero("Clave entera: ");arbolB.insertar(id);cout<<"Insertada (sin duplicados).\n";break;}
 case 22:{int id=leerEntero("Clave: ");cout<<(arbolB.buscar(id)?"Encontrada.\n":"No encontrada.\n");break;}
 case 23:arbolB.mostrar();break;
 case 24:{string n=leerTexto("Nombre del vertice: ");bool a=dirigido.agregarVertice(n),b=noDirigido.agregarVertice(n);cout<<((a&&b)?"Vertice agregado a ambos grafos.\n":"Nombre repetido o inconsistencia entre grafos.\n");break;}
 case 25:{string a=leerTexto("Origen: "),b=leerTexto("Destino: ");cout<<(dirigido.agregarArista(a,b)?"Arco dirigido agregado.\n":"Verifique que ambos vertices existan.\n");break;}
 case 26:{string a=leerTexto("Vertice 1: "),b=leerTexto("Vertice 2: ");cout<<(noDirigido.agregarArista(a,b)?"Arista no dirigida agregada.\n":"Verifique que ambos vertices existan.\n");break;}
 case 27:dirigido.mostrar();break;case 28:noDirigido.mostrar();break;
 case 0:cout<<"Fin del programa.\n";break;default:cout<<"Opcion no valida.\n";
 }
 }while(op!=0);
 return 0;
}
