#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string correo;
};

// Función para agregar un nuevo contacto a la agenda
void agregarContacto(map<string, Contacto>& agenda) {
    Contacto contacto;
    cout << "Ingrese el nombre del contacto: ";
    cin.ignore();
    getline(cin, contacto.nombre);
    cout << "Ingrese el número de teléfono del contacto: ";
    getline(cin, contacto.telefono);
    cout << "Ingrese la dirección de correo electrónico del contacto: ";
    getline(cin, contacto.correo);

    agenda[contacto.nombre] = contacto;
    cout << "Contacto agregado exitosamente." << endl;
}

// Función para buscar un contacto por su nombre
void buscarContacto(const map<string, Contacto>& agenda) {
    string nombre;
    cout << "Ingrese el nombre del contacto a buscar: ";
    cin.ignore();
    getline(cin, nombre);

    // Verificar si el contacto existe
    auto it = agenda.find(nombre);
    if (it == agenda.end()) {
        cout << "El contacto no existe." << endl;
        return;
    }

    const Contacto& contacto = it->second;
    cout << "Nombre: " << contacto.nombre << endl;
    cout << "Teléfono: " << contacto.telefono << endl;
    cout << "Correo electrónico: " << contacto.correo << endl;
}

// Función para actualizar la información de un contacto existente
void actualizarContacto(map<string, Contacto>& agenda) {
    string nombre;
    cout << "Ingrese el nombre del contacto a actualizar: ";
    cin.ignore();
    getline(cin, nombre);

    // Verificar si el contacto existe
    auto it = agenda.find(nombre);
    if (it == agenda.end()) {
        cout << "El contacto no existe." << endl;
        return;
    }

    Contacto& contacto = it->second;
    cout << "Ingrese el nuevo número de teléfono del contacto: ";
    getline(cin, contacto.telefono);
    cout << "Ingrese la nueva dirección de correo electrónico del contacto: ";
    getline(cin, contacto.correo);

    cout << "Contacto actualizado exitosamente." << endl;
}

// Función para mostrar la lista de contactos ordenada alfabéticamente
void mostrarContactos(const map<string, Contacto>& agenda) {
    if (agenda.empty()) {
        cout << "La agenda no tiene contactos." << endl;
        return;
    }

    cout << "Lista de contactos:" << endl;
    for (const auto& par : agenda) {
        const Contacto& contacto = par.second;
        cout << "Nombre: " << contacto.nombre << endl;
        cout << "Teléfono: " << contacto.telefono << endl;
        cout << "Correo electrónico: " << contacto.correo << endl;
        cout << endl;
    }
}

// Función para mostrar el menú y gestionar las operaciones
void mostrarMenu() {
    map<string, Contacto> agenda;

    int opcion;
    do {
        cout << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Calcular distancia" << endl;        
        cout << "1. Agregar un nuevo contacto" << endl;
        cout << "2. Buscar un contacto por su nombre" << endl;
        cout << "3. Actualizar la información de un contacto existente" << endl;
        cout << "4. Mostrar la lista de contactos ordenada alfabéticamente" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarContacto(agenda);
                break;
            case 2:
                buscarContacto(agenda);
                break;
            case 3:
                actualizarContacto(agenda);
                break;
            case 4:
                mostrarContactos(agenda);
                break;
            case 5:
                cout << "BYEBYE" << endl;
                break;
            default:
                cout << "Opción NO inválida" << endl;
                break;
        }
    } while (opcion != 5);
}

int main() {
    mostrarMenu();
    
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
