#include <stdio.h>

void mostrarCuadrado(int x) {
    int resultado = x * x;
    printf("El cuadrado de %d es %d\n", x, resultado);
}

int main() {
    mostrarCuadrado(5); // Imprime 25
    // printf("%d", x); // ERROR: x no es visible aquí
    return 0;
}
