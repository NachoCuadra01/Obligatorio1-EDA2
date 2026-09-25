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
            while (a < array[(pos)*2] && pos != 1){
                array[pos] = array[(pos)*2];
                array[(pos)*2] = a;
                pos = pos*2;
                a = array[pos];
            } 
        }



        void eliminar(int*& array, int& largo){
            if (!array) return;
            int min = array[1];
            array[1] = array[largo - 1];
            swap(array, 1);
            largo--;





            int* nuevo = new int[largo-1];
            

        }
       

        void agregar(int*&array, int dato){
            array[largo-1] = dato;
            swap(array, largo-1);
        }

        void consolidar(int* array){
            int valor1 = array[0];
            int valor2 = array[1];
            int costo = valor1 + valor2;
            total += costo;
            eliminar();
        }

}







int main(){
    // TODO
    return 0;
}