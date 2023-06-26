#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Evento {
    string nombre;
    string fecha;
    vector<string> asistentes;
};

// Función para agregar un nuevo evento a la lista
void agregarEvento(map<string, Evento>& eventos) {
    Evento evento;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, evento.nombre);
    cout << "Ingrese la fecha del evento: ";
    getline(cin, evento.fecha);

    eventos[evento.nombre] = evento;
    cout << "Evento agregado exitosamente." << endl;
}

// Función para agregar asistentes a un evento específico
void agregarAsistentes(map<string, Evento>& eventos) {
    string nombreEvento;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);

    // Verificar si el evento existe
    auto it = eventos.find(nombreEvento);
    if (it == eventos.end()) {
        cout << "El evento no existe." << endl;
        return;
    }

    Evento& evento = it->second;
    string nombreAsistente;
    cout << "Ingrese el nombre del asistente (ingrese '0' para finalizar): ";
    while (getline(cin, nombreAsistente)) {
        if (nombreAsistente == "0") {
            break;
        }
        evento.asistentes.push_back(nombreAsistente);
        cout << "Ingrese el nombre del asistente (ingrese '0' para finalizar): ";
    }

    cout << "Asistentes agregados exitosamente." << endl;
}

// Función para mostrar la lista de asistentes de un evento en orden alfabético
void mostrarAsistentes(map<string, Evento>& eventos) {
    string nombreEvento;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);

    // Verificar si el evento existe
    auto it = eventos.find(nombreEvento);
    if (it == eventos.end()) {
        cout << "El evento no existe." << endl;
        return;
    }

    Evento& evento = it->second;
    if (evento.asistentes.empty()) {
        cout << "El evento no tiene asistentes." << endl;
        return;
    }

    cout << "Asistentes del evento \"" << evento.nombre << "\":" << endl;
    sort(evento.asistentes.begin(), evento.asistentes.end());
    for (const string& asistente : evento.asistentes) {
        cout << asistente << endl;
    }
}

// Función para buscar eventos por fecha
void buscarEventosPorFecha(map<string, Evento>& eventos) {
    string fecha;
    cout << "Ingrese la fecha a buscar: ";
    cin.ignore();
    getline(cin, fecha);

    bool eventosEncontrados = false;
    for (const auto& par : eventos) {
        const string& nombreEvento = par.first;
        const Evento& evento = par.second;
        if (evento.fecha == fecha) {
            cout << "Evento: " << nombreEvento << endl;
            eventosEncontrados = true;
        }
    }

    if (!eventosEncontrados) {
        cout << "No se encontraron eventos para la fecha especificada." << endl;
    }
}

// Función para mostrar el menú y gestionar las operaciones
void mostrarMenu() {
    map<string, Evento> eventos;

    int opcion;
    do {
        cout << endl;
        cout << "----------------------------------------------"  << endl;        
        cout << "Menú" << endl;
        cout << "----------------------------------------------"  << endl;        
        cout << "1. Agregar un nuevo evento" << endl;
        cout << "2. Agregar asistentes a un evento" << endl;
        cout << "3. Mostrar lista de asistentes de un evento" << endl;
        cout << "4. Buscar eventos por fecha" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;        

        switch (opcion) {
            case 1:
                agregarEvento(eventos);
                break;
            case 2:
                agregarAsistentes(eventos);
                break;
            case 3:
                mostrarAsistentes(eventos);
                break;
            case 4:
                buscarEventosPorFecha(eventos);
                break;
            case 5:
                cout << "BYEBYE" << endl;
                break;
            default:
                cout << "Opción NO válida" << endl;
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
