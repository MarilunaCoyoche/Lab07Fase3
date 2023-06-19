#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*

Implementar templates de función para tareas específicas 
relacionadas con la gestión de rutas de entrega, como 
cálculos de distancia, tiempo estimado de entrega, o 
generación de informes basados en diferentes tipos de datos.

*/

// Template de función para calcular la distancia entre dos puntos
template <typename T>
T calcularDistancia(T x1, T y1, T x2, T y2) {
    T distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distancia;
}

// Template de función para calcular el tiempo estimado de entrega
template <typename T>
T calcularTiempoEstimado(T distancia, T velocidad) {
    T tiempo = distancia / velocidad;
    return tiempo;
}

// Template de función para generar informes basados en diferentes tipos de datos
template <typename T>
void generarInforme(const T& dato) {
    cout << "Informe generado: " << dato << endl;
}



/*

Probar y validar los templates de función en diferentes 
escenarios, asegurándose de que sean capaces de adaptarse 
a diferentes tipos de datos y producir resultados correctos 
y precisos.

*/

int main() {
    int opcion;
    
    do {
        // Menú de opciones
        cout << "----------------------------------------------"  << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Calcular distancia" << endl;
        cout << "2. Calcular tiempo estimado de entrega" << endl;
        cout << "3. Generar informe" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;

        
        switch (opcion) {
            case 1: {
                // Cálculo de distancia
                double x1, y1, x2, y2;
                cout << "Ingrese las coordenadas del primer punto (x y): ";
                cin >> x1 >> y1;
                cout << "Ingrese las coordenadas del segundo punto (x y): ";
                cin >> x2 >> y2;
                
                double distancia = calcularDistancia(x1, y1, x2, y2);
                cout << "----------------------------------------------"  << endl;
                cout << "Distancia: " << distancia << endl;
                cout << "----------------------------------------------"  << endl;

                break;
            }
            case 2: {
                // Cálculo de tiempo estimado de entrega
                double distancia, velocidad;
                cout << "Ingrese la distancia: ";
                cin >> distancia;
                cout << "Ingrese la velocidad: ";
                cin >> velocidad;
                
                double tiempo = calcularTiempoEstimado(distancia, velocidad);
                cout << "----------------------------------------------"  << endl;
                cout << "Tiempo estimado de entrega: " << tiempo << " horas" << endl;
                cout << "----------------------------------------------"  << endl;
                break;
            }
            case 3: {
                // Generación de informe
                string informe;
                cout << "Ingrese el contenido del informe: ";
                cin.ignore();
                getline(cin, informe);
                
                generarInforme(informe);
                break;
            }
            case 4: {
                // Salir del programa
                cout << "Fin del programa owo" << endl;
                break;
            }
            default:
                cout << "Opción no válida" << endl;
        }
        
        cout << endl;
        
    } while (opcion != 4);
    
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
