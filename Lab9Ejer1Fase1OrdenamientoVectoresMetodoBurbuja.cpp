//LIBERÍAS

#include <iostream>
#include <vector>

using namespace std;

// Función de intercambio de elementos

/*
mySwap() es una función genérica de intercambio 
de elementos que toma dos referencias a objetos del tipo T 
(el tipo de dato genérico) y los intercambia utilizando una variable temporal. 
Esto permite intercambiar elementos de cualquier tipo, ya sea entero, flotante u otro owo.
*/

template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Función de ordenamiento usando el método de la burbuja

/*
La función bubbleSort() método de la burbuja para ordenar elementos en un vector. 
Esta función también está definida como una plantilla y toma un vector de 
tipo T como parámetro de entrada. 
*/
template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}


//función principal
int main() {
    int opcion;
    cout << "----------------------------------------------"  << endl;
    cout << "MENU PRINCIPAL"  << endl;
    cout << "----------------------------------------------"  << endl;
    cout << "Seleccione el tipo de elementos a ordenar: " << endl;
    cout << "1. Enteros" << endl;
    cout << "2. Flotantes" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    cout << "----------------------------------------------"  << endl;
    //elementos enteros

    if (opcion == 1) {
        vector<int> elementos = { 10, 5, 8, 2, 1 };

        // Mostrar elementos enteros originales
        cout << "Elementos (enteros) originales: ";
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;

        // Ordenar elementos enteros
        bubbleSort(elementos);

        // Mostrar elementos enteros ordenados
        cout << "Elementos (enteros) ordenados: ";
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
    //elementos flotantes

    else if (opcion == 2) {
        vector<float> elementos = { 3.4, 1.2, 5.6, 2.3, 0.8 };

        // Mostrar elementos flotantes originales
        cout << "Elementos (flotantes) originales: ";
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;

        // Ordenar elementos flotantes
        bubbleSort(elementos);

        // Mostrar elementos flotantes ordenados
        cout << "Elementos (flotantes) ordenados: ";
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
    else {
        cout << "Opción inválida owo" << endl;
    }

    //hora
    cout << "----------------------------------------------"  << endl;
    cout<<"Hora registrada"<<endl;

    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);    
    
    cout << "----------------------------------------------"  << endl;
    return 0;
}
