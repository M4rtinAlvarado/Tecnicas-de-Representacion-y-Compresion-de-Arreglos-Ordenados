#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
using namespace std;


/** Crea un arreglo de tamaño size con distribución uniforme.
 * 
 * @param size Tamaño del arreglo
 * @param e Salto maximo entre elementos consecutivos
 * @return Puntero al arreglo creado
 */
int* lineal(int size, int e){
    srand(time(NULL));
    int* array = new int[size];
    array[0] = rand() % e;
    for(int i = 1; i < size; i++){
        array[i] = array[i-1] + rand() % e;
    }
    cout << endl;

    return array;
}




/** Crea un arreglo de tamaño size con distribución normal.
 * 
 * @param size Tamaño del arreglo
 * @param sd Desviación estandar
 * @return Puntero al arreglo creado
 */
int* distNormal(int size, int sd){
    int* array = new int[size];

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(size/2, sd);

    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<int>(d(gen));
    }

    sort(array, array + size);
    return array;
}





/** Crea el arreglo de gapCoding a partir del arreglo arr.
 * 
 * @param arr Arreglo de enteros
 * @param n Tamaño del arreglo
 * @return Puntero al arreglo de gapCoding
 */
int* gapCoding(int arr[], int n) {
    int* gap = new int[n];
    gap[0] = arr[0];
    for (int i = 1; i < n; i++) {
        gap[i] = arr[i] - arr[i - 1];
    }
    return gap;
}




/** Crea un arreglo de tamaño m con elementos seleccionados de arr.
 * 
 * @param arr Arreglo de enteros
 * @param m Tamaño del arreglo a crear
 * @param b Salto entre elementos seleccionados
 * @return Puntero al arreglo creado
 */
int* createSample(int arr[], int m, int b) {
    int* sample = new int[m];
    for (int i = 0; i < m; i++) {
        sample[i] = arr[i * b]; // Seleccionando elementos basados en el intervalo
    }
    return sample;
}



/** Genera un arreglo de numeros aleatorios para probar la busqueda binaria.
 * 
 * @param cant Cantidad de numeros a generar
 * @param max Valor maximo de los numeros
 * @return Puntero al arreglo creado
 */
int* generarNumeros(int cant, int max){
    srand(time(NULL));
    int* array = new int[cant];
    array[0] = rand() % max;
    for(int i = 1; i < cant; i++){
        array[i] = rand() % max;
    }

    return array;
}

