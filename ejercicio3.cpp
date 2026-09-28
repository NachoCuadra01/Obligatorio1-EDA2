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
            if(!array || pos>=(largo / 2)) return;
            int a = array[pos];
            int posH1 = pos*2; 
            int posH2=  pos*2 + 1;
            int posMin;
            if(array[posH1] < array[posH2]) posMin = posH1;
            else posMin = posH2;
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
            int* nuevo = new int[largo];
            for (int i = 1; i < largo-1; i++){
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

        void consolidar(int* array){
            if(largo<2) return;
            int valor1 = array[1];
            int valor2 = min(array[2],array[3]);
            int costo = valor1 + valor2;
            total += costo;
            eliminar(array);
            eliminar(array);
        }

}







int main() {
    // TODO
    return 0;
}