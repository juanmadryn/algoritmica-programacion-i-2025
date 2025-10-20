#include "utils.h"
#include <time.h>

#define DEBUG

void sort(int *arr, int n)
{
    int i, j, temp;
    int huboIntercambio = 1;

    for (i = 0; huboIntercambio && i < n - 1; i++)
    {
#ifdef DEBUG
        printf("Iteración %d:\n", i + 1);
#endif
        huboIntercambio = 0;

        for (j = 0; j < n - i - 1; j++)
        {
#ifdef DEBUG
            printf("  Comparando arr[%d] (%d) y arr[%d] (%d)", j, arr[j], j + 1, arr[j + 1]);
#endif
            if (arr[j] > arr[j + 1])
            {
                // Intercambiar
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                huboIntercambio = 1;
#ifdef DEBUG
                printf(" --> Intercambio realizado\n");
#endif
            }
            else
            {
#ifdef DEBUG
                printf(" --> No se intercambia\n");
#endif
            }
        }

#ifdef DEBUG
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
