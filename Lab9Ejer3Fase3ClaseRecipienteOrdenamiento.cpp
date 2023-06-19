#include <iostream>

using namespace std;

// Clase contenedora genérica
template <typename T>
class Contenedor {
private:
    T* arreglo;
    int tamaño;

public:
    Contenedor(T arr[], int size) {
        tamaño = size;
        arreglo = new T[tamaño];
        for (int i = 0; i < tamaño; i++) {
            arreglo[i] = arr[i];
        }
    }

    ~Contenedor() {
        delete[] arreglo;
    }

    // Método para imprimir el arreglo
    void imprimirArreglo() {
        for (int i = 0; i < tamaño; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arregloEnteros[] = {5, 2, 8, 1, 9};
    int tamañoEnteros = sizeof(arregloEnteros) / sizeof(arregloEnteros[0]);

    Contenedor<int> contenedorEnteros(arregloEnteros, tamañoEnteros);

    cout << "Arreglo de enteros: ";
    contenedorEnteros.imprimirArreglo();

    float arregloFlotantes[] = {3.14, 1.5, 2.7};
    int tamañoFlotantes = sizeof(arregloFlotantes) / sizeof(arregloFlotantes[0]);

    Contenedor<float> contenedorFlotantes(arregloFlotantes, tamañoFlotantes);

    cout << "Arreglo de flotantes: ";
    contenedorFlotantes.imprimirArreglo();

    return 0;
}
