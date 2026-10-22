# Justificación de órdenes — Obligatorio 1

## Ejercicio 1

- **Alta:** O(log K) pc y **Buscar:** O(log K) pc

  **Justificación:** esta función recorre el AVL de la siguiente manera: según el dato que recibo, si este es mayor al dato del nodo actual del AVL, se llama a la misma función, pero solo a la información que se encuentra del lado derecho del AVL, y a la izquierda en caso contrario. Así, el peor caso va a ser llegar hasta el último nivel, por ende, tendría que dividir el árbol en 2, luego 4, después 8, y así sucesivamente. Por eso queda el logaritmo en base 2 de K, siendo K la cantidad de elementos que hay en el AVL.

- **Rango:** O(log K + R) pc

  **Justificación:**

  Rango contiene 2 subfunciones: RangoAux y Dimensión.

  RangoAux va recorriendo el árbol, analizando cada T dato que, si cumple, lo agrega en un T array que recibe como parámetro. En caso de no cumplir va yendo para izquierda o derecha cargando el arreglo, donde se van descartando los subárboles que no cumplen, quedando O(log K + R) siendo R la cantidad de nodos dentro del rango.

  A su vez, la función dimensión también tiene O(log K + R). Es una función que su recorrido es idéntico al de RangoAux, la diferencia es que en esta función buscamos la cantidad de elementos que hay en el intervalo (desde, hasta), para luego en Rango inicializar un array de T con el largo que retorna dimensión.

  Como RangoAux es O(log K + R) y dimensión también, y ambas son independientes entre sí, quedará en O(2.(log K + R)); por lo que el 2 se puede sacar para afuera del orden y, al ser tendiente al infinito, se puede obviar. El resto de código en la función Rango es de O(1), así que, de esta forma, Rango quedará con O(2.(log K + R)) ~ O(log K+R).

## Ejercicio 2

- **Registrar y Consultar:** O(L) cp, siendo L el largo de la palabra involucrada.

  **Justificación:** Ambas llamadas tienen un esquema similar; contienen casi todo líneas de código de orden constante, menos el llamado a clave, que es la función que permite generar una clave numérica a partir de la palabra. Esta función es la que contiene el O(L), ya que tiene que recorrer el largo de la palabra en cuestión para calcular su clave. Después de eso, se llama a index, que permite hallar la posición o el "bucket" correspondiente mediante una operación de O(1).

  Después de eso, Registrar recorre la lista del bucket correspondiente para verificar si ya existe un nodo con esa clave. Si existe, incrementa su cantidad; de lo contrario, crea un nuevo nodo, le asigna sus características y lo agrega al principio de la lista, siendo estas últimas operaciones de O(1). A su vez, Consultar también llama a clave e index, y luego recorre la lista del bucket hasta encontrar la clave correspondiente o llegar al final, retornando su cantidad o 0.

  Así, ambas funciones quedan de O(L + K) en el peor caso, siendo L el largo de la palabra y K la cantidad de nodos en el bucket correspondiente. Si se supone que las listas de los buckets tienen un largo acotado, ambas funciones quedan de O(L).

- **Última línea de salida:** O(1) pc

  **Justificación:** La última línea llama a 2 funciones: una es cantCajones y otra es cajonMasLargo. Ambas tienen acceso a información general de la tabla hash, donde si la tabla es vacía se retorna 0, y si no se retorna t->cantCajones y t->max respectivamente.

## Ejercicio 3

- **Consolidar:** O(N log N) pc, siendo N la cantidad de archivos.

  **Justificación:** Casi todo el código de Consolidar es de O(1), a excepción del "eliminar", "agregar"; y el while que los contiene. Dichas funciones tienen O(1) y un llamado a "hundir" y "swap" respectivamente, ambas de O(log N) en su peor caso, ya que son funciones que dividen al árbol en 2, luego esa parte se divide de nuevo y así sucesivamente. El peor caso para ambas funciones es que se divida de principio a fin (o de fin a principio para swap), por eso log N.

  En resumen, todo lo que está dentro del while es de O(2.log(N)) ~ O(log N). Antes de empezar el while hay N elementos y luego N-1, y se reitera el while hasta que hayan 2 elementos (largo>=3 para no trabajar con la posición 0). Así, se repite N-1 veces (es decir, tiende a N) la iteración del while, haciendo que quede O(N. log N).

- **Consolidar — Orden espacial:** O(N)

  Para que esta función sea de O(N) espacial, debería guardar un elemento de cada uno de los N archivos del heap. Lo cual cumple, ya que se agregan en el heap los N elementos y luego se van consolidando como corresponde, también N veces.

## Ejercicio 4

- **Compilador:** O((V+A) log V) pc, siendo V la cantidad de módulos y A la cantidad de dependencias.

  **Justificación:** Al igual que en el ejercicio 3, las funciones "eliminar", "agregar", "hundir" y "swap" tienen complejidad O(log V) en el peor caso. Esto se mantiene porque seguimos trabajando con un heap binario; la única diferencia es que se agregaron nuevas condicionales para determinar cuándo realizar los intercambios, sin modificar la altura del heap ni su complejidad.

  Nuestra función utiliza el algoritmo de Kahn, manteniendo el orden requerido mediante un heap mínimo. Primero, el "for" recorre los V vértices y agrega al heap aquellos que no tienen ascendientes. En el peor caso, se podrían agregar los V vértices, con un costo de O(V log V).

  Luego, dentro del "while", se elimina un vértice del heap en cada iteración. Como cada vértice se agrega como máximo una vez y se elimina como máximo una vez, esta parte tiene un costo total de O(V log V).

  Por otro lado, para cada vértice eliminado, se recorren sus vecinos. Como cada dependencia se recorre exactamente una vez, el costo total de estos recorridos es O(A). Sin embargo, cuando el número de ascendientes de un vecino llega a cero, este se agrega al heap, lo que puede ocurrir como máximo una vez por vértice y representa un costo total de O(V log V).

  Por lo tanto, sumando los costos, obtenemos O(V log V + V log V + A + V log V), que se simplifica a O((V+A) log V).

- **Compilador — Orden espacial:** O(V+A)

  Hay varias estructuras para esta función; la implementación del heap mínimo, los arrays de "orden", "ascendientes" y "prioridades" son todos de O(V), ya que todos pueden almacenar hasta V datos. Por su parte, la lista de adyacencia de "vecinos", tiene O(V+A), ya que almacena un puntero por vértice y un nodo por dependencia. Así, la sumatoria se simplifica en O(V+A).

## Ejercicio 5

- **costoMin:** O(E log E) pc, siendo E la cantidad de senderos.

  **Justificación:** se utilizó el algoritmo de Kruskal, el cual toma un minheap del largo de la cantidad de aristas y empieza a agregarlas según su peso, por lo que al terminar queda el mínimo peso en la raíz del heap. Esta parte ya tiene O(E log E) en peor caso.

  Ahora el algoritmo va eliminando la arista con menor peso (O(log E)) y revisa si el vértice de origen y el de destino pertenecen al mismo conjunto; si pertenecen, pasa a la siguiente arista; si no, agrega a esa arista como parte del costo final y los une en el mismo conjunto (función de orden constante). Además, suma uno en un contador de aristas que corta cuando se llega a V-1.

  En el peor caso, se evalúa con todas las aristas antes de llegar al contador = V-1, por lo que se repite E veces. Ahí tenemos nuestro segundo O(E log E).

  Finalmente, la destrucción del heap y del MFSET tienen O(1), por lo que al final, el orden en el peor caso queda 2.O(E log E) ~ O(E log E).

- **costoMin — Orden espacial:** O(V+E)

  En este ejercicio simplemente hay 2 estructuras: MFSET y heap; donde el primero lo creamos de largo V (cantidad de vértices) y al segundo de largo E (representando las aristas). De esta manera, se almacenan en una estructura todos los vértices y en la otra todas las aristas, quedando el orden espacial O(V+E).