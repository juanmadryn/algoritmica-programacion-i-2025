#include <stdio.h>

int main() {
    char linea[100];

    printf("Ingrese una frase: ");
    scanf(" %[^\n]", linea);  // Atención al espacio antes del %

    printf("Usted ingresó: %s\n", linea);
    return 0;
}
