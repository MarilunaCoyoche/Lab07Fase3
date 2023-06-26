#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>  // Para convertir a mayúsculas

using namespace std;

// Función para mostrar el contenido de la lista
void mostrarLista(const list<string>& lista) {
    cout << "Contenido de la lista: ";
    for (const string& palabra : lista) {
        cout << palabra << " ";
    }
    cout << endl;
}

int main() {
    list<string> palabras;  // Contenedor para almacenar las palabras

    int opcion;
    do {
        // Menú de opciones
        cout << "----------------------------------------------"  << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------------"  << endl;        
        cout << "1. Ingresar palabra" << endl;
        cout << "2. Ordenar palabras en orden alfabético" << endl;
        cout << "3. Contar ocurrencias de una palabra" << endl;
        cout << "4. Convertir palabras a mayúsculas" << endl;
        cout << "5. Mostrar contenido de la lista" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;        

        switch (opcion) {
            case 1: {
                // Ingresar palabra
                string palabra;
                cout << "Ingrese una palabra: ";
                cin >> palabra;
                palabras.push_back(palabra);
                cout << "Palabra ingresada correctamente." << endl;
                break;
            }
            case 2: {
                // Ordenar palabras en orden alfabético
                palabras.sort();
                cout << "Palabras ordenadas en orden alfabético." << endl;
                break;
            }
            case 3: {
                // Contar ocurrencias de una palabra
                string palabraBuscada;
                cout << "Ingrese la palabra que desea buscar: ";
                cin >> palabraBuscada;

                int conteo = count(palabras.begin(), palabras.end(), palabraBuscada);
                cout << "La palabra '" << palabraBuscada << "' aparece " << conteo << " veces en la lista." << endl;
                break;
            }
            case 4: {
                // Convertir palabras a mayúsculas
                transform(palabras.begin(), palabras.end(), palabras.begin(), [](string& palabra) {
                    for (char& c : palabra) {
                        c = toupper(c);
                    }
                    return palabra;
                });
                cout << "Palabras convertidas a mayúsculas." << endl;
                break;
            }
            case 5: {
                // Mostrar contenido de la lista
                mostrarLista(palabras);
                break;
            }
            case 6: {
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
    } while (opcion != 6);

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
