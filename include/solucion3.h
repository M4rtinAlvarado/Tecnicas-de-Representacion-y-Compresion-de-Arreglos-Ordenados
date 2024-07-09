#include <iostream>
#include <unordered_map>
#include "huffman.h"
#include <time.h>
using namespace std;


/** Crea un HashMap con la frecuencia de los elementos del arreglo gapCoding.
 * 
 * @param gap Arreglo de gapCoding
 * @param n Tamaño del arreglo
 * @return Puntero al HashMap creado
 */
unordered_map<int, int> * countFreq(int *gap, int n){
    unordered_map<int, int> *hashMap = new unordered_map<int, int>;//(data, frecuencia)
    hashMap->insert({gap[0], 1});
    for (int i = 1; i < n; i++){
        if (hashMap->find(gap[i]) == hashMap->end()){
            hashMap->insert({gap[i], 1});
        }
        else{
            hashMap->at(gap[i])++;
        }
    }
    return hashMap;
}



/** Busca x en un intervalo del arreglo gap.
 * 
 * @param gapCode Arreglo de gapCoding indicea codificado
 * @param size Tamaño del arreglo gapCode
 * @param x Elemento a buscar
 * @param indice Indice del inicio del intervalo en el cual se encuentra x
 * @param b Saltos del arreglo Sample
 * @param actual valor del elemento en el indice
 * @param m Tamaño del arreglo Sample
 * @param hashmapDecode HashMap con los valores de los elementos codificados indice su frecuencia
 * @return Posición del elemento encontrado, -1 si no se encuentra
 */
int busquedaLinealGapHuffman(unsigned short int* gapCode, int size, int x, int indice, int b, int actual, int m, unordered_map<unsigned short int, int> hashmapDecode) {
    int i = b*indice; int lim;
    if(indice == m-1) {
        lim = size;
    }else {
        lim = b*(indice+1);
    }
    while (i < lim && actual< x) {
        i++;
        actual += hashmapDecode[gapCode[i]];
    }
    if (actual == x) {
        return i;
    } else {
        return -1;
    }
}


bool busquedaSol3(int *sample, unsigned short int *gapCode, int size, int m, int b, int x, unordered_map<unsigned short int, int> hashmapDecode){
    int* result = binarySearchSample(sample, m, x);
    int i = busquedaLinealGapHuffman(gapCode, size, x, result[0], b, result[1], m, hashmapDecode);
    if (i == x){
        return true;
    }
    return false;
}

void SOLUCION3(unsigned int t0, unsigned int t1, double time, int memoria, int cant, int size, int m, int b, int* sampleLineal, int* gapLineal, int* randomNumbersLineal, int* sampleNormal, int* gapNormal, int* randomNumbersNormal){

     // SOLUCION 3
    cout << "====================== Solucion 3 ======================" <<endl<<endl;

    //Inicalizacion solucion 3
    unordered_map<int, int> *hashmapFrecLineal = countFreq(gapLineal, size);
    unordered_map<int, unsigned short int> hashmapEncodeLineal;
    unordered_map<unsigned short int, int> hashmapDecodeLineal;
    int aux1 = HuffmanCodes(*hashmapFrecLineal, hashmapEncodeLineal, hashmapDecodeLineal);
    unsigned short int* gapCodeLineal = new unsigned short int[size];
    for (int i = 0; i<size; i++){ gapLineal[i]= hashmapEncodeLineal[gapLineal[i]]; }


    unordered_map<int, int> *hashmapFrecNormal = countFreq(gapNormal, size);
    unordered_map<int, unsigned short int> hashmapEncodeNormal;
    unordered_map<unsigned short int, int> hashmapDecodeNormal;
    int aux2 = HuffmanCodes(*hashmapFrecNormal, hashmapEncodeNormal, hashmapDecodeNormal);
    unsigned short int* gapCodeNormal = new unsigned short int[size];
    for (int i = 0; i<size; i++){ gapCodeNormal[i] = hashmapEncodeNormal[gapNormal[i]]; }


    //Busqueda en solucion 3 arreglo lineal 

    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol3(sampleLineal, gapCodeLineal, size, m, b, randomNumbersLineal[i],hashmapDecodeLineal);
    }
    t1 = clock();

    memoria=0;
    for(int i = 0; i < size; i++){
        memoria += sizeof(gapCodeLineal[i]);
    }
    for(int i = 0; i < m; i++){
        memoria += sizeof(sampleLineal[i]);
    }
    for (auto x:hashmapDecodeLineal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }
    for (auto x: *hashmapFrecLineal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }
    for (auto x: hashmapEncodeLineal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    memoria += sizeof(sampleLineal) + sizeof(gapCodeLineal) + sizeof(size) + sizeof(m) + sizeof(b) + sizeof(hashmapDecodeLineal) + sizeof(*hashmapFrecLineal) + sizeof(hashmapEncodeLineal) + aux1;
    cout << "Tiempo Ejecución Arreglo Lineal: " << time << endl << "Memoria Usada para la busqueda: "<< memoria << endl;

    
    //Busqueda en solucion 3 arreglo Distribucion Normal
    t0 = clock();
    for(int i = 0; i < cant; i++){
        busquedaSol3(sampleNormal, gapCodeNormal, size, m, b, randomNumbersNormal[i], hashmapDecodeNormal);
    }
    t1 = clock();

    memoria=0;
    for(int i = 0; i < size; i++){
        memoria += sizeof(gapCodeNormal[i]);
    }
    for(int i = 0; i < m; i++){
        memoria += sizeof(sampleNormal[i]);
    }
    for (auto x:hashmapDecodeNormal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }
    for (auto x:*hashmapFrecNormal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }
    for (auto x: hashmapEncodeNormal){
        memoria += sizeof(x.first) + sizeof(x.second);
    }

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    memoria += sizeof(sampleNormal) + sizeof(gapCodeNormal) + sizeof(size) + sizeof(m) + sizeof(b) + sizeof(hashmapDecodeNormal) + sizeof(*hashmapFrecNormal) + sizeof(hashmapEncodeNormal) + aux2;
    cout << "Tiempo Ejecución Arreglo Distribucion Normal: " << time << endl << "Memoria Usada para la busqueda: "<< memoria << endl;

}
