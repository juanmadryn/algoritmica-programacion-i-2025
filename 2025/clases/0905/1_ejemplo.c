#include <stdio.h>

int main() {
    char nombre[50];

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);  // No permite espacios

    printf("Hola, %s!\n", nombre);
    return 0;
}