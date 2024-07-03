#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
// Funciones para manejar archivos
 
void guardarPeliculasEnArchivo(char peliculas[][4][40], const char* archivo) {
    FILE *file = fopen(archivo, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de peliculas.\n");
        return;
    }
 
    for (int i = 0; i < 20; i++) {
        fprintf(file, "%s|%s|%s|%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
 
    fclose(file);
}
 
void cargarPeliculasDesdeArchivo(char peliculas[][4][40], const char* archivo) {
    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        file = fopen(archivo, "w"); // Crear el archivo si no existe
        if (file != NULL) {
            fclose(file);
        }
        return;
    }
 
    for (int i = 0; i < 20; i++) {
        fscanf(file, " %39[^|]|%39[^|]|%39[^|]|%39[^\n]", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
 
    fclose(file);
}
 
void guardarClientesEnArchivo(char clientes[][2][40], const char* archivo) {
    FILE *file = fopen(archivo, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
 
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s|%s\n", clientes[i][0], clientes[i][1]);
    }
 
    fclose(file);
}
 
void cargarClientesDesdeArchivo(char clientes[][2][40], const char* archivo) {
    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        file = fopen(archivo, "w"); // Crear el archivo si no existe
        if (file != NULL) {
            fclose(file);
        }
        return;
    }
 
    for (int i = 0; i < 5; i++) {
        fscanf(file, " %39[^|]|%39[^\n]", clientes[i][0], clientes[i][1]);
    }
 
    fclose(file);
}
 
void guardarReservasEnArchivo(int reserva[][4], const char* archivo) {
    FILE *file = fopen(archivo, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de reservas.\n");
        return;
    }
 
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d|%d|%d|%d\n", reserva[i][0], reserva[i][1], reserva[i][2], reserva[i][3]);
    }
 
    fclose(file);
}
 
void cargarReservasDesdeArchivo(int reserva[][4], const char* archivo) {
    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        file = fopen(archivo, "w"); // Crear el archivo si no existe
        if (file != NULL) {
            fclose(file);
        }
        return;
    }
 
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d|%d|%d|%d", &reserva[i][0], &reserva[i][1], &reserva[i][2], &reserva[i][3]);
    }
 
    fclose(file);
}
 
// Funciones originales
 
void ingresarCliente(char clientes[][2][40]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "") == 0) {
            printf("Ingrese nombre del nuevo cliente: ");
            scanf(" %[^\n]s", clientes[i][0]); // Leer hasta el final de la línea
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s", clientes[i][1]);
            break;
        }
    }
    imprimirClientes(clientes);
}
 
void imprimirClientes(char clientes[][2][40]) {
    for (int i = 0; i < 5; i++) {
        printf("%s\t%s\n", clientes[i][0], clientes[i][1]);
    }
}
 
void listarPeliculas(char peliculas[][4][40]) {
    for (int i = 0; i < 20; i++) {
        if (strcmp(peliculas[i][0], "") != 0) {
            printf("%s Nombre: %s Hora: %s Género: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}
 
void buscarporNombre(char peliculas[][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la película: ");
    scanf(" %[^\n]s", nombre); // Leer hasta el final de la línea
 
    for (int i = 0; i < 20; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            printf("%s Nombre: %s Hora: %s Género: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Película no encontrada.\n");
}
 
void buscarporGenero(char peliculas[][4][40]) {
    char genero[40];
    printf("Ingrese el género de la película: ");
    scanf(" %[^\n]s", genero); // Leer hasta el final de la línea
 
    for (int i = 0; i < 20; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("%s Nombre: %s Hora: %s Género: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Película no encontrada.\n");
}
 
void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    int clienteCedula, peliculaID;
    char cedula[40];
    int clienteEncontrado = -1;
    int cantidadEntradas[3] = {0, 0, 0};
 
    // Mostrar clientes registrados
    printf("Clientes registrados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - %s\n", i + 1, clientes[i][0], clientes[i][1]);
    }
    printf("¿Su cédula está en la lista? (1.Si / 2.No): ");
    int opcion;
    scanf("%d", &opcion);
 
    if (opcion == 1) {
        printf("Seleccione el número del cliente: ");
        scanf("%d", &clienteCedula);
        clienteCedula--; // Ajustar índice
        clienteEncontrado = clienteCedula;
    } else {
        printf("Ingrese su cédula: ");
        scanf("%s", cedula);
 
        // Buscar cédula en la lista de clientes
        for (int i = 0; i < 5; i++) {
            if (strcmp(clientes[i][1], cedula) == 0) {
                clienteEncontrado = i;
                break;
            }
        }
 
        // Si no se encuentra, añadir nuevo cliente
        if (clienteEncontrado == -1) {
            printf("Ingrese su nombre: ");
            scanf(" %[^\n]s", clientes[4][0]); // Leer hasta el final de la línea
            strcpy(clientes[4][1], cedula);
            clienteEncontrado = 4;
        }
    }
 
    listarPeliculas(peliculas);
 
    printf("Seleccione el número de la película: ");
    scanf("%d", &peliculaID);
 
    // Solicitar la cantidad de entradas por tipo
    printf("¿Cuántas entradas de tipo Normal (0) quiere?: ");
    scanf("%d", &cantidadEntradas[0]);
    printf("¿Cuántas entradas de tipo Niños (1) quiere?: ");
    scanf("%d", &cantidadEntradas[1]);
    printf("¿Cuántas entradas de tipo Tercera Edad (2) quiere?: ");
    scanf("%d", &cantidadEntradas[2]);
 
    // Registrar la reserva y calcular la factura
    double total = 0.0;
    printf("Factura:\n");
    for (int tipoEntrada = 0; tipoEntrada < 3; tipoEntrada++) {
        if (cantidadEntradas[tipoEntrada] > 0) {
            printf("Tipo de Entrada: %d Cantidad: %d Precio por unidad: %.2f Subtotal: %.2f\n", tipoEntrada, cantidadEntradas[tipoEntrada], precio[tipoEntrada], cantidadEntradas[tipoEntrada] * precio[tipoEntrada]);
            total += cantidadEntradas[tipoEntrada] * precio[tipoEntrada];
        }
    }
    printf("Total a pagar: %.2f\n", total);
 
    for (int tipoEntrada = 0; tipoEntrada < 3; tipoEntrada++) {
        for (int i = 0; i < cantidadEntradas[tipoEntrada]; i++) {
            for (int j = 0; j < 10; j++) {
                if (reserva[j][0] == -1) {
                    reserva[j][0] = clienteEncontrado;
                    reserva[j][1] = peliculaID - 1;
                    reserva[j][2] = tipoEntrada;
                    reserva[j][3] = 1;
                    break;
                }
            }
        }
    }
 
    printf("Tickets comprados exitosamente.\n");
}
 
void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] != -1) {
            int clienteID = reserva[i][0];
            int peliculaID = reserva[i][1];
            int tipoEntrada = reserva[i][2];
            printf("Cliente: %s Película: %s Tipo de Entrada: %d Precio: %.2f\n", clientes[clienteID][0], peliculas[peliculaID][1], tipoEntrada, precio[tipoEntrada]);
        }
    }
}
 
void calcularCostoTotal(double precio[], int reserva[][4]) {
    double total = 0.0;
    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] != -1) {
            int tipoEntrada = reserva[i][2];
            total += precio[tipoEntrada];
        }
    }
    printf("El costo total de todas las compras es: %.2f\n", total);
}