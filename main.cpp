#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int op = 0;
    int numVentas = 0;
    double totalDia = 0.0;
    double prom = 0.0;

    // variables para la venta y cobro
    double precio = 0.0;
    int cant = 0;
    double subtotal = 0.0;
    double porcDesc = 0.0;
    double desc = 0.0;
    double subConDesc = 0.0;
    double iva = 0.0;
    double total = 0.0;
    double pago = 0.0;
    double cambio = 0.0;

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

                    if (precio > 0.0) {
                        cout << "Cantidad (1 a 100): ";
                        cin >> cant;

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

                // solo cobramos si compraron algo
                if (subtotal > 0.0) {
                    // saca el porcentaje de descuento segun el subtotal
                    if (subtotal < 100.0) {
                        porcDesc = 0.0;
                    } else if (subtotal < 500.0) {
                        porcDesc = 0.05;
                    } else {
                        porcDesc = 0.10;
                    }

                    desc = subtotal * porcDesc;
                    subConDesc = subtotal - desc;
                    iva = subConDesc * 0.12;
                    total = subConDesc + iva;

                    cout << "\nTotal a pagar (con IVA): $" << total << endl;
                    cout << "Con cuanto paga el cliente?: $";
                    cin >> pago;

                    // corregido: ciclo para obligar a que el pago alcance a cubrir el total
                    while (cin.fail() || pago < total) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Pago insuficiente o invalido. Debe ser al menos $" << total << ": $";
                        cin >> pago;
                    }
                    cin.ignore(1000, '\n');

                    cambio = pago - total;

                    // impresion del recibo con 2 decimales
                    cout << "\n========== RECIBO DE VENTA ==========\n";
                    cout << "Subtotal:              $" << subtotal << endl;
                    cout << "Descuento (" << (porcDesc * 100) << "%):     -$" << desc << endl;
                    cout << "Subtotal c/descuento:  $" << subConDesc << endl;
                    cout << "IVA (12%):            +$" << iva << endl;
                    cout << "-------------------------------------\n";
                    cout << "TOTAL:                 $" << total << endl;
                    cout << "Pago recibido:         $" << pago << endl;
                    cout << "Cambio:                $" << cambio << "\n";
                    cout << "=====================================" << endl;
                } else {
                    cout << "\nNo se ingresaron productos, venta cancelada.\n";
                }
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