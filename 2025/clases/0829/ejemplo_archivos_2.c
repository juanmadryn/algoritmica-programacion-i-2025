#include <stdio.h>

int main() {
    FILE *archivo = fopen("nombres.txt", "r");
    char nombre[100];

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(nombre, 100, archivo) != NULL) {
        printf("Nombre: %s", nombre);
    }

    fclose(archivo);
    return 0;
}
