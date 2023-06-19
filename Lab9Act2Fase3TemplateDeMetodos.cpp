#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*

Diseñar y definir clases relevantes para el 
sistema de gestión de rutas de entrega, como
una clase "Ruta" o "Entrega"

*/

// Clase para representar una entrega
class Entrega {
private:
    string destinatario;
    string direccion;

public:
    Entrega(const string& destinatario, const string& direccion)
        : destinatario(destinatario), direccion(direccion) {}

    string getDestinatario() const {
        return destinatario;
    }

    string getDireccion() const {
        return direccion;
    }
};

// Clase para representar una ruta de entrega
class Ruta {
private:
    vector<Entrega> entregas;

/*

Implementar templates de método dentro de estas clases para 
realizar operaciones específicas, como la asignación de vehículos 
a rutas o la planificación de horarios basados
en diferentes tipos de datos.

*/
public:
    // Método para agregar una entrega a la ruta
    void agregarEntrega(const Entrega& entrega) {
        entregas.push_back(entrega);
    }

    // Método template para realizar una operación específica en la ruta
    template <typename T>
    void asignarVehiculo(const T& vehiculo) {
        cout << "Asignando vehículo: " << vehiculo << " a la ruta." << endl;
    }

    // Método template para realizar una operación específica en la ruta
    template <typename T>
    void planificarHorarios(const T& horarios) {
        cout << "Planificando horarios basados en: " << horarios << endl;
    }
};

/*

Verificar la funcionalidad de los templates de método en 
diferentes instancias de las clases, asegurándose de que se 
adapten correctamente a los diferentes tipos de datos 
utilizados en el sistema.

*/

int main() {
    Ruta ruta;

    int opcion = 0;
    while (opcion != 5) {
        cout << "----------------------------------------------"  << endl;        
        cout << "Sistema de Gestión de Rutas de Entrega " << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Agregar entrega a la ruta" << endl;
        cout << "2. Asignar vehículo a la ruta" << endl;
        cout << "3. Planificar horarios basados en números enteros" << endl;
        cout << "4. Planificar horarios basados en texto" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese el número de la opción deseada: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;

        switch (opcion) {
            case 1: {
                string destinatario, direccion;
                cout << "Ingrese el nombre del destinatario: ";
                cin.ignore();
                getline(cin, destinatario);
                cout << "Ingrese la dirección de entrega: ";
                getline(cin, direccion);
                ruta.agregarEntrega(Entrega(destinatario, direccion));
                cout << "Entrega agregada correctamente." << endl;
                break;
            }
            case 2: {
                string vehiculo;
                cout << "Ingrese el vehículo a asignar: ";
                cin.ignore();
                getline(cin, vehiculo);
                ruta.asignarVehiculo(vehiculo);
                break;
            }
            case 3: {
                int horarios;
                cout << "Ingrese los horarios (números enteros): ";
                cin >> horarios;
                ruta.planificarHorarios(horarios);
                break;
            }
            case 4: {
                string horarios;
                cout << "Ingrese los horarios (texto): ";
                cin.ignore();
                getline(cin, horarios);
                ruta.planificarHorarios(horarios);
                break;
            }
            case 5:
                cout << "Fin del programa owo" << endl;
                break;
            default:
                cout << "Opción  no válida" << endl;
                break;
        }

        cout << endl;
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

