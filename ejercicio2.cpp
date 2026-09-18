#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;


class HashAbierto{
    public:
        struct cajon{
            cajon* sig;
            string palabra;
            int cant;
        };

        struct hash{
            cajon** inventario;
            int indMax;
            int max;
            int cantCajones;
            int cota;
            hash(int cota) : cota(cota), indMax(-1),max(0), cantCajones(0), inventario(NULL) {} 
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
    

        int clave(string palabra){ //acordarse de autoria con claude y bitacora
            int clave = 0;
            for (int  i = 0; i < palabra.length(); i++){
                clave += pow(palabra[i], 2);
            }
            return clave;
        }

        int index(Hash t, int clave){
            if(!t) return -1;
            return abs(clave % t->cota);
        };

        void registro(Hash t, string pal, int cota){
            if(!t){
                Hash nuevo = crear(cota);
                t = nuevo;
            }
            int pos = index(t, clave(pal));
            cajon* c = new cajon;
            c->palabra = pal;
            if(t->inventario[pos])c->cant = 1 + t->inventario[pos]->cant;
            else c->cant = 1;
            c->sig = t->inventario[pos];
            t->inventario[pos] = c;
            t->cantCajones++;
            if(t->inventario[pos]->cant > t->max){
                t->max = t->inventario[pos]->cant;
                t->indMax = pos;
            }
        };

        int consulta(Hash t, string pal){
            if (!t) return 0;
            int pos = index(t, clave(pal));
            if (pos == -1) return 0;
            return t->inventario[pos]->cant;
            
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
        tabla.consulta(pal);
    }
    return 0;
}