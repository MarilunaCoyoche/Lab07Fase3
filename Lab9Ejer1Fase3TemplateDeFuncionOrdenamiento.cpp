#include <iostream>

using namespace std;

// Plantilla de función para imprimir el arreglo
template <typename T>
void imprimirArreglo(const T arreglo[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Plantilla de función para ordenar el arreglo
template <typename T>
void ordenarArreglo(T arreglo[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

int main() {
    int arregloEnteros[] = {5, 2, 8, 1, 9};
    int tamañoEnteros = sizeof(arregloEnteros) / sizeof(arregloEnteros[0]);

    cout << "Arreglo original: ";
    imprimirArreglo(arregloEnteros, tamañoEnteros);

    ordenarArreglo(arregloEnteros, tamañoEnteros);

    cout << "Arreglo ordenado: ";
    imprimirArreglo(arregloEnteros, tamañoEnteros);

    return 0;
}
