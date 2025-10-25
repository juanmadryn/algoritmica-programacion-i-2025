#include <stdio.h>
#include "../1020/utils.h"

void selectionSort(int* arr, int n) {
    printf("Ejecutando Selection Sort...\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insertionSort(int* arr, int n) {
    printf("Ejecutando Insertion Sort...\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int* arr, int n) {
    printf("Ejecutando Bubble Sort...\n");
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n = 100;
    int maxValor = 100;
    int *data = generarArregloAleatorio(n, maxValor);
    
    // Puntero a función de ordenamiento
    void (*sort_func)(int*, int) = NULL;

    // Menú de selección
    int opcion;
    printf("Seleccione el algoritmo de ordenamiento:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            sort_func = selectionSort;
            break;
        case 2:
            sort_func = insertionSort;
            break;
        case 3:
            sort_func = bubbleSort;
            break;
        default:
            printf("Opción inválida.\n");
            return 1;
    }

    printf("Arreglo original:\n");
    mostrarArreglo(data, n);

    // Llamar al algoritmo seleccionado usando el puntero a función
    sort_func(data, n);

    printf("Arreglo ordenado:\n");
    mostrarArreglo(data, n);

    return 0;
}
