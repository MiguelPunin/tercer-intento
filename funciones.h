void ingresarCliente(char clientes[][2][40]);
void imprimirClientes(char clientes[][2][40]);
void listarPeliculas(char peliculas[][4][40]);
void buscarporNombre(char peliculas[][4][40]);
void buscarporGenero(char peliculas[][4][40]);
void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]);
void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]);
void calcularCostoTotal(double precio[], int reserva[][4]);
 
void guardarPeliculasEnArchivo(char peliculas[][4][40], const char* archivo);
void cargarPeliculasDesdeArchivo(char peliculas[][4][40], const char* archivo);
void guardarClientesEnArchivo(char clientes[][2][40], const char* archivo);
void cargarClientesDesdeArchivo(char clientes[][2][40], const char* archivo);
void guardarReservasEnArchivo(int reserva[][4], const char* archivo);
void cargarReservasDesdeArchivo(int reserva[][4], const char* archivo);