#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[100];
    int contador = 0;

    printf("Ingrese un texto: ");
    fgets(texto, sizeof(texto), stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    printf("Cantidad de vocales: %d\n", contador);
    return 0;
}
