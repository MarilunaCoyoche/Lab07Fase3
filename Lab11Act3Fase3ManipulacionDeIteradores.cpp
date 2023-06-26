#include <iostream>
#include <deque>
#include <cctype>  // Para verificar vocales

using namespace std;

// Función para mostrar el contenido del deque
void mostrarDeque(const deque<char>& deque) {
    cout << "Contenido del deque: ";
    for (char c : deque) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    deque<char> caracteres;  // Contenedor deque para almacenar los caracteres

    int opcion;
    do {
        // Menú de opciones
        cout << "----------------------------------------------"  << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------------"  << endl;        
        cout << "1. Ingresar cadena de caracteres" << endl;
        cout << "2. Mostrar caracteres" << endl;
        cout << "3. Reemplazar vocales por '*'" << endl;
        cout << "4. Mostrar caracteres en orden inverso" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;        


        switch (opcion) {
            case 1: {
                // Ingresar cadena de caracteres
                string cadena;
                cout << "Ingrese una cadena de caracteres: ";
                cin >> cadena;

                // Almacenar cada caracter de la cadena en el deque
                for (char c : cadena) {
                    caracteres.push_back(c);
                }

                cout << "Cadena ingresada correctamente." << endl;
                break;
            }
            case 2: {
                // Mostrar caracteres
                cout << "Caracteres: ";
                for (char c : caracteres) {
                    cout << c << " ";
                }
                cout << endl;
                break;
            }
            case 3: {
                // Reemplazar vocales por '*'
                for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
                    if (tolower(*it) == 'a' || tolower(*it) == 'e' || tolower(*it) == 'i' ||
                        tolower(*it) == 'o' || tolower(*it) == 'u') {
                        *it = '*';
                    }
                }
                cout << "Vocales reemplazadas por '*'." << endl;
                break;
            }
            case 4: {
                // Mostrar caracteres en orden inverso
                cout << "Caracteres en orden inverso: ";
                for (auto rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
                    cout << *rit << " ";
                }
                cout << endl;
                break;
            }
            case 5: {
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
    } while (opcion != 5);

    
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
