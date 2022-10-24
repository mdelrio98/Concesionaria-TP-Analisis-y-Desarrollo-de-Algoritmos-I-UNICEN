# Concesionaria-TP-Analisis-y-Desarrollo-de-Algoritmos-I-UNICEN
 
## Trabajo Practico de Cursada

### Objetivo
  Una concesionaria de autos usados nos pide implementar un sistema de asistencia para la
  atención a clientes. Este sistema deberá llevar un registro de los autos con los cuáles
  cuenta la concesionaria, y proveer distintos servicios de búsqueda que respondan a las
  consultas realizadas por los clientes y operarios.
  Luego la concesionaria decide cambiar los servicios de consulta disponibles para los clientes para
  brindar un único servicio.
  Por este motivo, nos solicita realizar las modificaciones necesarias en la aplicación para
  resolver, eficientemente, el siguiente servicio:
    - Obtener la información de los autos de mayor y menor precio dentro de un rango de
    modelos dado.
  Por ejemplo, un cliente quiere conocer el auto de menor precio y el auto de mayor
  precio (junto con su información) que la concesionaria tiene en sus registros con
  modelo entre los años 2005 y 2010, inclusive.

### Captura de Requerimientos
  Los servicios de búsqueda que se deben proveer son:
  
  1) Verificar si existe una patente dada dentro de la colección de autos de la
  concesionaria.
  2) Listar todos los autos de un modelo solicitado por el cliente, presentando de cada
  uno su información general y características.
  3) Obtener toda la información del auto de mayor precio, entre los existentes
  
  La información de los autos deberá ser obtenida de un archivo de texto al momento de
  iniciar la aplicación. Una vez cargada esta información la misma no cambiará hasta que la
  aplicación no se ejecute nuevamente.
  La aplicación se inicializará al comienzo del día y se detendrá al finalizar la jornada; por lo
  tanto, seguramente se deban resolver un número considerable de veces cada uno de los
  servicios establecidos como necesarios.
  Se sabe que la concesionaria cuenta con una colección grande de autos totales, mucho
  más grande que la cantidad de autos por modelo. Además, se dispone de autos en cada
  uno de los años desde el 2000 al 2020 inclusive.
  
### Diseño de la solución

Para resolver eficientemente el servicio es necesario construir una estructura de búsqueda
conocida como **Segment-Tree**.
Las estructuras de búsqueda generalmente se construyen sobre estructuras generales de
almacenamiento. De esta forma, la información se encuentra almacenada una única vez en
la estructura general y las aplicaciones pueden construir las estructuras de búsqueda que
consideren apropiadas para acceder a los datos.
Acceder a los datos que se están buscando a través de estas estructuras de búsqueda
resulta en resoluciones mucho más eficientes, en comparación con resolver el problema
directamente utilizando la estructura general.
Segment-Tree es una estructura de búsqueda muy aplicada en un contexto particular, como
se verá a continuación.

### Fundamentación teórica

Un Segment-Tree es una estructura de datos que permite realizar búsquedas de rangos de
valores en un arreglo de forma eficiente. Esta estructura se puede representar mediante un
árbol binario de búsqueda donde cada nodo guarda resultados parciales (por algún criterio)
sobre elementos de un arreglo.
De esta forma, el arreglo sería la estructura general de almacenamiento mientras que el
Segment-Tree sólo nos brinda un acceso eficiente a esos datos.
Por ejemplo, si consideramos el siguiente arreglo [2, 5, 1, 4, 9, 3] y queremos responder,
eficientemente, ¿cuáles es el menor valor entre dos índices cualesquiera del arreglo?,
podemos construir el siguiente Segment-Tree para buscar esa respuesta:

[![img1.png](https://i.postimg.cc/VL00x7gF/img1.png)](https://postimg.cc/TpGPmJZy)

De la misma forma podríamos construir un Segment-Tree para conocer la suma de los
valores de un arreglo entre cualquier par de índices:

[![img2.png](https://i.postimg.cc/fWm3z81W/img2.png)](https://postimg.cc/w3xxFQ6n)

### Construcción del Segment-Tree

El Segment-Tree se construye a partir de un arreglo ordenado mediante el criterio por el
cuál se quiere hacer la búsqueda de rango. En este caso, se debe construir un arreglo
donde en cada celda se almacena la información de los autos de un modelo en particular.
Debido a que el número de autos por año no se conoce al momento de comenzar la carga a
memoria, se propone utilizar una lista vinculada (o cualquier otro contenedor dinámico) para
almacenar todos los autos de cada modelo encontrado.Una vez cargados todos los autos a memoria en el arreglo, se puede plantear el siguiente
pseudo-código para construir el Segment-Tree por rango de modelos:

~~~
construir_segment_tree (estructura_general E, segment_tree S,indice izq, indice der)
{
  si izq < der
    medio = (der + izq ) / 2
    segment_tree I = construir_segment_tree (E, S, izq, medio)
    segment_tree D = construir_segment_tree (E, S, medio + 1, der)
    S.izquierda = I
    S.derecha = D
    S.valor = procesar_valores(I,D)
    retornar S
  sino
    nuevo segment_tree N
    N.valor = obtener_valor(E, izq, der)
    retornar N
}
~~~

En el siguiente esquema se puede visualizar el vínculo resultante entre la estructura general
de almacenamiento y la estructura de búsqueda por rangos, para un caso acotado:

[![img3.png](https://i.postimg.cc/xdXCW5K2/img3.png)](https://postimg.cc/Z9h4Nr77)

**Aclaración:** por simplicidad no se muestran en el dibujo, pero todos los nodos deberían
registrar los resultados de los rangos correspondientes.Utilización del Segment-Tree
La resolución del servicio deberá utilizar el Segment-Tree como punto de acceso a la
información. El cliente brindará un rango de modelos y la aplicación, utilizando esta
estructura de búsqueda, deberá retornar la información de los autos que coincidan con el
criterio de búsqueda ingresado.
  
