#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

#ifndef MFSET_H
#define MFSET_H

//DECIR QUE AGARRAMOS TODO ESTO DE LO QUE HICIMOS EN CLASE EN AUTORIA
//ACLARAR QUE SOMOS MOGULES Y NOS DIMOS CUENTA DSP QUE PODÍAMOS HABER USADO ESTO EN EL EJ3 Y 4
class Arista {
    public:
    int origen;
    int destino;
    int costo;
    Arista(int o, int d, int c): origen(o), destino(d), costo(c) {}
    Arista(): origen(0), destino(0), costo(0) {}
};

// MinHeap de aristas por costo: el minimo siempre esta en la posicion 1
class HeapAristas {
    private:
    Arista * datos;
    int largo;
    int cantidad;

    int posPadre(int pos) {
        return (pos ) / 2;
    }
    int posHijoIzq(int pos) {
        return 2 * pos;
    }
    int posHijoDer(int pos) {
        return 2 * pos +1;
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
        this->datos = new Arista[this->largo+1];
    }
    bool esVacio() {
        return this->cantidad == 0;
    }
    void insertar(Arista a) {
        if (this->cantidad == this->largo) return; // esta lleno
        this->datos[this->cantidad+1] = a;
        this->cantidad ++;
        flotar(this->cantidad);
    }
    Arista obtenerMinimo() {
        return this->datos[0];
    }
    void eliminarMinimo() {
        this->datos[1] = this->datos[this->cantidad];
        this->cantidad --;
        hundir(1);
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
        if (a == this->padre[a])  return a;
        this->padre[a] = representante(this->padre[a]); // compresion de caminos
        return this->padre[a];
    }
    bool unir(int a, int b) { // devuelve si pudo unir o no
        int repA = representante(a);
        int repB = representante(b);
        if (repA == repB)return false;
        if (this->elementos[repA] > this->elementos[repB]) { //unión por altura
            this->padre[repB] = repA;
            this->elementos[repA] += this->elementos[repB];
        } else {
            this->padre[repA] = repB;
            this->elementos[repB] += this->elementos[repA];
        }
        return true;
    }
};

class ParNacional {
    private:
    int cantRefugios;
    int cantSenderos;
    int maxSenderos;
    Arista * senderos;

    public:
    ParNacional(int v, int e) {
        this->cantRefugios = v;
        this->maxSenderos = e;
        this->cantSenderos = 0;
        this->senderos = new Arista[e];        
    }
    void agregarSendero(int origen, int destino, int costo) {
        if (this->cantSenderos == this->maxSenderos) return;
        this->senderos[this->cantSenderos] = Arista(origen, destino, costo);
        this->cantSenderos++;
    }
};

long long costoMin(ParNacional* park){
    if(!park) return -1;
    int cont = 0;
    long long costoTotal = 0;
    MFSet* conjunto = new MFSet(park->cantRefugios);
    HeapAristas* heap = new HeapAristas(park->maxSenderos);
    for (int i = 1; i <= park->maxSenderos; i++){
        heap->insertar(park->senderos[i]);
    }
    while(!heap->esVacio() && cont < park->cantRefugios-1){
        
    }

    return costoTotal;
}




int main()
{
    // TODO
    return 0;
}

#endif