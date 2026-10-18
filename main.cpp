#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int op = 0;
    int numVentas = 0;
    double totalDia = 0.0;
    double prom = 0.0;

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
                cout << "\n-- Registro de venta (pendiente) --" << endl;
                break;

            case 2:
                cout << "\n-- Resumen parcial --\n";
                // calculo provisional del promedio (falta validar si no hay ventas)
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