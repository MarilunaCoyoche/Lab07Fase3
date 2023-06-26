#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct Producto {
    string codigo;
    string descripcion;
    int cantidad;
};

// Función para mostrar un producto
void mostrarProducto(const Producto& producto) {
    cout << "Código: " << producto.codigo << endl;
    cout << "Descripción: " << producto.descripcion << endl;
    cout << "Cantidad: " << producto.cantidad << endl;
    cout << "---------------------------" << endl;
}

int main() {
    unordered_map<string, Producto> inventario;

    int opcion = 0;
    while (opcion != 5) {
        cout << "----------------------------------------------"  << endl;        
        cout << " GESTIÓN DE INVENTARIO " << endl;
        cout << "----------------------------------------------"  << endl;        
        cout << "1. Agregar producto" << endl;
        cout << "2. Actualizar cantidad" << endl;
        cout << "3. Buscar producto por código" << endl;
        cout << "4. Mostrar inventario ordenado por descripción" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;        

        if (opcion == 1) {
            Producto producto;
            cout << "Ingrese el código del producto: ";
            cin >> producto.codigo;
            cout << "Ingrese la descripción del producto: ";
            cin >> producto.descripcion;
            cout << "Ingrese la cantidad disponible: ";
            cin >> producto.cantidad;

            inventario[producto.codigo] = producto;
        } else if (opcion == 2) {
            string codigo;
            int nuevaCantidad;
            cout << "Ingrese el código del producto: ";
            cin >> codigo;
            cout << "Ingrese la nueva cantidad disponible: ";
            cin >> nuevaCantidad;

            if (inventario.count(codigo) > 0) {
                inventario[codigo].cantidad = nuevaCantidad;
                cout << "Cantidad actualizada exitosamente." << endl;
            } else {
                cout << "El producto no existe en el inventario." << endl;
            }
        } else if (opcion == 3) {
            string codigo;
            cout << "Ingrese el código del producto: ";
            cin >> codigo;

            if (inventario.count(codigo) > 0) {
                cout << "Producto encontrado:" << endl;
                mostrarProducto(inventario[codigo]);
            } else {
                cout << "El producto no existe en el inventario." << endl;
            }
        } else if (opcion == 4) {
            // Crear una copia del inventario y ordenarla por descripción
            vector<pair<string, Producto>> inventarioOrdenado(inventario.begin(), inventario.end());
            sort(inventarioOrdenado.begin(), inventarioOrdenado.end(), [](const pair<string, Producto>& p1, const pair<string, Producto>& p2) {
                return p1.second.descripcion < p2.second.descripcion;
            });

            // Mostrar la lista de productos ordenada por descripción
            for (const auto& producto : inventarioOrdenado) {
                mostrarProducto(producto.second);
            }
        } else if (opcion == 5) {
            cout << "BYEBYE" << endl;
        } else {
            cout << "Opción no válida." << endl;
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
