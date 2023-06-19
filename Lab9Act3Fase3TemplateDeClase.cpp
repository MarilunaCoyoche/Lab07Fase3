#include <iostream>
#include <vector>

using namespace std;

/*

Diseñar y definir una clase principal que represente 
el sistema de gestión de rutas de
entrega en su totalidad.

*/

// Clase principal que representa el sistema de gestión de rutas de entrega
template<typename T>
class SistemaGestionRutas {
private:
    vector<T> rutas;  // Vector para almacenar las rutas de entrega


/*

Implementar templates de clase dentro de esta clase principal 
para abordar aspectos clave del sistema, como la administración 
de rutas, la optimización de recursos o la generación
de informes.

*/
public:
    // Método para agregar una nueva ruta de entrega al sistema
    void agregarRuta(const T& ruta) {
        rutas.push_back(ruta);
    }

    // Método para eliminar una ruta existente del sistema
    void eliminarRuta(const T& ruta) {
        // Buscar la ruta en el vector y eliminarla
        for (auto it = rutas.begin(); it != rutas.end(); ++it) {
            if (*it == ruta) {
                rutas.erase(it);
                break;
            }
        }
    }

    // Método para obtener la cantidad total de rutas en el sistema
    int obtenerCantidadRutas() const {
        return rutas.size();
    }

    // Método para realizar la optimización de recursos de las rutas
    void optimizarRecursos() {
        // Implementar la lógica de optimización de recursos aquí
        // Puede incluir cálculos de distancias, asignación de vehículos, etc.
        cout << "Se han optimizado los recursos de las rutas." << endl;
    }

    // Método para generar informes de las rutas
    void generarInformes() const {
        // Implementar la generación de informes aquí
        // Puede ser en formato de texto, archivo CSV, etc.
        cout << "Se han generado los informes de las rutas." << endl;
    }
};

// Función para mostrar el menú de opciones y obtener la selección del usuario
int mostrarMenu() {
    int opcion;
    cout << "----------------------------------------------"  << endl;
    cout << "Menú de opciones " << endl;
    cout << "----------------------------------------------"  << endl;
    cout << "1. Agregar ruta" << endl;
    cout << "2. Eliminar ruta" << endl;
    cout << "3. Mostrar cantidad de rutas" << endl;
    cout << "4. Optimizar recursos" << endl;
    cout << "5. Generar informes" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    cout << "----------------------------------------------"  << endl;
    cout << endl;
    return opcion;
}


/*

Probar exhaustivamente los templates de clase en diferentes escenarios, 
asegurándose de que sean capaces de adaptarse a diferentes tipos de datos 
y proporcionar la funcionalidad esperada en cada caso.

*/

// Ejemplo de uso de la clase principal
int main() {
    SistemaGestionRutas<int> sistema;

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1: {
                int ruta;
                cout << "Ingrese el número de la ruta a agregar: ";
                cin >> ruta;
                sistema.agregarRuta(ruta);
                cout << "Ruta agregada exitosamente." << endl;
                cout << "----------------------------------------------"  << endl;
                break;
            }
            case 2: {
                int ruta;
                cout << "Ingrese el número de la ruta a eliminar: ";
                cin >> ruta;
                sistema.eliminarRuta(ruta);
                cout << "Ruta eliminada exitosamente." << endl;
                cout << "----------------------------------------------"  << endl;
                break;
            }
            case 3: {
                int cantidadRutas = sistema.obtenerCantidadRutas();
                cout << "Cantidad de rutas en el sistema: " << cantidadRutas << endl;
                cout << "----------------------------------------------"  << endl;
                break;
            }
            case 4:
                sistema.optimizarRecursos();
                break;
            case 5:
                sistema.generarInformes();
                break;
            case 6:
                cout << "Fin del programa owo" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
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

