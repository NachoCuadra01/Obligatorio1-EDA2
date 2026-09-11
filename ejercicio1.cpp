#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

template <class T>

class AVLbalanceado{
    private:
    //falta algo aca
    public:
        struct nodoAVL {
            T dato;
            nodoAVL* izq, *der;
            int altura;
            nodoAVL(T d) : dato(d), altura(1), izq(NULL), der(NULL) {} 
        }; typedef nodoAVL* AVL;

        AVL crear(T pieza){
            return new nodoAVL(pieza);
        }

        int altura(AVL a){
            if (!a) return 0;
            return a->altura;
        }
        

        void actualizarAltura(AVL& a) {
            if (!a) return;
            a->altura = 1 + max(altura(a->izq), altura(a->der));
        }    

        int calcularBalance(AVL a) {
            return altura(a->der) - altura(a->izq);
        }
       
        AVL rotacionIzq(AVL& A, AVL& B) {
            A->der = B->izq;
            B->izq = A;
            actualizarAltura(A);
            actualizarAltura(B);
            return B;
        }
        
        AVL rotacionDer(AVL& A, AVL& B) {
            A->izq = B->der;
            B->der = A;
            actualizarAltura(A);
            actualizarAltura(B);
            return B;
        }

        void altaP(AVL& a, T pieza){
            if (!a) {
                AVL nuevo = new nodoAVL(pieza);
                a = nuevo;
            }
            if(a->dato == pieza) return;
            else if (pieza > a->dato) altaP(a->der, pieza);
            else altaP(a->izq, pieza);
            actualizarAltura(a);
            int balance = calcularBalance(a);

            if (balance > 1 && a->der->dato < pieza) {
                a = rotacionIzq(a, a->der);
                return;
            }
            else if (balance > 1 && a->der->dato > pieza) {
                a->der = rotacionDer(a->der, a->der);
                a = rotacionIzq(a, a->der);
                return;
            }
            else if (balance < -1 && a->izq->dato > pieza) {
                a = rotacionDer(a, a->izq);
                return;
            }
            else if (balance < -1 && a->izq->catalogo < pieza) {
                a->izq = rotacionIzq(a->izq, a->izq->der);
                a = rotacionDer(a, a->izq);
                return;
            }
        }

        
        bool buscar(AVL a, T dato){ 
            if (!a) return false;
            if (a->dato == dato) return true;
            if (a->dato > dato) return buscar(a->izq, dato);
            else return buscar(a->der, dato);
        }


        T* rangoAux(AVL a, T&* arr, T desde, T hasta, int& pos){
            if (a->dato > desde) rango(a->izq, desde, hasta);

            if (a->dato >= desde && a->dato <= hasta){
                arr[pos] = a->dato;
                pos++;
            }

            if (a->dato < hasta) rango(a->der, desde, hasta);
        }
        

        T* rango(AVL a, T desde, T hasta){
            if (!a) return NULL;
            T* arr = new T[hasta-desde];
            int pos = 0;
            return rangoAux(a, arr, desde, hasta, pos);
        }
            
    
};


    int main(){
        AVLbalanceado<int> monedas;
        AVLbalanceado<string> pinturas; 

        int x;
        cin >> x;
        for (int i = 0; i < x; i++){
            string col1;
            string col2;
            cin >> col1 >> col2;
            if (col1 == "ALTA"){
                if (col2 == "M"){
                    int c;
                    cin >> c;
                    monedas.altaP(c);
                }
            }
            
            
            






        }

        return 0;
    }



