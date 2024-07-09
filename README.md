# Técnicas-de-Representación-y-Compresión-de-Arreglos-Ordenados
## Integrantes:

- **Andrés Mardones**
- **Martín Alvarado**
- **Isaías Cabrera**
- **Osvaldo Casas-Cordero**


## Descripción
Este proyecto tiene como objetivo la implementación y análisis de técnicas de representación y compresión de arreglos ordenados, en particular se analizaran tres soluciones:

- **Arreglo Explícito**
- **Arreglo representado con gapCoding**
- **Representación con Huffman**


## Estructura de Archivos
- **makefile**: Contiene las reglas de compilación del proyecto.
- **main.cpp**: Contiene el método main del proyecto.
- **include/**: Contiene los archivos headers.
- **generacion.h**: Contiene las funciones para la generación de arreglos.
- **huffman.h**: Contiene las funciones para la codificación de Huffman.
- **solucion1.h**: Contiene las funciones para la solución 1.
- **solucion2.h**: Contiene las funciones para la solución 2.
- **solucion3.h**: Contiene las funciones para la solución 3.


## Requisitos
- **Compilador g++**
- **make**


## Instalación
Para instalar make en Ubuntu, ejecute el siguiente comando:
```bash
sudo apt install make
```


## Compilación
Para compilar el proyecto ejecutar el makefile en la terminal con el siguiente comando:
```bash
make
```

## Ejecución
Para ejecutar el proyecto, ejecute el siguiente comando:
```bash
./main <size> <e> <sd>
 ```
Esto entregará los tiempos de búsqueda de cada solución y además la memoria utilizada por las 3 soluciones.

Donde:
- **size**: Tamaño de los arreglos a generar.
- **e**: Entero que indica salto máximo entre elementos del arreglo.
- **sd**: Entero que indica la desviación estándar del arreglo con distribución normal.

#
