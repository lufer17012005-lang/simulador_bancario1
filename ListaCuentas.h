#ifndef LISTA_CUENTAS_H
#define LISTA_CUENTAS_H

#include <iostream>
#include "Cuenta.h"
using namespace std;

struct NodoCuenta {
    Cuenta dato;
    NodoCuenta* sig;
    NodoCuenta* ant;
};

class ListaCuentas {
private:
    NodoCuenta* primero;
    NodoCuenta* ultimo;

public:
    ListaCuentas() : primero(nullptr), ultimo(nullptr) {}

    ~ListaCuentas() {
        while (primero != nullptr) {
            NodoCuenta* temp = primero;
            primero = primero->sig;
            delete temp;
        }
    }

    bool estaVacia() const { return primero == nullptr; }

    Cuenta* buscar(int id) {
        for (NodoCuenta* p = primero; p != nullptr; p = p->sig)
            if (p->dato.id == id) return &p->dato;
        return nullptr;
    }

    bool agregar(const Cuenta& c) {
        if (buscar(c.id) != nullptr) return false;
        NodoCuenta* nuevo = new NodoCuenta{c, nullptr, ultimo};
        if (ultimo == nullptr) primero = nuevo;
        else ultimo->sig = nuevo;
        ultimo = nuevo;
        return true;
    }

    bool eliminar(int id) {
        for (NodoCuenta* p = primero; p != nullptr; p = p->sig) {
            if (p->dato.id == id) {
                if (p->ant != nullptr) p->ant->sig = p->sig;
                else primero = p->sig;
                if (p->sig != nullptr) p->sig->ant = p->ant;
                else ultimo = p->ant;
                delete p;
                return true;
            }
        }
        return false;
    }

    void mostrarAdelante() const {
        if (estaVacia()) { cout << "No hay cuentas registradas.\n"; return; }
        for (NodoCuenta* p = primero; p != nullptr; p = p->sig)
            imprimir(p->dato);
    }

    void mostrarAtras() const {
        if (estaVacia()) { cout << "No hay cuentas registradas.\n"; return; }
        for (NodoCuenta* p = ultimo; p != nullptr; p = p->ant)
            imprimir(p->dato);
    }

private:
    static void imprimir(const Cuenta& c) {
        cout << "ID: " << c.id << " | " << c.titular << " | " << c.tipo
             << " | Saldo: $" << c.saldo << "\n";
    }
};

#endif
