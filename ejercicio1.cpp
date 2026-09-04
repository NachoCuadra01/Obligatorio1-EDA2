#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct nodoAVL{
    int altura;
    string titulo;
    int catalogo;
    nodoAVL* izq;
    nodoAVL* der;
}; typedef nodoAVL* AVL;

    int altura(AVL a) {
        if (!a) return 0;
        return a->altura;
    }

    void actualizarAltura(AVL a) {
        a->altura = 1 + max(altura(a->izq), altura(a->der));
    }

    int calcularBalance(AVL a) {
        return altura(a->der) - altura(a->izq);
    }

    Nodo * rotacionIzq(Nodo * A, Nodo * B) {
            A->der = B->izq;
            B->izq = A;
            ActualizarAltura(A);
            ActualizarAltura(B);
            return B;
        }

    Nodo * rotacionDer(Nodo * A, Nodo * B) {
        A->izq = B->der;
        B->der = A;
        ActualizarAltura(A);
        ActualizarAltura(B);
        return B;
    }

    void altaP(AVL p, string t){
        if (!p){
            AVL nuevo = new nodoAVL;
            nuevo->titulo = t;
            p = nuevo;
        }
        if(p->titulo == t) return;
        else if (t> p->titulo) altaP(p->der, t);
        else altaP(p->izq, t);
        actualizarAltura(p);
        int balance = calcularBalance(p);
    }

    void altaM(AVL m, int c){
        if (!m){
            AVL nuevo = new nodoAVL;
            nuevo->catalogo = c;
            m = nuevo;
        }
        if(m->catalogo == c) return;
        else if (c> m->catalogo) altaM(m->der, c);
        else altaM(m->izq, c);
        actualizarAltura(m);
        int balance = calcularBalance(m);
        if (balance > 1 && t->der->dato < x) {
            rotacionIzq(t, t->der);
            return;
        }
        else if (balance > 1 && t->der->dato > x) {
            t->der = rotacionDer(t->der, t->der->izq);
            rotacionIzq(t, t->der);
            return;
        }
        else if (balance < -1 && t->izq->dato > x) {
            rotacionDer(t, t->izq);
            return;
        }
        else if (balance < -1 && t->izq->dato < x) {
            t->izq = rotacionIzq(t->izq, t->izq->der);
            rotacionDer(t, t->izq);
            return;
        }

    }