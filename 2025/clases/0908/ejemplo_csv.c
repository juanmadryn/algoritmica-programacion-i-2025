#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINEA 256
#define MAX_REGISTROS 100

// Definición del struct para un registro del CSV
typedef struct {
    char fecha[20];
    char descripcion[50];
    char debitos[20];
    char creditos[20];
    char leyenda[100];
} Registro;

int main() {
    Registro registros[MAX_REGISTROS];
    int cantidad = 0;
    char linea[MAX_LINEA];

    // Cabecera
    printf("%-12s | %-35s | %-10s | %-10s | %s\n", "Fecha", "Descripción", "Débitos", "Créditos", "Leyenda");
    printf("-------------------------------------------------------------------------------\n");

    // Leer línea por línea desde stdin
    while (fgets(linea, sizeof(linea), stdin) && cantidad < MAX_REGISTROS) {
        // Eliminar salto de línea final
        size_t len = strlen(linea);
        if (len > 0 && linea[len - 1] == '\n') {
            linea[len - 1] = '\0';
        }

        // Tokenización
        char *token = strtok(linea, ";");
        if (!token) continue;
        strncpy(registros[cantidad].fecha, token, sizeof(registros[cantidad].fecha));

        token = strtok(NULL, ";");
        if (!token) continue;
        strncpy(registros[cantidad].descripcion, token, sizeof(registros[cantidad].descripcion));

        token = strtok(NULL, ";");
        if (!token) continue;
        strncpy(registros[cantidad].debitos, token, sizeof(registros[cantidad].debitos));

        token = strtok(NULL, ";");
        if (!token) continue;
        strncpy(registros[cantidad].creditos, token, sizeof(registros[cantidad].creditos));

        token = strtok(NULL, ";");
        if (token)
            strncpy(registros[cantidad].leyenda, token, sizeof(registros[cantidad].leyenda));
        else
            registros[cantidad].leyenda[0] = '\0';  // Leyenda vacía

        cantidad++;
    }

    // Mostrar todos los registros almacenados
    for (int i = 0; i < cantidad; i++) {
        printf("%-12s | %-35s | %-10s | %-10s | %s\n",
               registros[i].fecha,
               registros[i].descripcion,
               registros[i].debitos,
               registros[i].creditos,
               registros[i].leyenda);
    }

    return 0;
}
