#include <iostream>
#include <time.h>
using namespace std;


/** Busqueda binaria en un arreglo de enteros.
 * 
 * @param arr Arreglo de enteros
 * @param l Indice izquierdo
 * @param r Indice derecho
 * @param x Elemento a buscar
 * @return true si el elemento se encuentra en el arreglo, false en caso contrario
 */
int binarySearchBool(int* arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearchBool(arr, l, mid - 1, x);
        }

        return binarySearchBool(arr, mid + 1, r, x);
    }

    return -1;
}


bool busquedaSol1(int * arr, int size, int x){
    int i = binarySearchBool(arr, 0, size, x);
    if (i == x){
        return true;
    }
    return false;
}

void SOLUCION1(unsigned int t0, unsigned int t1, double time, int memoria, int cant, int size, int* arrayLineal, int* randomNumbersLineal, int* arrayDistNormal, int* randomNumbersNormal){

    // SOLUCION 1
    cout << "====================== Solucion 1 ======================" <<endl<<endl;

    //Busqueda en solucion 1 arreglo lineal 
    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol1(arrayLineal, size, randomNumbersLineal[i]);
    }
    t1 = clock();
    for(int i = 0; i < size; i++){
        memoria += sizeof(arrayLineal[i]);
    }
 
    time = (double(t1-t0) / CLOCKS_PER_SEC);
    memoria += sizeof(arrayLineal) + sizeof(size);
    cout << "Tiempo Ejecución Arreglo Lineal: " << time << endl <<"Memoria Usada para la busqueda: " << memoria <<endl;

  //Busqueda en solucion 1 arreglo Distribucion Normal
    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol1(arrayDistNormal, size, randomNumbersNormal[i]);
    }
    t1 = clock();
    
    memoria = 0;
    for(int i = 0; i < size; i++){
        memoria += sizeof(arrayDistNormal[i]);
    }

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    memoria += sizeof(arrayDistNormal) + sizeof(size);
    cout << "Tiempo Ejecución Arreglo Distribución Normal: " << time << endl <<"Memoria Usada para la busqueda: " << memoria <<endl;
}
