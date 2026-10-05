#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;



class OrdenCompilacion{
    public:

    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int d) : dato(d), siguiente(NULL) {}
    };
    struct modulo {
        int prioridad;
        int numero;
    };

    struct heapMin{
        modulo* array;
        int largo;
        int cantVertices;
        heapMin (int l) : largo(l+1), cantVertices(0){
                array = new modulo[l+1];
                for (int i = 1; i < largo; i++){
                    array[i].numero = -1;
                    array[i].prioridad = INT_MAX;   
                }         
            }
    }; 


    void swap(heapMin& h, int pos){
            if(pos>= h.largo) return;
            modulo a = h.array[pos];
            while (pos >= 2){
                if(a.prioridad < h.array[(pos)/2].prioridad){
                    h.array[pos] = h.array[(pos)/2];
                    h.array[(pos)/2] = a;
                }
                else if(a.prioridad == h.array[(pos)/2].prioridad){
                    if(h.array[(pos)/2].numero < a.numero){
                        h.array[pos] = h.array[(pos)/2];
                        h.array[(pos)/2] = a;
                    }
                }
                pos = pos/2;
                a = h.array[pos];
            } 
        }

        void hundir(heapMin& h, int pos){
            if(!h.array || pos * 2 >= h.largo) return;
            modulo a = h.array[pos];
            int posH1 = pos*2; 
            int posH2=  pos*2 + 1;
            int posMin;
            if(posH2 < h.largo && h.array[posH2].prioridad < h.array[posH1].prioridad) posMin = posH2;
            else if(h.array[posH2].prioridad == h.array[posH1].prioridad){
                if(h.array[posH2].numero < h.array[posH1].numero) posMin = posH2;
                else posMin = posH1;
            }
            else posMin = posH1; 
            if(a.prioridad > h.array[posMin].prioridad){
                h.array[pos] = h.array[posMin];
                h.array[posMin] = a;
                hundir(h, posMin);
            }
            else if (a.prioridad == h.array[posMin].prioridad){
                if(h.array[posMin].numero < a.numero) {
                    h.array[pos] = h.array[posMin];
                    h.array[posMin] = a;
                    hundir(h, posMin);
                }
            }
        }

        int eliminar(heapMin& h){
            if (!h.array) return;
            int num = h.array[1].numero;
            h.array[1] = h.array[h.largo - 1];
            h.array--;
            hundir(h, 1);   
            return num;
        }


        void agregar(heapMin& h, int prioridad, int numero){
            h.array[h.largo-1].numero = numero;
            h.array[h.largo-1].prioridad = prioridad;
            swap(h, h.largo-1);
            h.cantVertices++;
        }

        void compilador(int largo, int* ascendientes, int* prioridades, Nodo** vecinos){
            heapMin modulos(largo-1);
            int* orden = new int[largo-1];
            int cant = 0;

            for (int i = 1; i < largo; i++){
                if(ascendientes[i] == 0) agregar(modulos, prioridades[i], i);           
            }
            
            while(modulos.cantVertices > 0){
                int v = eliminar(modulos); 
                Nodo* vec = vecinos[v];
                orden[cant] = v;
                cant++;
                while (!vec){
                    ascendientes[vec->dato]--;
                    if(ascendientes[vec->dato] == 0) agregar (modulos, prioridades[vec->dato], vec->dato); 
                    vec = vec->siguiente;
                }
                
                
            }
            if(cant!= largo-1) cout << 'ciclo';
            else for(int i = 0; i < largo-1; i++) cout << orden[i] << '\n';
        }


};

int main(){
    
    //int* prio = new int[largo+1]();
    //int* ascendientes
    // hacer que sume uno por cada padre
    return 0;
}