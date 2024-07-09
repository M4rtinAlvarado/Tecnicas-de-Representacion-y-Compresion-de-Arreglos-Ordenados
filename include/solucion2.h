#include <iostream>
#include <time.h>
using namespace std;


/** Busca el elemento x en el arreglo samp, si no lo encuentra devuelve el inicio del intervalo en el que debería estar.
 * 
 * @param samp arreglo Sample
 * @param size Tamaño del Sample
 * @param x Elemento a buscar
 * @return Puntero al arreglo con la posición y el valor del elemento encontrado
 */
int* binarySearchSample(int samp[], int size, int x) {
    int l = 0, r = size - 1;
    int result = -1;
    int* res = new int[2];
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (samp[mid] == x) {
            result = mid;
            break;
        } else
        if (samp[mid] < x) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    res[0] = result;
    res[1] = samp[result];
    return res;
}



/** Busca x en un intervalo del arreglo gap.
 * 
 * @param gap Arreglo de gapCoding
 * @param size Tamaño del arreglo gapCoding
 * @param x Elemento a buscar
 * @param indice Indice del inicio del intervalo en el cual se encuentra x
 * @param b Saltos del arreglo Sample
 * @param actual valor del elemento en el indice
 * @param m Tamaño del arreglo Sample
 * @return Posición del elemento encontrado, -1 si no se encuentra
 */
int busquedaLinealGap(int* gap, int size, int x, int indice, int b, int actual, int m) {
    int i = b*indice; int lim;
    if(indice == m-1) {
        lim = size;
    }else {
        lim = b*(indice+1);
    }
    while (i < lim && actual< x) {
        i++;
        actual += gap[i];
    }
    if (actual == x) {
        return i;
    } else {
        return -1;
    }
}

bool busquedaSol2(int *sample, int *gap, int size, int m, int b, int x){
    int* result = binarySearchSample(sample, m, x);
    int i = busquedaLinealGap(gap, size, x, result[0], b, result[1], m);
    if (i == x){
        return true;
    }
    return false;
}

void SOLUCION2(unsigned int t0, unsigned int t1, double time, int memoria, int cant, int size, int m, int b, int* sampleLineal, int* gapLineal, int* randomNumbersLineal, int* sampleNormal, int* gapNormal, int* randomNumbersNormal){

    // SOLUCION 2
    cout << "====================== Solucion 2 ======================" << endl << endl;

    //Busqueda en solucion 2 arreglo Lineal
    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol2(sampleLineal, gapLineal, size, m, b, randomNumbersLineal[i]);
    }
    t1 = clock();

    memoria = 0;
    for(int i = 0; i < size; i++){
        memoria += sizeof(gapLineal[i]);
    }
    for(int i = 0; i < m; i++){
        memoria += sizeof(sampleLineal[i]);
    }
 
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    memoria += sizeof(gapLineal) + sizeof(sampleLineal) + sizeof(m) + sizeof(b);
    cout << "Tiempo Ejecución Arreglo Lineal: " << time << endl << "Memoria Usada para la busqueda: "<< memoria << endl;
    
    //Busqueda en solucion 2 arreglo Distribucion Normal
    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol2(sampleNormal, gapNormal, size, m, b, randomNumbersNormal[i]);
    }
    t1 = clock();

    memoria=0;
    for(int i = 0; i < size; i++){
        memoria += sizeof(gapNormal[i]);
    }
    for(int i = 0; i < m; i++){
        memoria += sizeof(sampleNormal[i]);
    }

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    memoria += sizeof(gapLineal) + sizeof(sampleLineal) + sizeof(m) + sizeof(b);
    cout << "Tiempo Ejecución Arreglo Distribucion Normal: " << time << endl << "Memoria Usada para la busqueda: "<< memoria << endl;

}
