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
- **prueba.cpp**: Contiene el código fuente del proyecto.
- **funciones.h**: Contiene las funciones auxiliares que se utilizaran en la ejecución.
- **huffman.h**: Contiene las funciones para la codificación de Huffman.


## Requisitos
- **Compilador g++**
- **Valgrind**


## Instalación
Para instalar Valgrind en Ubuntu, ejecute el siguiente comando:
```bash
sudo apt-get install valgrind
```


## Compilación
Para compilar el proyecto ejecutar el make:
```bash
make
```

## Ejecución
Para ejecutar el proyecto de la forma más básica, ejecute el siguiente comando:
```bash
./main <size> <e> <sd>
 ```
Esto entregará los tiempos de búsqueda de cada solución y además la memoria utilizada por las 3 soluciones.

Donde:
- **size**: Tamaño de los arreglos a generar.
- **e**: Entero que indica salto máximo entre elementos del arreglo.
- **sd**: Entero que indica la desviación estándar del arreglo con distribución normal.

#
