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

    AVL rotacionIzq(AVL A, AVL B) {
            A->der = B->izq;
            B->izq = A;
            actualizarAltura(A);
            actualizarAltura(B);
            return B;
        }

    AVL rotacionDer(AVL A, AVL B) {
        A->izq = B->der;
        B->der = A;
        actualizarAltura(A);
        actualizarAltura(B);
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
        if (balance > 1 && m->der->catalogo < c) {
            rotacionIzq(m, m->der);
            return;
        }
        else if (balance > 1 && m->der->catalogo > c) {
            m->der = rotacionDer(m->der, m->der);
            rotacionIzq(m, m->der);
            return;
        }
        else if (balance < -1 && m->izq->catalogo > c) {
            rotacionDer(m, m->izq);
            return;
        }
        else if (balance < -1 && m->izq->catalogo < c) {
            m->izq = rotacionIzq(m->izq, m->izq->der);
            rotacionDer(m, m->izq);
            return;
        }

    }