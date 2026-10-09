#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

#ifndef MFSET_H
#define MFSET_H

class Arista {
    public:
    int origen;
    int destino;
    int costo;
    Arista(int o, int d, int c): origen(o), destino(d), costo(c) {}
    Arista(): origen(0), destino(0), costo(0) {}
};

// MinHeap de aristas por costo: el minimo siempre esta en la posicion 0
class HeapAristas {
    private:
    Arista * datos;
    int largo;
    int cantidad;

    int posPadre(int pos) {
        return (pos - 1) / 2;
    }
    int posHijoIzq(int pos) {
        return 2 * pos + 1;
    }
    int posHijoDer(int pos) {
        return 2 * pos + 2;
    }
    void intercambiar(int a, int b) {
        Arista tmp = this->datos[a];
        this->datos[a] = this->datos[b];
        this->datos[b] = tmp;
    }
    void flotar(int pos) {
        if (pos == 0) return; // es la raiz
        int pad = posPadre(pos);
        if (this->datos[pos].costo < this->datos[pad].costo) {
            intercambiar(pos, pad);
            flotar(pad);
        }
    }
    void hundir(int pos) {
        int izq = posHijoIzq(pos);
        if (izq >= this->cantidad) return; // es una hoja
        int menor = izq;
        int der = posHijoDer(pos);
        if (der < this->cantidad && this->datos[der].costo < this->datos[menor].costo) {
            menor = der;
        }
        if (this->datos[menor].costo < this->datos[pos].costo) {
            intercambiar(menor, pos);
            hundir(menor);
        }
    }

    public:
    HeapAristas(int n) {
        this->largo = n;
        this->cantidad = 0;
        this->datos = new Arista[this->largo];
    }
    bool esVacio() {
        return this->cantidad == 0;
    }
    void insertar(Arista a) {
        if (this->cantidad == this->largo) return; // esta lleno
        this->datos[this->cantidad] = a;
        this->cantidad ++;
        flotar(this->cantidad - 1);
    }
    Arista obtenerMinimo() {
        return this->datos[0];
    }
    void eliminarMinimo() {
        this->datos[0] = this->datos[this->cantidad - 1];
        this->cantidad --;
        hundir(0);
    }
};


class MFSet {
    private:
    int * padre;
    int * elementos; // Cuantos elementos tiene el conjunto
    int largo;

    public:
    MFSet(int n) {
        this->largo = n;
        this->padre = new int[this->largo];
        this->elementos = new int[this->largo];
        for (int i = 0; i < this->largo; i ++) {
            this->padre[i] = i;
            this->elementos[i] = 1;
        }
    }
    int representante(int a) {
        if (a == this->padre[a]) {
            return a;
        }
        this->padre[a] = representante(this->padre[a]); // compresion de caminos
        return this->padre[a];
    }
    bool unir(int a, int b) { // devuelve si pudo unir o no
        int repA = representante(a);
        int repB = representante(b);
        if (repA == repB){
            return false;
        }
        if (this->elementos[repA] > this->elementos[repB]) { // Optimizacion por Tamanio :)
            this->padre[repB] = repA;
            this->elementos[repA] += this->elementos[repB];
        } else {
            this->padre[repA] = repB;
            this->elementos[repB] += this->elementos[repA];
        }
        return true;
    }
};

#endif





int main()
{
    // TODO
    return 0;
}