#include <stdio.h>

extern int contador;  // Declaración de la variable global

void incrementar();

int main() {
    printf("Valor inicial: %d\n", contador);
    incrementar();
    printf("Después de incrementar: %d\n", contador);
    return 0;
}
