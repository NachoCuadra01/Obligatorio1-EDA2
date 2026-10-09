    #include <cassert>
    #include <string>
    #include <iostream>
    #include <limits>


    using namespace std;

    struct Nodo {
            int dato;
            Nodo* siguiente;
            Nodo(int d) : dato(d), siguiente(NULL) {}
        };


    class OrdenCompilacion{
        public:

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
                        if(h.array[(pos)/2].numero > a.numero){
                            h.array[pos] = h.array[(pos)/2];
                            h.array[(pos)/2] = a;
                        }
                    }
                    pos = pos/2;
                    a = h.array[pos];
                } 
            }

            void hundir(heapMin& h, int pos){
                if(!h.array || pos * 2 > h.cantVertices) return;
                modulo a = h.array[pos];
                int posH1 = pos*2; 
                int posH2=  pos*2 + 1;
                int posMin = posH1;
                if(posH2 <= h.cantVertices){
                    if(h.array[posH2].prioridad < h.array[posH1].prioridad) posMin = posH2;
                    else if(h.array[posH2].prioridad == h.array[posH1].prioridad){
                        if(h.array[posH2].numero < h.array[posH1].numero) posMin = posH2;
                    }   
                }

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
                if (!h.array) return -1;
                int num = h.array[1].numero;
                h.array[1] = h.array[h.cantVertices];
                h.cantVertices--;
                hundir(h, 1);   
                return num;
            }


            void agregar(heapMin& h, int prioridad, int numero){
                h.cantVertices++;
                h.array[h.cantVertices].numero = numero;
                h.array[h.cantVertices].prioridad = prioridad;
                swap(h, h.cantVertices);
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
                    while (vec){
                        ascendientes[vec->dato]--;
                        if(ascendientes[vec->dato] == 0) agregar (modulos, prioridades[vec->dato], vec->dato); 
                        vec = vec->siguiente;
                    }
                    
                    
                }

                if(cant != largo-1) cout << "imposible" << endl;
                else for(int i = 0; i < largo-1; i++) cout << orden[i] << '\n';
            }


    };

    int main(){
        OrdenCompilacion g;
        int modulos, dependencia;
        cin >> modulos >> dependencia;
        int* prioridad = new int[modulos+1];
        for(int i = 1; i <= modulos; i++){
            int x;
            cin >> x;
            prioridad[i] = x;
        }


        int* ascendentes = new int[modulos+1]();
        Nodo** vecinos = new Nodo*[modulos+1]();

        for(int i = 1; i <= dependencia; i++){
            int u, v;
            cin >> u >> v;
            Nodo* nuevo = new Nodo(v);
            nuevo->siguiente = vecinos[u];
            vecinos[u] = nuevo;
            ascendentes[v]++;
        }

        g.compilador(modulos+1, ascendentes, prioridad, vecinos);
        
        return 0;
    }