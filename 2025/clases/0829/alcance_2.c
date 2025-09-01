#include <stdio.h>

int contador = 0; // Variable global

void incrementar() {
    contador++;
}

int main() {
    incrementar();
    incrementar();
    printf("Contador: %d\n", contador); // Imprime 2
    return 0;
}
