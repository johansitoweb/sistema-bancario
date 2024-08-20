#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numeroCuenta;
    float saldo;
} CuentaBancaria;

void crearCuenta(CuentaBancaria *cuenta, int numero) {
    cuenta->numeroCuenta = numero;
    cuenta->saldo = 0.0;
    printf("Cuenta creada con éxito. Número de cuenta: %d\n", numero);
}

void depositar(CuentaBancaria *cuenta, float cantidad) {
    if (cantidad > 0) {
        cuenta->saldo += cantidad;
        printf("Depósito de %.2f realizado. Saldo actual: %.2f\n", cantidad, cuenta->saldo);
    } else {
        printf("La cantidad a depositar debe ser mayor que cero.\n");
    }
}

void retirar(CuentaBancaria *cuenta, float cantidad) {
    if (cantidad > 0 && cantidad <= cuenta->saldo) {
        cuenta->saldo -= cantidad;
        printf("Retiro de %.2f realizado. Saldo actual: %.2f\n", cantidad, cuenta->saldo);
    } else {
        printf("Retiro fallido. Verifique la cantidad.\n");
    }
}

void consultarSaldo(CuentaBancaria *cuenta) {
    printf("Saldo actual de la cuenta %d: %.2f\n", cuenta->numeroCuenta, cuenta->saldo);
}

void transferir(CuentaBancaria *cuentaOrigen, CuentaBancaria *cuentaDestino, float cantidad) {
    if (cantidad > 0 && cantidad <= cuentaOrigen->saldo) {
        cuentaOrigen->saldo -= cantidad;
        cuentaDestino->saldo += cantidad;
        printf("Transferencia de %.2f de la cuenta %d a la cuenta %d realizada con éxito.\n", cantidad, cuentaOrigen->numeroCuenta, cuentaDestino->numeroCuenta);
    } else {
        printf("Transferencia fallida. Verifique la cantidad y el saldo disponible.\n");
    }
}

int main() {
    CuentaBancaria cuenta1, cuenta2;
    int opcion;
    int numeroCuenta1, numeroCuenta2;

    printf("Bienvenido al sistema bancario\n");
    printf("Ingrese el número de cuenta para la primera cuenta: ");
    scanf("%d", &numeroCuenta1);
    crearCuenta(&cuenta1, numeroCuenta1);

    printf("Ingrese el número de cuenta para la segunda cuenta: ");
    scanf("%d", &numeroCuenta2);
    crearCuenta(&cuenta2, numeroCuenta2);

    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Depositar en cuenta 1\n");
        printf("2. Retirar de cuenta 1\n");
        printf("3. Consultar saldo de cuenta 1\n");
        printf("4. Depositar en cuenta 2\n");
        printf("5. Retirar de cuenta 2\n");
        printf("6. Consultar saldo de cuenta 2\n");
        printf("7. Transferir entre cuentas\n");
        printf("8. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float cantidad;
                printf("Ingrese la cantidad a depositar en cuenta 1: ");
                scanf("%f", &cantidad);
                depositar(&cuenta1, cantidad);
                break;
            }
            case 2: {
                float cantidad;
                printf("Ingrese la cantidad a retirar de cuenta 1: ");
                scanf("%f", &cantidad);
                retirar(&cuenta1, cantidad);
                break;
            }
            case 3:
                consultarSaldo(&cuenta1);
                break;
            case 4: {
                float cantidad;
                printf("Ingrese la cantidad a depositar en cuenta 2: ");
                scanf("%f", &cantidad);
                depositar(&cuenta2, cantidad);
                break;
            }
            case 5: {
                float cantidad;
                printf("Ingrese la cantidad a retirar de cuenta 2: ");
                scanf("%f", &cantidad);
                retirar(&cuenta2, cantidad);
                break;
            }
            case 6:
                consultarSaldo(&cuenta2);
                break;
            case 7: {
                float cantidad;
                printf("Ingrese la cantidad a transferir de cuenta 1 a cuenta 2: ");
                scanf("%f", &cantidad);
                transferir(&cuenta1, &cuenta2, cantidad);
                break;
            }
            case 8:
                printf("Saliendo del sistema. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 8);

    return 0;
}
