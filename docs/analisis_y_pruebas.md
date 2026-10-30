# Documentación del Proyecto: Sistema de Caja para Tienda

## 1. Análisis del Problema
El programa automatiza el proceso de cobro en una tiendita de barrio mediante consola en C++[cite: 2, 8]. Permite al usuario interactuar a través de un menú repetitivo, ingresar productos por venta con precio y cantidad, aplicar descuentos según el volumen de compra, calcular el 12% de IVA, cobrar al cliente entregando el cambio correcto y generar un reporte estadístico al cierre del día sin riesgo de división entre cero[cite: 2, 4, 5, 6].

## 2. Pseudocódigo General
```text
Algoritmo SistemaCaja
    Inicializar acumuladores del dia (ventas, total, mayor, menor, descuentos)
    Repetir
        Mostrar menu (1. Registrar venta, 2. Resumen parcial, 3. Cerrar caja)
        Leer opcion
        Segun opcion Hacer
            1:
                subtotalVenta <- 0
                Repetir
                    Leer precio (validar >= 0)
                    Si precio > 0 Entonces
                        Leer cantidad (validar 1 a 100)
                        subtotalVenta <- subtotalVenta + (precio * cantidad)
                    FinSi
                Hasta Que precio == 0
                
                Calcular descuento (0%, 5% o 10%)
                Calcular IVA 12% sobre monto con descuento
                totalPagar <- (subtotalVenta - descuento) + IVA
                
                Repetir
                    Leer montoPago
                Hasta Que montoPago >= totalPagar
                
                cambio <- montoPago - totalPagar
                Imprimir recibo detallado
                Actualizar acumuladores del dia
            2:
                Si numeroVentas > 0 Entonces
                    Mostrar totales, mayor, menor y promedio
                Sino
                    Mostrar mensaje: No hay ventas registradas
                FinSi
            3:
                Mostrar resumen final y salir
            De Otro Modo:
                Mostrar error de opcion invalida
        FinSegun
    Hasta Que opcion == 3
FinAlgoritmo
## 3. Casos de Prueba Mínimos
- **Venta de Q99.99:** Subtotal menor a Q100 -> Descuento aplicado: 0%[cite: 6].
- **Venta de Q100.00:** Límite del tramo -> Descuento aplicado: 5%[cite: 6].
- **Venta de Q500.00:** Límite superior -> Descuento aplicado: 10%[cite: 6].
- **Validaciones de Entrada:**
  - Cantidad 0: Sistema rechaza y vuelve a solicitar cantidad[cite: 5].
  - Cantidad 101: Sistema rechaza (fuera del rango 1-100) y vuelve a solicitar[cite: 5].
  - Precio negativo: Sistema muestra error y pide precio válido[cite: 5].
  - Opción de menú "9": Sistema muestra "Opción inválida" y repite el menú[cite: 4].
- **Resumen sin ventas:** Muestra aviso amigable en lugar de provocar error de división entre cero[cite: 6].
- **Pago insuficiente:** Si el total es Q100 y el cliente ingresa Q80, el sistema solicita nuevamente el monto hasta cubrir el total[cite: 5].