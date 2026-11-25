#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include <iostream>
using namespace std;

struct NodoArbol {
    int id;
    NodoArbol* izq;
    NodoArbol* der;
};

class ArbolBinario {
private:
    NodoArbol* raiz;

    NodoArbol* insertarRec(NodoArbol* actual, int id) {
        if (actual == nullptr)
            return new NodoArbol{id, nullptr, nullptr};
        if (id < actual->id)
            actual->izq = insertarRec(actual->izq, id);
        else if (id > actual->id)
            actual->der = insertarRec(actual->der, id);
        return actual; // No permite IDs duplicados.
    }

    bool buscarRec(NodoArbol* actual, int id) const {
        if (actual == nullptr) return false;
        if (actual->id == id) return true;
        if (id < actual->id) return buscarRec(actual->izq, id);
        return buscarRec(actual->der, id);
    }

    void inordenRec(NodoArbol* actual) const {
        if (actual == nullptr) return;
        inordenRec(actual->izq);
        cout << actual->id << " ";
        inordenRec(actual->der);
    }

    void preordenRec(NodoArbol* actual) const {
        if (actual == nullptr) return;
        cout << actual->id << " ";
        preordenRec(actual->izq);
        preordenRec(actual->der);
    }

    void postordenRec(NodoArbol* actual) const {
        if (actual == nullptr) return;
        postordenRec(actual->izq);
        postordenRec(actual->der);
        cout << actual->id << " ";
    }

    int alturaRec(NodoArbol* actual) const {
        if (actual == nullptr) return 0;
        int ai = alturaRec(actual->izq);
        int ad = alturaRec(actual->der);
        return 1 + (ai > ad ? ai : ad);
    }

    int contarRec(NodoArbol* actual) const {
        if (actual == nullptr) return 0;
        return 1 + contarRec(actual->izq) + contarRec(actual->der);
    }

    NodoArbol* menorNodo(NodoArbol* actual) {
        while (actual != nullptr && actual->izq != nullptr)
            actual = actual->izq;
        return actual;
    }

    NodoArbol* eliminarRec(NodoArbol* actual, int id, bool& eliminado) {
        if (actual == nullptr) return nullptr;
        if (id < actual->id) {
            actual->izq = eliminarRec(actual->izq, id, eliminado);
        } else if (id > actual->id) {
            actual->der = eliminarRec(actual->der, id, eliminado);
        } else {
            eliminado = true;
            if (actual->izq == nullptr && actual->der == nullptr) {
                delete actual;
                return nullptr;
            }
            if (actual->izq == nullptr) {
                NodoArbol* temp = actual->der;
                delete actual;
                return temp;
            }
            if (actual->der == nullptr) {
                NodoArbol* temp = actual->izq;
                delete actual;
                return temp;
            }
            NodoArbol* sucesor = menorNodo(actual->der);
            actual->id = sucesor->id;
            bool eliminadoSucesor = false;
            actual->der = eliminarRec(actual->der, sucesor->id, eliminadoSucesor);
        }
        return actual;
    }

    void liberarRec(NodoArbol* actual) {
        if (actual == nullptr) return;
        liberarRec(actual->izq);
        liberarRec(actual->der);
        delete actual;
    }

public:
    ArbolBinario() : raiz(nullptr) {}
    ~ArbolBinario() { liberarRec(raiz); }

    bool estaVacio() const { return raiz == nullptr; }
    void insertar(int id) { raiz = insertarRec(raiz, id); }
    bool buscar(int id) const { return buscarRec(raiz, id); }

    bool eliminar(int id) {
        bool eliminado = false;
        raiz = eliminarRec(raiz, id, eliminado);
        return eliminado;
    }

    void mostrarInorden() const {
        if (estaVacio()) { cout << "El arbol esta vacio.\n"; return; }
        inordenRec(raiz); cout << "\n";
    }
    void mostrarPreorden() const {
        if (estaVacio()) { cout << "El arbol esta vacio.\n"; return; }
        preordenRec(raiz); cout << "\n";
    }
    void mostrarPostorden() const {
        if (estaVacio()) { cout << "El arbol esta vacio.\n"; return; }
        postordenRec(raiz); cout << "\n";
    }
    int altura() const { return alturaRec(raiz); }
    int cantidadNodos() const { return contarRec(raiz); }
};

#endif
