#include "utils.h"

void mostrarArreglo(int *arr, int n)
{
    printf("Arreglo: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

int *generarArregloAleatorio(int n, int maxValor)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % maxValor;
    }

    return arr;
}