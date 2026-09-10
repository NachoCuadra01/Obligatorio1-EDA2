#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

template <class T>

class AVL{
    private:
    public:
        struct nodoAVL {
            T dato;
            nodoAVL* izq, *der;
            int altura;
            nodoAVL(T d) : dato(d), altura(1), izq(NULL), der(NULL); 
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

        void altaP(AVL a, T pieza){
            if (!a) AVL nuevo = new nodoAVL(pieza);
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

        
        char* buscar(AVL a, T pieza){ 
            if (!a) return "no";
            if (a->dato == pieza) return "si";
            if (a->dato > pieza) return buscar(a->izq, pieza);
            else return buscar(a->der, pieza);
        }


        T rango(AVL a,T desde,T hasta){
            if (!a) return "";




        }




};




