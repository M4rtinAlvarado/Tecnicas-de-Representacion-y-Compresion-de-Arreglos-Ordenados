#include <iostream>
#include "include/generacion.h"
#include "include/solucion1.h"
#include "include/solucion2.h"
#include "include/solucion3.h"
using namespace std;


int main(int argc, char *argv[]){

    // Verifica que se pasen exactamente dos argumentos
    if (argc != 4) {
        cout << "Ejecute el programa como ./prog <size> <e> <sd>" << endl;
        return EXIT_FAILURE;
    }

    //inicializacion general
    const int size = atoi(argv[1]);
    unsigned t0 = 0;
    unsigned t1 = 0;
    double time = 0;
    long int memoria = 0;
    int e = atoi(argv[2]);
    int sd = atoi(argv[3]);
    int* arrayLineal = lineal(size, e);
    int* arrayDistNormal = distNormal(size, sd);
    

    //Crear los numeros aleatorios que se buscaran en las distintas soluciones
    int cant = 10000;
    int* randomNumbersLineal = generarNumeros(cant, arrayLineal[size-1]);
    int* randomNumbersNormal = generarNumeros(cant, arrayDistNormal[size-1]);
    

    SOLUCION1(t0, t1, time, memoria, cant, size, arrayLineal, randomNumbersLineal, arrayDistNormal, randomNumbersNormal);

    
    //Inicalizacion solucion 2
    
    int m = (int) (size / 4);
    int b = size / m; // Calculando el intervalo
    int* gapLineal = gapCoding(arrayLineal, size);
    int* gapNormal = gapCoding(arrayDistNormal, size);

    int* sampleLineal = createSample(arrayLineal, m, b);
    int* sampleNormal = createSample(arrayDistNormal, m, b);

    //Eliminando datos que ya se ocuparon

    delete[] arrayLineal;
    delete[] arrayDistNormal;

    
    SOLUCION2(t0, t1, time, memoria, cant, size, m, b, sampleLineal, gapLineal, randomNumbersLineal, sampleNormal, gapNormal, randomNumbersNormal);


    SOLUCION3(t0, t1, time, memoria, cant, size, m, b, sampleLineal, gapLineal, randomNumbersLineal, sampleNormal, gapNormal, randomNumbersNormal);
   
    delete[] gapLineal;
    delete[] gapNormal;

    return EXIT_SUCCESS;

}
