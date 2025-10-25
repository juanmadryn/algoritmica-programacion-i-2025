#include <stdio.h>
#include <stdlib.h>

void imprimir_arreglo(int *arr, int n, const char *nombre) {
    printf("%s:\n", nombre);
    for (int i = 0; i < n; i++) {
        printf("  [%d] = %d\t(Dirección: %p)\n", i, arr[i], (void*)&arr[i]);
    }
    printf("\n");
}

int main() {
    // Variable en stack
    int stack_var = 42;
    printf("Variable en stack: %d (Dirección: %p)\n\n", stack_var, (void*)&stack_var);

    // malloc: reserva memoria sin inicializar
    int *arr_malloc = (int *)malloc(5 * sizeof(int));
    if (arr_malloc == NULL) {
        perror("malloc falló");
        return 1;
    }

    // Mostrar contenido de malloc
    printf("Contenido después de malloc (sin inicializar):\n");
    imprimir_arreglo(arr_malloc, 5, "arr_malloc");

    // calloc: reserva memoria e inicializa en 0
    int *arr_calloc = (int *)calloc(5, sizeof(int));
    if (arr_calloc == NULL) {
        perror("calloc falló");
        return 1;
    }

    // Mostrar contenido de calloc
    printf("Contenido después de calloc (inicializado a cero):\n");
    imprimir_arreglo(arr_calloc, 5, "arr_calloc");

    // Usar realloc para redimensionar arr_malloc
    arr_malloc = (int *)realloc(arr_malloc, 8 * sizeof(int));
    if (arr_malloc == NULL) {
        perror("realloc falló");
        return 1;
    }

    // Inicializamos las nuevas posiciones
    for (int i = 5; i < 8; i++) {
        arr_malloc[i] = i * 10;
    }

    printf("Contenido después de realloc:\n");
    imprimir_arreglo(arr_malloc, 8, "arr_malloc (redimensionado)");

    // Liberar memoria
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
