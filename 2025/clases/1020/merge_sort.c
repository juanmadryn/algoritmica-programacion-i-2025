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

void merge(int *arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Crear arreglos temporales
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Error al asignar memoria en merge.\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];

    printf("Fusionando:\n  Izquierda: ");
    mostrarArreglo(L, n1);
    printf("  Derecha:   ");
    mostrarArreglo(R, n2);

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    printf("  Resultado: ");
    mostrarArreglo(arr + inicio, fin - inicio + 1);
    printf("Presione ENTER para continuar...\n");
    getchar();

    free(L);
    free(R);
}

void sort(int *arr, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        sort(arr, inicio, medio);
        sort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}

void sortWrapper(int *arr, int n) {
    sort(arr, 0, n - 1);
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

    sort(arreglo, 0, n-1);

    printf("\n--- Arreglo ordenado ---\n");
    mostrarArreglo(arreglo, n);

    free(arreglo); // Liberar memoria

    return 0;
}
