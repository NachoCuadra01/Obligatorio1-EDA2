# Bitácora — Obligatorio 1

**Integrantes:** Ignacio Cuadra (355314), Lucas Scafarelli (364717)

## 2026-09-04 — En conjunto
- Implementamos primeros avances, creando la clase AVLbalanceado, hicimos los métodos de rotaciones e iniciamos con la implementación de alta.

## 2026-09-11 — En conjunto
- Terminamos la implementación de alta y buscar. Iniciamos con rango.

## 2026-09-12 — En conjunto
- Empezamos con la implementación del main para poder leer los datos. Al momento de probar los métodos creados nos encontramos varios bugs.
Nos encontramos que teníamos que crear una raíz general la cual cargar y no crear una nueva en cada método. Luego en rango tuvimos problemas con el tema de órdenes, la cual resolvimos preguntándole a la inteligencia artificial qué convenía hacer para mantener el orden pedido.

## 2026-09-14 — En conjunto
- Se compiló y quedó aprobado el ejercicio 1 y comenzamos con la justificación de los órdenes de las funciones de Alta, Buscar y Rango.
Se leyó la proposición del ejercicio 2, también se pensó las formas necesarias para resolver, ej: el constructor del hash tendría un int que contiene el valor del cajón más largo.

## 2026-09-18 — En conjunto
- Se empezó a trabajar con el ejercicio 2, donde creamos el hash abierto y construimos las funciones pedidas. Tuvimos discusiones de cómo hacer index, ya que pensamos el caso que una combinación de letras de un largo puede tener la suma en tabla ASCII que otra combinación de letras de distinto largo. Se le consultó a la IA, específicamente a Claude, qué convenía hacer para hallar un índice único, nos devolvió que lo ideal sería hacer la sumatoria de cada letra en la tabla ASCII al cuadrado, para minimizar la probabilidad de que 2 diferentes palabras de distinto largo coincidan. Luego de haber resuelto eso, continuamos resolviendo las funciones bajo las restricciones mencionadas.
Finalmente, se compiló y quedó aprobado el ejercicio 2 y realizamos la justificación de los órdenes de las funciones de registro, consulta y la última línea.

## 2026-09-20 — En conjunto
- Se empezó con el ejercicio 3, planteando ideas y maneras de realizar el heapMin.

## 2026-09-21 — En conjunto
- Se empezó a realizar el código del ejercicio 3, nos fuimos encontrando con varios problemas, los cuales fuimos solucionando algunos con Claude y otros nos fuimos dando cuenta, uno de esos problemas fue que precisábamos un hundir y un swap, el cual uno va de arriba hacia abajo y otro de abajo hacia arriba.

## 2026-09-28 — En conjunto
- Se continuó con el ejercicio 3 hasta finalizarlo, se logró finalizar pasando las pruebas y funcionando todo correcto. Se solucionó un bug con Claude que la prueba número dos nos daba 42 en vez de 44. También nos dimos cuenta que no podíamos usar int ya que el resultado puede sobrepasar 32 bits entonces necesitábamos usar otro tipo, así que usamos long long.
Además, se planteó la justificación de órdenes en este ejercicio.

## 2026-10-02 — En conjunto
- Arrancamos leyendo el ejercicio 4, y planteando los structs correspondientes. Importamos las funciones correspondientes del ejercicio 3 sobre el heap. Pensamos en hacer una matriz para los vecinos, lo discutimos con el profe y nos dijo que era buena idea, así que intentó de implementar.
Sin embargo, nos complicaba con el tema del recorrido y los órdenes, por lo que se resolvió con hacer un array de listas, donde cada posición representa a una lista de los vecinos de esa posición (ej: vecinos [1] = 2, 3, 4).

## 2026-10-09 — En conjunto
- Seguimos con el ejercicio 4, hasta finalizarlo. En vez de continuar con el ejercicio 5, arrancamos con la justificación de órdenes de la parte 4.

## 2026-10-16 — En conjunto
- Con parte del algoritmo de MFset y de heap que hicimos en clase, lo tomamos para nuestro obligatorio y modificamos el de heap para usarlo en base 1. Luego de esto implementamos la función costoMin. Después de terminado la prueba 1 nos estaba dando 23 en vez de 16, por lo tanto le preguntamos a Claude qué error teníamos que nos estaba haciendo sumar de más. Lo que resultó que teníamos era que estábamos recorriendo el array de senderos (aristas) de parque nacional desde la posición 1 hasta la V, en lugar de la posición 0 hasta la V-1, para luego ser insertados en el heap, ahora sí, en base 1.
Después de resolver este problema todas las pruebas dieron bien.