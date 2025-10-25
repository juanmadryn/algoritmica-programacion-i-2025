#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arreglo;
    int n;

    // Pedir al usuario el tamaño del arreglo
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    // Reservar memoria para n enteros
    arreglo = (int *)malloc(n * sizeof(int));

    // Verificar si malloc falló
    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Cargar los valores del arreglo
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor para la posición %d: ", i);
        scanf("%d", &arreglo[i]);
    }

    // Mostrar el contenido del arreglo
    printf("\nContenido del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
    }

    // Liberar la memoria reservada
    free(arreglo);

    return 0;
}
