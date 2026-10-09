# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Alta: O(log K)pc y Buscar: O(log K)pc  
Justificación: esta función recorre el AVL de la siguiente manera: según el dato que recibo, si este es mayor al dato del nodo actual del AVL, se llama a la misma función, pero solo a la información que se encuentra del lado derecho del AVL, y a la izquierda en caso contrario. Así, el peor caso va a ser llegar hasta el último nivel, por ende, tendría que dividir el árbol en 2, luego 4, después 8, y así sucesivamente. Por eso queda el logaritmo en base 2 de K, siendo K la cantidad de elementos que hay en el AVL.

- Rango: O(log K + R)pc   
Justificación: 
Rango contiene 2 subfunciones: RangoAux y Dimensión.
RangoAux va recorriendo el arbol, analizando cada T dato que, si cumple, lo agrega en un T array que recibe como parámetro. En caso de no cumplir va yendo para izquierda o derecha cargando el arreglo, donde se van descartando los subarboles que no cumplen, quedando O(log K + R) siendo R la cantidad de nodos dentro del rango. 
A su vez, la función dimensión también tiene O(log K + R). Es una función que su recorrido es idéntico al de RangoAux, la diferencia es que en esta función buscamos la cantidad de elementos que hay en el intervalo (desde, hasta), para luego en Rango inicializar un array de T con el largo que retorna dimensión.
Como RangoAux es O(log K + R) y dimensión también, y ambas son independientes entre sí, quedará en O(2.(log K + R)); por lo que el 2 se puede sacar para afuera del orden y, al ser tendiente al infinito, se puede obviar. El resto de código en la función Rango es de O(1), así que, de esta forma, Rango quedará con O(2.(log K + R)) ~ O(log K+R) .

## Ejercicio 2
- Registrar y Consultar: O(L)cp , siendo L el largo de la palabra involucrada.  
Justificación: Ambas llamadas tienen un esquema similar; contienen casi todo líneas de código de orden constante, menos el llamado de index, que es la función que permite hallar la posición o el "bucket" al que corresponde la palabra. Y esta función es la que contiene el O(L), ya que tiene que recorrer el largo de la palabra en cuestión para encontrar el bucket. Después de eso, todo lo que tiene Registrar es de O(1): se crea un nuevo nodo, se le asigna sus características, y se agrega al principio de la lista de buckets correspondiente. A su vez, consultar también llama a index, y el resto del código es de orden constante; retorna 0 o la cantidad que tiene el primer nodo, hecho así para que el primer nodo tenga la cantidad de elementos desde ahí para adelante.
Así ambas funciones quedan de O(L)

- Úlitma línea de salida: O(1) pc  
Justificación: La última línea llama a 2 funciones: una es cantCajones y otra es cajonMasLargo. Ambas tienen acceso a información general de la tabla hash, donde si la tabla es vacía se retorna 0, y sino se retorna t->cantCajones y t->max respectivamente.

## Ejercicio 3
- Consolidar O(N logN pc), siendo N la cantidad de archivos.  
Justificación: Casi todo el código de Consolidar es de O(1), a excepción del "eliminar" , "agregar"; y el while que los contiene. Dichas funciones tienen O(1) y un llamado a "hundir" y "swap" respectivamente, ambas de O(log N) en su peor caso, ya que son funciones que dividen al árbol en 2, luego esa parte se divide de nuevo y así sucesivamente. El peor caso para ambas funciones es que se divida de principio a fin (o de fin a principio para swap), por eso log N.
En resumen, todo lo que está dentro del while es de O(2.log(N)) ~ O(log N). Antes de empezar el while hay N elementos y luego N-1, y se reitera el while hasta que hayan 2 elementos (largo>=3 para no trabajar con la posición 0). Así, se repite N-1 veces (es decir, tiende a N) la iteración del while, haciendo que quede O(N. log N).

- Consolidar Orden espacial O(N): Para que esta función sea de O(N) espacial, debería guardar un elemento de cada uno de los N archivos del heap. Lo cual cumple, ya que se agregan en el heap los N elementos y luego se van consolidando como corresponde, también N veces.

## Ejercicio 4
- Compilador: O((V+A)\log V) pc, siendo V la cantidad de módulos y A la cantidad de dependencias.  
Justificación: Al igual que en el ejercicio 3, las funciones "eliminar", "agregar", "hundir" y "swap" tienen complejidad O(log V) en el peor caso. Esto se mantiene porque seguimos trabajando con un heap binario; la única diferencia es que se agregaron nuevas condicionales para determinar cuándo realizar los intercambios, sin modificar la altura del heap ni su complejidad.

Nuestra función utiliza el algoritmo de Kahn, manteniendo el orden requerido mediante un heap mínimo. Primero, el "for" recorre los V vértices y agrega al heap aquellos que no tienen ascendientes. En el peor caso, se podrían agregar los V vértices, con un costo de O(V log V).

Luego, dentro del "while", se elimina un vértice del heap en cada iteración. Como cada vértice se agrega como máximo una vez y se elimina como máximo una vez, esta parte tiene un costo total de O(V log V).

Por otro lado, para cada vértice eliminado, se recorren sus vecinos. Como cada dependencia se recorre exactamente una vez, el costo total de estos recorridos es O(A). Sin embargo, cuando el número de ascendientes de un vecino llega a cero, este se agrega al heap, lo que puede ocurrir como máximo una vez por vértice y representa un costo total de O(V log V).

Por lo tanto, sumando los costos, obtenemos O(V log V + V log V + A + V log V), que se simplifica a O((V+A) log V).

- Compilador Orden espacial O(V+A): hay varias estructuras para esta función; la implementación del heap mínimo, los arrays de "orden", "acendientes"  y "prioridades" son todos de O(V), ya que todos pueden almacenar hasta V datos. Por su parte, la lista de adyacencia de "vecinos", tiene O(V+A), ya que almacena un puntero por vértice y un nodo por dependencia. Así, la sumatoria se simplifica en O(V+A).

## Ejercicio 5
- Kruskal O(E logE) pc, siendo E la cantidad de senderos.
Justificación: ...

- Kruskal Orden espacial O(V+E):


