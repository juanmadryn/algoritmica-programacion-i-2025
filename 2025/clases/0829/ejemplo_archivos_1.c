#include <stdio.h>

int main() {
    FILE *archivo = fopen("nombres.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Juan\n");
    fprintf(archivo, "Ana\n");
    fprintf(archivo, "Carlos\n");

    fclose(archivo);
    return 0;
}
