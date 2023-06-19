#include <iostream>

using namespace std;

// Clase que representa un arreglo genérico
template <typename T>
class Arreglo {
private:
    T* elementos;
    int tamaño;

public:
    Arreglo(T arr[], int size) {
        tamaño = size;
        elementos = new T[tamaño];
        for (int i = 0; i < tamaño; i++) {
            elementos[i] = arr[i];
        }
    }

    ~Arreglo() {
        delete[] elementos;
    }

    // Método para imprimir el arreglo
    void imprimirArreglo() {
        for (int i = 0; i < tamaño; i++) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }

    // Método para ordenar el arreglo
    void ordenarArreglo() {
        for (int i = 0; i < tamaño - 1; i++) {
            for (int j = 0; j < tamaño - i - 1; j++) {
                if (elementos[j] > elementos[j + 1]) {
                    swap(elementos[j], elementos[j + 1]);
                }
            }
        }
    }
};

int main() {
    int arregloEnteros[] = {5, 2, 8, 1, 9};
    int tamañoEnteros = sizeof(arregloEnteros) / sizeof(arregloEnteros[0]);

    Arreglo<int> arreglo(arregloEnteros, tamañoEnteros);

    cout << "Arreglo original: ";
    arreglo.imprimirArreglo();

    arreglo.ordenarArreglo();

    cout << "Arreglo ordenado: ";
    arreglo.imprimirArreglo();

    return 0;
}
