#include <stdio.h>
#include <time.h>
#include "../1020/utils.h"

// --- Algoritmos de ordenamiento ---

void selectionSort(int *arr, int n)
{
    printf("Ejecutando Selection Sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insertionSort(int *arr, int n)
{
    printf("Ejecutando Insertion Sort...\n");
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int *arr, int n)
{
    printf("Ejecutando Bubble Sort...\n");
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

const void (*jump_table[])(int *, int) = {
    selectionSort,
    insertionSort,
    bubbleSort};

const char *nombres[] = {
    "Selection Sort",
    "Insertion Sort",
    "Bubble Sort"};

int main()
{
    int n = 10000;
    int maxValor = 100;
    int *data = generarArregloAleatorio(n, maxValor);

    // Menú de selección
    int opcion;
    printf("Seleccione el algoritmo de ordenamiento:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    // Validar opción
    if (opcion < 1 || opcion > 3)
    {
        printf("Opción inválida.\n");
        return 1;
    }

    printf("Arreglo original:\n");
    //mostrarArreglo(data, n);

    clock_t start = clock();
    jump_table[opcion - 1](data, n);
    clock_t end = clock();

    printf("Arreglo ordenado:\n");
    //mostrarArreglo(data, n);

    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (%s): %.8f segundos\n", nombres[opcion - 1], tiempo);

    return 0;
}
