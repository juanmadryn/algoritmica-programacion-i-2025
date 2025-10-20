#include "utils.h"
#include <time.h>

#define DEBUG

void sort(int *arr, int n)
{
    int i, j, minIdx, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
#ifdef DEBUG
        printf("Iteración %d:\n", i + 1);
#endif
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // Intercambio si se encontró un nuevo mínimo
        if (minIdx != i)
        {
#ifdef DEBUG
            printf("  Intercambio arr[%d] (%d) con arr[%d] (%d)\n", i, arr[i], minIdx, arr[minIdx]);
#endif
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
        else
        {
#ifdef DEBUG
            printf("  Sin intercambio, el mínimo ya está en posición %d\n", i);
#endif
        }

        mostrarArreglo(arr, n);
#ifdef DEBUG
        printf("\nPresione ENTER para continuar...\n");
        getchar();
#endif
    }
}

int main()
{
    int n = 10;
    int maxValor = 100;

    srand(time(NULL)); // Inicializar semilla aleatoria

    printf("--- Ordenamiento por Selección con Arreglo Aleatorio ---\n\n");

    int *arreglo = generarArregloAleatorio(n, maxValor);

    printf("Arreglo generado aleatoriamente:\n");
    mostrarArreglo(arreglo, n);

    printf("\nPresione ENTER para comenzar el ordenamiento...\n");
    getchar();

    sort(arreglo, n);

    printf("\n--- Arreglo ordenado ---\n");
    mostrarArreglo(arreglo, n);

    free(arreglo); // Liberar memoria

    return 0;
}
