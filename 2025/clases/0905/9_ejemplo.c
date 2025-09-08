#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    int esPalindromo = 1;

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    int len = strlen(palabra);

    for (int i = 0; i < len / 2; i++) {
        if (palabra[i] != palabra[len - 1 - i]) {
            esPalindromo = 0;
            break;
        }
    }

    if (esPalindromo)
        printf("Es un palíndromo.\n");
    else
        printf("No es un palíndromo.\n");

    return 0;
}
