# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Alta: O(log K)pc y Buscar: O(log K)pc
  / Justificación: esta función recorre el AVL de la siguiente manera: según el dato que recibo, si este es mayor al dato del nodo actual del AVL, se llama a la misma función, pero solo a la información que se encuentra del lado derecho del AVL, y a la izquierda en caso contrario. Así, el peor caso va a ser llegar hasta el último nivel, por ende, tendría que dividir el árbol en 2, luego 4, después 8, y así sucesivamente. Por eso queda el logaritmo en base 2 de K, siendo K la cantidad de elementos que hay en el AVL.

- Rango: O(log K + R)pc 
/ Justificación: 
Rango contiene 2 subfunciones: RangoAux y Dimensión.
RangoAux va recorriendo el arbol, analizando cada T dato que, si cumple, lo agrega en un T array que recibe como parámetro. En caso de no cumplir va yendo para izquierda o derecha cargando el arreglo, donde se van descartando los subarboles que no cumplen, quedando O(log K + R) siendo R la cantidad de nodos dentro del rango. 
A su vez, la función dimensión también tiene O(log K + R). Es una función que su recorrido es idéntico al de RangoAux, la diferencia es que en esta función buscamos la cantidad de elementos que hay en el intervalo (desde, hasta), para luego en Rango inicializar un array de T con el largo que retorna dimensión.
Como RangoAux es O(log K + R) y dimensión también, y ambas son independientes entre sí, quedará en O(2.(log K + R)); por lo que el 2 se puede sacar para afuera del orden y, al ser tendiente al infinito, se puede obviar. El resto de código en la función Rango es de O(1), así que, de esta forma, Rango quedará con O(2.(log K + R)) ~ O(log K+R) .

## Ejercicio 2
- Registrar y Consultar: O(L)cp , siendo L el largo de la palabra involucrada.
/ Justificación: Ambas llamadas tienen un esquema similar; contienen casi todo líneas de código de orden constante, menos el llamado de index, que es la función que permite hallar la posición o el "bucket" al que corresponde la palabra. Y esta función es la que contiene el O(L), ya que tiene que recorrer el largo de la palabra en cuestión para encontrar el bucket. Después de eso, todo lo que tiene Registrar es de O(1): se crea un nuevo nodo, se le asigna sus características, y se agrega al principio de la lista de buckets correspondiente. A su vez, consultar también llama a index, y el resto del código es de orden constante; retorna 0 o la cantidad que tiene el primer nodo, hecho así para que el primer nodo tenga la cantidad de elementos desde ahí para adelante.
Así ambas funciones quedan de O(L)

- Úlitma línea de salida: O(1) pc
/ Justificación: La última línea llama a 2 funciones: una es cantCajones y otra es cajonMasLargo. Ambas tienen acceso a información general de la tabla hash, donde si la tabla es vacía se retorna 0, y sino se retorna t->cantCajones y t->max respectivamente.

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

