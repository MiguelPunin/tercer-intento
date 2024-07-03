#include <stdio.h>
#include "funciones.h"
 
int main (int argc, char *argv[]) {
    char peliculas[20][4][40] = {
        {"1", "Avatar", "10:20", "Fantasia"},
        {"2", "Cars 1", "11:20", "Animada"},
        {"3", "Barbie y el castillo de princesas", "12:20", "Animada"},
        {"4", "El conjuro 1", "17:50", "Terror"},
        {"5", "Mision Imposible", "15:30", "Accion"},
        {"6", "Matrix", "13:30", "Ciencia ficcion"},
        {"7", "Intensamente 2", "18:00", "Animada"},
        {"8", "BAD BOYS", "16:00", "Accion"},
        {"9", "Fast and furious", "14:30", "Accion"},
        {"10", "La llorona", "18:20", "Terror"},
        {"11", "50 sombras de grey", "20:00", "Romance"},
        {"12", "Pocoyo", "11:40", "Animado"}
    };
    double precio[3] = {7, 3.5, 3};
    char clientes[5][2][40] = {
        {"Maria Gomez", "142658735"},
        {"Luis Perez", "123456788"},
        {"Pedro Rodriguez", "84824692"},
        {"Ana Hernandez", "459276183"},
        {"Alejandro Larrea", "102795432"}
    };
 
    int reserva[10][4] = {
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}
    };
 
    // Nombres de los archivos
    const char* archivoPeliculas = "peliculas.txt";
    const char* archivoClientes = "clientes.txt";
    const char* archivoReservas = "reservas.txt";
 
    // Cargar datos desde archivos
    cargarPeliculasDesdeArchivo(peliculas, archivoPeliculas);
    cargarClientesDesdeArchivo(clientes, archivoClientes);
    cargarReservasDesdeArchivo(reserva, archivoReservas);
 
    int opcion1 = 0, opcion2 = 0, opcion3 = 0;
    do {
        printf("Escoja una opcion:\n1. Ingresar Cliente\n2. Ver Peliculas\n3. Buscar Pelicula\n4. Comprar Ticket\n5. Ver Compras\n>> ");
        scanf("%d", &opcion2);
        switch (opcion2) {
            case 1:
                ingresarCliente(clientes);
                guardarClientesEnArchivo(clientes, archivoClientes);
                break;
            case 2:
                listarPeliculas(peliculas);
                break;
            case 3:
                printf("1. Por nombre\n2. Por Genero\n>> ");
                scanf("%d", &opcion3);
                switch (opcion3) {
                    case 1:
                        buscarporNombre(peliculas);
                        break;
                    case 2:
                        buscarporGenero(peliculas);
                        break;
                    default:
                        printf("Opcion no valida.\n");
                        break;
                }
                break;
            case 4:
                comprarTicket(peliculas, precio, clientes, reserva);
                guardarReservasEnArchivo(reserva, archivoReservas);
                break;
            case 5:
                verCompras(peliculas, precio, clientes, reserva);
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
        printf("Desea escoger una nueva opcion: 1. Si / 2. No\n>> ");
        scanf("%d", &opcion1);
    } while (opcion1 == 1);
 
    // Guardar datos en archivos
    guardarPeliculasEnArchivo(peliculas, archivoPeliculas);
    guardarClientesEnArchivo(clientes, archivoClientes);
    guardarReservasEnArchivo(reserva, archivoReservas);
 
    // Llamada a la función para calcular el costo total
    calcularCostoTotal(precio, reserva);
 
    return 0;
}