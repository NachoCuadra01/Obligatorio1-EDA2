#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class HeapMin {
    public:
        int total = 0;
        int* array;
        int largo;


         void swap(int*& array, int pos){
            int a = array[pos];
            while (pos >= 2){
                if(a < array[(pos)/2]){
                    array[pos] = array[(pos)/2];
                    array[(pos)/2] = a;
                }
                pos = pos/2;
                a = array[pos];
            } 
        }

        void hundir(int*&array, int pos){
            if(!array || pos * 2 >= largo) return;
            int a = array[pos];
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

        void eliminar(int*& array){
            if (!array) return;
            array[1] = array[largo - 1];
            largo--;
            int* nuevo = new int[largo + 1];
            for (int i = 1; i < largo; i++){
                nuevo[i] = array[i];
            }
            delete[] array;
            array = nuevo;
            hundir(array, 1); 
        }
       

        void agregar(int*&array, int dato, int pos){
            array[pos] = dato;
            swap(array, pos);
        }

        void consolidar(int*& array){
            if(largo < 3) return;
            int valor1 = array[1];
            int valor2;
            if (largo > 3) valor2 = min(array[2], array[3]);
            else valor2 = array[2];
            int costo = valor1 + valor2;
            total += costo;
            eliminar(array);
            eliminar(array);
            agregar(array, costo, largo);
            largo++;
            consolidar(array);
        }

};



int main() {
    HeapMin heap;
    int cantArchivos;
    cin >> cantArchivos;
    heap.largo = cantArchivos+1;
    heap.array = new int[cantArchivos+1];
    for(int i = 1; i <= cantArchivos; i++){
        int tamArchivo;
        cin >> tamArchivo;
        heap.agregar(heap.array, tamArchivo, i);
    }
    heap.consolidar(heap.array);
    cout << heap.total;
    delete[] heap.array;
    return 0;
}