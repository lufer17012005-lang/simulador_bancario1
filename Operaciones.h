#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Cuenta.h"

inline bool depositar(Cuenta* c, double monto) {
    if (c == nullptr || monto <= 0) return false;
    c->saldo += monto;
    return true;
}

inline bool retirar(Cuenta* c, double monto) {
    if (c == nullptr || monto <= 0 || monto > c->saldo) return false;
    c->saldo -= monto;
    return true;
}

inline bool transferir(Cuenta* origen, Cuenta* destino, double monto) {
    if (origen == nullptr || destino == nullptr || origen == destino) return false;
    if (monto <= 0 || monto > origen->saldo) return false;
    origen->saldo -= monto;
    destino->saldo += monto;
    return true;
}

#endif
