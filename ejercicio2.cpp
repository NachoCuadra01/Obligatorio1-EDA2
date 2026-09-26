#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib> 

using namespace std;


class HashAbierto{
    public:
        struct cajon{
            cajon* sig;
            int clavePalabra; //ahora guardamos la clave y no la palabra en si, sino que si la clave que representa cada string
            int cant;
        };

        struct hash{
            cajon** inventario;
            int max;
            int cantCajones;
            int cota;
            hash(int cota) : cota(cota),max(0), cantCajones(0) {
                inventario = new cajon*[cota];
                for (int i = 0; i < cota; i++) inventario[i] = NULL;           
            }
        }; 
        typedef hash* Hash;


    private:
        Hash tabla;
    public:
        HashAbierto() : tabla(NULL) {}

        Hash crear(int cota){
            return new hash(cota);
        }

        void registro(string pal, int cota){
            registro(tabla, pal, cota);
        }

        int consulta(string pal){
            return consulta(tabla, pal);
        }

        int cantCajones(){
            return cantCajones(tabla);
        }

        int cajonMasLargo(){
            return cajonMasLargo(tabla);
        }
    

        int clave(string palabra){ //acordarse de autoria con claude y bitacora
            int key = 0;
            for (int  i = 0; i < (int)palabra.length(); i++){
                key += palabra[i] * palabra[i];
            }
            return key;
        }

        int index(Hash t, int clave){
            if(!t) return -1;
            return abs(clave % t->cota);
        };

        void registro(Hash& t, string pal, int cota){ //corregido con claude para autoria y esas mierdas
            if(!t){
                Hash nuevo = crear(cota);
                t = nuevo;
            }
            int key = clave(pal);
            int pos = index(t, key);
            cajon* c = t->inventario[pos];
            while (c){
                if (c->clavePalabra == key){ 
                    c->cant ++;
                    if (c->cant > t->max) t->max = c->cant;
                    return;
                }
                c = c->sig;
            }
            cajon* nuevo = new cajon;
            nuevo->clavePalabra = key;
            nuevo->cant = 1;
            nuevo->sig = t->inventario[pos];
            t->inventario[pos] = nuevo;
            t->cantCajones++;

            if(nuevo->cant > t->max) t->max = nuevo->cant;
        };

        int consulta(Hash t, string pal){
            if (!t) return 0;
            int key = clave(pal);
            int pos = index(t, key);
            cajon* c = t->inventario[pos];
            while(c){
                if (c->clavePalabra == key) return c->cant;
                c = c->sig;
            }    
            return 0;
        }

        int cantCajones(Hash t){
            if(!t) return 0;
            return t->cantCajones;
        }

        int cajonMasLargo(Hash t){
            if(!t)return 0;
            return t->max;
        }

};




int main(){
    HashAbierto tabla;
    int x;
    cin >> x;
    //tabla.crear(x);
    for (int i = 0; i < x; i++){
        string pal;
        cin >> pal;
        tabla.registro(pal, x);
    }
    int consulta;
    cin >> consulta;
    for(int i = 0; i < consulta; i++){
        string pal;
        cin >> pal;
        cout <<  tabla.consulta(pal) << '\n'; 
    }
    
    cout << tabla.cantCajones() << ' ' << tabla.cajonMasLargo();    //ÚLTIMA LÍNEA

}