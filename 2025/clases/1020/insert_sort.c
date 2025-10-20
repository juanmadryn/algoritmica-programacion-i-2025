#include "utils.h"
#include <time.h>

#define DEBUG

void sort(int *arr, int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
#ifdef DEBUG
        printf("Iteración %d:\n", i);
        printf("Elemento a insertar: %d\n", key);
#endif
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
#ifdef DEBUG
            printf("  arr[%d] := arr[%d] (%d)\n", j + 1, j, arr[j]);
#endif
            j--;
        }

        arr[j + 1] = key;
#ifdef DEBUG
        printf("Insertado %d en la posición %d\n", key, j + 1);
        mostrarArreglo(arr, n);
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

    printf("--- Ordenamiento por Inserción con Arreglo Aleatorio ---\n\n");

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
