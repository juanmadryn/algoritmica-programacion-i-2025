#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

int tablero[N];  // tablero[i] representa la columna donde se coloca la reina en la fila i
int soluciones = 0;

// Verifica si es seguro colocar una reina en la fila 'fila' y columna 'col'
bool esValido(int fila, int col) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i] == col ||                         // Misma columna
            tablero[i] - i == col - fila ||              // Misma diagonal principal
            tablero[i] + i == col + fila)                // Misma diagonal secundaria
            return false;
    }
    return true;
}

// Imprime una solución encontrada
void mostrarTablero() {
    soluciones++;
    printf("Solución %d:\n", soluciones);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Función recursiva de backtracking
void resolver(int fila) {
    if (fila == N) {
        mostrarTablero();  // Se encontró una solución completa
        return;
    }
    for (int col = 0; col < N; col++) {
        if (esValido(fila, col)) {
            tablero[fila] = col;    // Colocar reina
            resolver(fila + 1);     // Avanzar a la siguiente fila
            // No es necesario "deshacer" tablero[fila] porque será sobrescrito en la próxima iteración
        }
    }
}

int main() {
    resolver(0);  // Comenzar desde la primera fila
    printf("Total de soluciones encontradas: %d\n", soluciones);
    return 0;
}
