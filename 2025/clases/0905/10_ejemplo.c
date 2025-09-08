#include <stdio.h>
#include <string.h>

int main() {
    char frase[] = "Esto es una frase de ejemplo";
    char *palabra;

    // Primer llamada a strtok: pasamos la cadena original
    palabra = strtok(frase, " ");

    // Mientras haya palabras
    while (palabra != NULL) {
        printf("Palabra: %s\n", palabra);

        // Llamadas siguientes a strtok: pasamos NULL
        palabra = strtok(NULL, " ");
    }

    return 0;
}
