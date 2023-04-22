# Quiz-SO
Quiz de Sistemas Operativos valor 10%


### Integrantes: 

* Jurguen Monge Rojas
* Elmer Mejia Carranza
* Wilfredo Barquero Herrera


### Politica de Memoria: Mapa de bits

En un sistema de gestión de memoria que utiliza mapas de bits para llevar un seguimiento del estado de la memoria (por ejemplo,
si está disponible o asignada), generalmente es responsabilidad del proceso conocer en qué bloques de memoria está almacenado. 
El bloque de memoria en sí mismo por lo general no "sabe" a qué proceso está ligado.

En un sistema con mapa de bits, se utiliza un mapa que mantiene un registro del estado de cada bloque de memoria, indicando 
si está disponible o asignado a un proceso específico. Por lo tanto, es el proceso el que debe solicitar la asignación de bloques
de memoria y mantener un registro de qué bloques le han sido asignados. Cuando un proceso necesita acceder o liberar una porción 
de memoria, debe hacerlo a través de las funciones o interfaces proporcionadas por el sistema operativo o la biblioteca de gestión 
de memoria del lenguaje de programación que esté utilizando.

![image](https://user-images.githubusercontent.com/68663454/233809016-2fc95142-a384-41f8-94dc-0b362cf93c74.png)

El proceso puede mantener un registro de los bloques de memoria que ha asignado utilizando estructuras de datos propias, como 
listas enlazadas, matrices u otras estructuras de datos, para rastrear la ubicación y estado de su memoria asignada. Es 
responsabilidad del proceso gestionar la asignación y liberación de memoria de manera adecuada para evitar errores de 
acceso a memoria no asignada o fugas de memoria.

![image](https://user-images.githubusercontent.com/68663454/233810559-5a150d2f-899e-484f-9293-41039ff2f62b.png)


En resumen, en un sistema de gestión de memoria basado en mapas de bits, el proceso generalmente debe llevar un registro de qué
bloques de memoria le han sido asignados y qué bloques están disponibles o asignados a otros procesos. El bloque de memoria en
sí mismo por lo general no tiene conocimiento de a qué proceso está ligado.

#### Gestión de memoria con mapeo de bits

El tamaño de la unidad de asignación es una cuestión de diseño importante

Cuanto más pequeña sea la unidad, mayor será el mapa de bits.

Si se escoge una unidad de asignación grande, el mapa de bits será
pequeño, pero podría desperdiciarse una unidad de memoria
apreciable en la última unidad de asignación del proceso si el
tamaño del proceso no es un múltiplo exacto de la unidad de
asignación

![image](https://user-images.githubusercontent.com/68663454/233810550-81c1c0a5-89e3-462f-a834-2b0fe313ae38.png)



