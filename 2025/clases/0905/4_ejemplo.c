#include <stdio.h>
#include <string.h>

int main() {
    char saludo[100] = "Hola ";
    char nombre[50];

    printf("Ingrese su nombre: ");
    scanf(" %[^\n]", nombre);

    strcat(saludo, nombre);

    printf("Cadena: %s - Tamanio: %d\n", saludo, strlen(saludo));
    return 0;
}
