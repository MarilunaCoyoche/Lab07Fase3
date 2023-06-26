#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para mostrar el contenido del contenedor vector
void mostrarContenedor(const vector<int>& contenedor) {
    cout << "Contenido del contenedor: ";
    for (int num : contenedor) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numeros;  // Contenedor para almacenar los números

    int opcion;
    do {
        // Menú de opciones
        cout << "----------------------------------------------"  << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Ingresar número" << endl;
        cout << "2. Calcular suma de los números" << endl;
        cout << "3. Encontrar número máximo y mínimo" << endl;
        cout << "4. Ordenar los números de forma ascendente" << endl;
        cout << "5. Eliminar los números pares" << endl;
        cout << "6. Mostrar contenido del contenedor" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;

        switch (opcion) {
            case 1: {
                // Ingresar número
                int numero;
                cout << "Ingrese un número: ";
                cin >> numero;
                numeros.push_back(numero);
                cout << "Número ingresado correctamente." << endl;
                break;
            }
            case 2: {
                // Calcular la suma de los números
                int suma = 0;
                for (int num : numeros) {
                    suma += num;
                }
                cout << "La suma de los números es: " << suma << endl;
                break;
            }
            case 3: {
                // Encontrar número máximo y mínimo
                if (!numeros.empty()) {
                    int maximo = *max_element(numeros.begin(), numeros.end());
                    int minimo = *min_element(numeros.begin(), numeros.end());
                    cout << "Número máximo: " << maximo << endl;
                    cout << "Número mínimo: " << minimo << endl;
                } else {
                    cout << "El contenedor está vacío. No se pueden encontrar el máximo y mínimo." << endl;
                }
                break;
            }
            case 4: {
                // Ordenar los números de forma ascendente
                sort(numeros.begin(), numeros.end());
                cout << "Números ordenados de forma ascendente." << endl;
                break;
            }
            case 5: {
                // Eliminar los números pares
                numeros.erase(remove_if(numeros.begin(), numeros.end(), [](int num) {
                    return num % 2 == 0;
                }), numeros.end());
                cout << "Números pares eliminados del contenedor." << endl;
                break;
            }
            case 6: {
                // Mostrar contenido del contenedor
                mostrarContenedor(numeros);
                break;
            }
            case 7: {
                // Salir del programa
                cout << "BYEBYE" << endl;
                break;
            }
            default: {
                cout << "Opción NO válida" << endl;
                break;
            }
        }

        cout << endl;
    } while (opcion != 7);

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
