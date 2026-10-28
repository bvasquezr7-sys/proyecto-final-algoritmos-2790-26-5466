#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int op = 0;
    int numVentas = 0;
    double totalDia = 0.0;
    double prom = 0.0;

    // variables para la venta
    double precio = 0.0;
    int cant = 0;
    double subtotal = 0.0;

    cout << fixed << setprecision(2);

    do {
        cout << "\n=== SISTEMA DE CAJA ===\n";
        cout << "1. Registrar venta" << endl;
        cout << "2. Resumen parcial" << endl;
        cout << "3. Salir\n";
        cout << "Elige una opcion: ";
        cin >> op;

        // limpia el buffer por si meten letras
        while (cin.fail() || op < 1 || op > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opcion no valida, intenta de nuevo (1-3): ";
            cin >> op;
        }
        cin.ignore(1000, '\n');

        switch (op) {
            case 1:
                cout << "\n--- NUEVA VENTA (pon precio 0 para terminar) ---\n";
                // corregido: asegurar que el subtotal inicie en 0 y cantidad no pase de 100
                subtotal = 0.0;
                precio = -1.0;

                while (precio != 0.0) {
                    cout << "\nPrecio del producto: $";
                    cin >> precio;

                    // valida que no metan precio negativo ni letras
                    while (cin.fail() || precio < 0.0) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error, el precio debe ser >= 0. Intenta otra vez: $";
                        cin >> precio;
                    }
                    cin.ignore(1000, '\n');

                    // si no es 0 pedimos la cantidad
                    if (precio > 0.0) {
                        cout << "Cantidad (1 a 100): ";
                        cin >> cant;

                        // corregido: asegurar que el subtotal inicie en 0 y cantidad no pase de 100
                        while (cin.fail() || cant < 1 || cant > 100) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Error, la cantidad debe estar entre 1 y 100: ";
                            cin >> cant;
                        }
                        cin.ignore(1000, '\n');

                        subtotal = subtotal + (precio * cant);
                        cout << "Subtotal acumulado: $" << subtotal << endl;
                    }
                }

                cout << "\nSubtotal final de la venta: $" << subtotal << "\n";
                break;

            case 2:
                cout << "\n-- Resumen parcial --\n";
                prom = totalDia / numVentas;
                cout << "Ventas realizadas: " << numVentas << endl;
                cout << "Total del dia: $" << totalDia << endl;
                cout << "Promedio: $" << prom << "\n";
                break;

            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
        }

    } while (op != 3);

    return 0;
}