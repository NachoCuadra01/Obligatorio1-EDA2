#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class HeapMin {
    public:
        long long total = 0;
        long long* array;
        int largo;


         void swap(long long*& array, int pos){
            long long a = array[pos];
            while (pos >= 2){
                if(a < array[(pos)/2]){
                    array[pos] = array[(pos)/2];
                    array[(pos)/2] = a;
                }
                pos = pos/2;
                a = array[pos];
            } 
        }

        void hundir(long long*&array, int pos){
            if(!array || pos * 2 >= largo) return;
            long long a = array[pos];
            int posH1 = pos*2; 
            int posH2=  pos*2 + 1;
            int posMin;
            if(posH2 < largo && array[posH2] < array[posH1]) posMin = posH2;
            else posMin = posH1;
            if(a>array[posMin]){
                array[pos] = array[posMin];
                array[posMin] = a;
                hundir(array, posMin);
            }
        }

        void eliminar(long long*& array){
            if (!array) return;
            array[1] = array[largo - 1];
            largo--;
            hundir(array, 1);   
        }
       

        void agregar(long long*&array, long long dato, int pos){
            array[pos] = dato;
            swap(array, pos);
        }

        void consolidar(long long*& array){ //contar que cambiamos de int a long long, y que cambiamos consolidar de recursivo a while porque no daba el orden
            while(largo >= 3){
                long long valor1 = array[1];
                long long valor2;
                if (largo > 3) valor2 = min(array[2], array[3]);
                else valor2 = array[2];
                long long costo = valor1 + valor2;
                total += costo;
                eliminar(array);
                eliminar(array);
                agregar(array, costo, largo);
                largo++;
            }
        }

};



int main() {
    HeapMin heap;
    int cantArchivos;
    cin >> cantArchivos;
    heap.largo = cantArchivos+1;
    heap.array = new long long[cantArchivos+1];
    for(int i = 1; i <= cantArchivos; i++){
        long long tamArchivo;
        cin >> tamArchivo;
        heap.agregar(heap.array, tamArchivo, i);
    }
    heap.consolidar(heap.array);
    cout << heap.total;
    delete[] heap.array;
    return 0;
}