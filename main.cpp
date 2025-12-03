#include <iostream>
using namespace std;

// Nodo con valor entero y punteros a hijos
struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v): valor(v), izq(nullptr), der(nullptr) {}
};


// Árbol binario de búsqueda
class ArbolBinario {
private:
    Nodo* raiz;


    Nodo* insertarRec(Nodo* nodo, int v) {
        if (!nodo) return new Nodo(v);
        if (v < nodo->valor) nodo->izq = insertarRec(nodo->izq, v);
        else nodo->der = insertarRec(nodo->der, v);
        return nodo;
    }


    void enOrdenRec(Nodo* nodo) {
        if (!nodo) return;
        enOrdenRec(nodo->izq);
        cout << nodo->valor << " ";
        enOrdenRec(nodo->der);
    }


public:
    ArbolBinario(): raiz(nullptr) {}


    void insertar(int v) { raiz = insertarRec(raiz, v); }


    void enOrden() { enOrdenRec(raiz); cout << endl; }
};


int main() {
    ArbolBinario arbol;
    // Al menos 10 valores para probar
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 45};
    for (int v : valores) arbol.insertar(v);


    cout << "Imprimiendo el árbol en orden:\n";
    arbol.enOrden();


    return 0;
}