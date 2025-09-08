#include <stdio.h>

int main() {
    char frase[100];

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("La frase ingresada es: %s", frase);
    return 0;
}
