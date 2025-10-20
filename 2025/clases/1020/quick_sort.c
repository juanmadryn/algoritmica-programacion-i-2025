#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

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

// Retorna el índice de la mediana entre arr[low], arr[mid], arr[high]
int medianaDeTres(int *arr, int low, int high) {
    int mid = low + (high - low) / 2;

    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];

    if ((a < b && b < c) || (c < b && b < a))
        return mid;
    else if ((b < a && a < c) || (c < a && a < b))
        return low;
    else
        return high;
}

// Partición con mediana de tres como pivote
int particionar(int *arr, int low, int high) {
    int medIdx = medianaDeTres(arr, low, high);
    int pivot = arr[medIdx];

    // Mover pivote a la última posición
    int temp = arr[medIdx];
    arr[medIdx] = arr[high];
    arr[high] = temp;

    printf("Usando pivote (mediana de tres): %d\n", pivot);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Intercambio arr[i] y arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Colocar el pivote en su lugar final
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void sort(int *arr, int low, int high, int totalLength) {
    if (low < high) {
        printf("QuickSort entre índices %d y %d\n", low, high);
        mostrarArreglo(arr, totalLength);
        printf("Presione ENTER para continuar...\n");
        getchar();

        int pi = particionar(arr, low, high);

        sort(arr, low, pi - 1, totalLength);
        sort(arr, pi + 1, high, totalLength);
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

    sort(arreglo, 0, n-1, n);

    printf("\n--- Arreglo ordenado ---\n");
    mostrarArreglo(arreglo, n);

    free(arreglo); // Liberar memoria

    return 0;
}
