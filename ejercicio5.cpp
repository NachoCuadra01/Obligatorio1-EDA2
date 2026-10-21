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
        if (pos == 1) return; // es la raiz
        int pad = posPadre(pos);
        if (this->datos[pos].costo < this->datos[pad].costo) {
            intercambiar(pos, pad);
            flotar(pad);
        }
    }
    void hundir(int pos) {
        int izq = posHijoIzq(pos);
        if (izq > this->cantidad) return; // es una hoja
        int menor = izq;
        int der = posHijoDer(pos);
        if (der <= this->cantidad && this->datos[der].costo < this->datos[menor].costo) {
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
        return this->datos[1];
    }
    void eliminarMinimo() {
        this->datos[1] = this->datos[this->cantidad];
        this->cantidad --;
        hundir(1);
    }

    void destruir(){
        delete [] this->datos;
        this->datos = NULL;
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

    void destruir(){
        delete [] this->elementos;
        this->elementos = NULL;
        delete[] this->padre;
        this->padre = NULL; 
    }
};

class ParNacional {
    public:
    int cantRefugios;
    int cantSenderos;
    int maxSenderos;
    Arista * senderos;

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

    void destruir(){
        delete [] this->senderos;
        this->senderos = NULL;
    }
};

long long costoMin(ParNacional* p){
    if(!p) return -1;
    int cont = 0;
    long long costoTotal = 0;
    MFSet* conjunto = new MFSet(p->cantRefugios+1);
    HeapAristas* heap = new HeapAristas(p->maxSenderos);
    for (int i = 0; i < p->cantSenderos; i++){
        heap->insertar(p->senderos[i]);
    }
    while(!heap->esVacio() && cont < p->cantRefugios-1){
        Arista a = heap->obtenerMinimo();
        heap->eliminarMinimo();
        int conjuntoOrigen = conjunto->representante(a.origen);
        int conjuntoDestino = conjunto->representante(a.destino);
        if(conjuntoOrigen != conjuntoDestino){
            cont++;
            conjunto->unir(conjuntoOrigen, conjuntoDestino);
            costoTotal += a.costo;
        }
    }
    heap->destruir();
    conjunto->destruir();
    if(cont != p->cantRefugios-1) return -1;
    else return costoTotal;
}




int main()
{
    int vertices;
    int aristas;
    cin >> vertices >> aristas; 
    ParNacional* park = new ParNacional(vertices, aristas);
    for (int i = 0; i < aristas; i++)
    {
        int origen;
        int destino;
        int costo;
        cin >> origen >> destino>> costo;
        park->agregarSendero(origen, destino, costo);
    }
    long long costoMinimo = costoMin(park);
    if(costoMinimo == -1) cout << "imposible" << endl;
    else cout << costoMinimo << endl;
    park->destruir();
    return 0;
}

#endif