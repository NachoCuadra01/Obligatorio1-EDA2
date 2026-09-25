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
            while (pos != 1){
                if(a < array[(pos)/2]){
                    array[pos] = array[(pos)/2];
                    array[(pos)/2] = a;
                }
                pos = pos/2;
                a = array[pos];
            } 
        }

        void hundir(int*&array){
            if(!array) return;
            int pos = 1;
            int a = array[pos];
            int posH1 = pos*2; 
            int posH2=  pos*2 + 1;
            int posMin;
            if(array[posH1] < array[posH2]) posMin = posH1;
            else posMin = posH2;
            while(a>array[posMin]){
                array[pos] = array[posMin];
                array[posMin] = a;
                //cambiarle los valores a los ints para chequear si se puede seguir hundiendo
            }
        }

        void eliminar(int*& array){
            if (!array) return;
            array[1] = array[largo - 1];
            hundir(array); //el hundir solamente va aplicar desde el mínimo para abajo, así que no hace falta la pos como parámetro
            largo--;
            int* nuevo = new int[largo-1];
            for (int i = 1; i < largo-1; i++){
                nuevo[i] = array[i];
            }
            delete[] array;
            array = nuevo;
        }
       

        void agregar(int*&array, int dato){
            array[largo-1] = dato;
            swap(array, largo-1);
        }

        void consolidar(int* array){
            if(largo<2) return;
            int valor1 = array[1];
            int valor2 = array[2];
            int costo = valor1 + valor2;
            total += costo;
            //podríamos hacer que se swapeen el primero y el último
            //y el segundo con el penúltimo, ejecutamos eliminar una vez y que elimine a los 2
        }

}







int main() {
    // TODO
    return 0;
}