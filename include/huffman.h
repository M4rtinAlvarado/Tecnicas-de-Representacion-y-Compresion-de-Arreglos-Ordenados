#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;


/** Nodo de un arbol de Huffman
 */
class nodoHuffman {
public:
    int data;
    int freq;
    nodoHuffman* izq;
    nodoHuffman* der;
    nodoHuffman(int valor, int frecuencia){
        data = valor;
        freq = frecuencia;
        izq = der = NULL;
    }
};

/**
 * Método de comparación de los nodos
 */
class Comparacion {
public:
    bool operator()(nodoHuffman* a, nodoHuffman* b){
        return a->freq > b->freq;
    }
};

void medirMemoria(nodoHuffman* root, int &acum){
    if(root->izq != nullptr){
        medirMemoria(root->izq, acum);
    }
    if(root->der != nullptr){
        medirMemoria(root->der, acum);
    }
    acum += sizeof(*root);
    return;

}

/** Genera el arbol de Huffman a partir de un priorityQueue
 * 
 * @param pq Cola de prioridad con los nodos del arbol
 * @return nodoHuffman* Raiz del arbol de Huffman
 */
nodoHuffman* generateTree(priority_queue<nodoHuffman*, vector<nodoHuffman*>, Comparacion> pq){
    while (pq.size() != 1){
        nodoHuffman* izq = pq.top();

        pq.pop();
        nodoHuffman* der = pq.top();

        pq.pop();
        nodoHuffman* nodo = new nodoHuffman('$', izq->freq + der->freq);

        nodo->izq = izq;
        nodo->der = der;

        pq.push(nodo);
    }
    return pq.top();
}



/** Recorre el arbol de Huffman y guarda los codigos en un hashmap
 * 
 * @param root Raiz del arbol de Huffman
 * @param str String que guarda el codigo
 * @param hashmapEncode Hashmap para guardar los codigos y los valores
 * @param hashmapDecode Hashmap para guardar los valores y los codigos
 */
void insertCodes(nodoHuffman* root, string str, unordered_map<unsigned short int, int> &hashmapEncode, unordered_map<int, unsigned short int> &hashmapDecode){
	if (root == nullptr)
		return;

	if (!root->izq && !root->der) {
        reverse(str.begin(), str.end());
        unsigned short int codigo = bitset<8>(str).to_ulong();
        hashmapDecode[root->data] = codigo;
        hashmapEncode[codigo] = root->data;
	}
	insertCodes(root->izq, str + "0", hashmapEncode, hashmapDecode);
	insertCodes(root->der, str + "1", hashmapEncode, hashmapDecode);
}


/** Genera la PriorityQueue y llama a generateTree para generar el arbol de Huffman, luego llama a insertCodes.
 * 
 * @param hashmapFrec Hashmap con la frecuencia de los elementos
 * @param hashmapDecode Hashmap para guardar los valores y los codigos
 * @param hashmapEncode Hashmap para guardar los codigos y los valores
 */
int HuffmanCodes(unordered_map<int, int> hashmapFrec, unordered_map<int, unsigned short int> &hashmapDecode, unordered_map<unsigned short int, int> &hashmapEncode){
    priority_queue<nodoHuffman *, vector<nodoHuffman *>, Comparacion> heap;
    for (auto x : hashmapFrec){
        nodoHuffman *nodo = new nodoHuffman(x.first, x.second);
        heap.push(nodo);
    }
    nodoHuffman *root = generateTree(heap);
    int aux = 0;
    medirMemoria(root, aux);
    insertCodes(root, "", hashmapEncode, hashmapDecode);

    return aux;
}

