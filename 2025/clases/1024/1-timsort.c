#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30
#define MAX_N 100
#define RUN 32
#define GALLOP_TRIGGER 7 // después de 7 elecciones seguidas, activar galloping

// Mostrar el arreglo
void printArray(int arr[], int size, const char *msg)
{
    printf("%s: [", msg);
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
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

// Insertion Sort para subarreglos
void insertionSort(int arr[], int left, int right)
{
    printf("-> InsertionSort desde %d hasta %d\n", left, right);
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        printf("   Insertar %d\n", temp);
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            printf("     Desplazar %d a la derecha\n", arr[j]);
            j--;
        }
        arr[j + 1] = temp;
        printf("   Insertado %d en posición %d\n", temp, j + 1);
    }
    printArray(arr + left, right - left + 1, "   Subarreglo ordenado");
}

// Galloping search: binary search for first value > key
int gallopRight(int key, int *arr, int len)
{
    int lo = 0, hi = 1;
    if (arr[0] > key)
        return 0;

    while (hi < len && arr[hi] <= key)
    {
        lo = hi;
        hi = hi * 2 + 1;
        if (hi >= len)
            hi = len;
    }

    // binary search between lo and hi
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= key)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int gallopLeft(int key, int *arr, int len)
{
    int lo = 0, hi = 1;
    if (arr[0] >= key)
        return 0;

    while (hi < len && arr[hi] < key)
    {
        lo = hi;
        hi = hi * 2 + 1;
        if (hi >= len)
            hi = len;
    }

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < key)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void mergeWithGalloping(int arr[], int l, int m, int r)
{
    printf("-> Merge (con galloping) de %d a %d\n", l, r);

    int len1 = m - l + 1;
    int len2 = r - m;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    memcpy(left, arr + l, len1 * sizeof(int));
    memcpy(right, arr + m + 1, len2 * sizeof(int));

    int i = 0, j = 0, k = l;
    int countLeft = 0, countRight = 0;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
            countLeft++;
            countRight = 0;
        }
        else
        {
            arr[k++] = right[j++];
            countRight++;
            countLeft = 0;
        }

        // Activar galloping si hay muchas elecciones consecutivas del mismo lado
        if (countLeft >= GALLOP_TRIGGER)
        {
            int idx = gallopRight(right[j], left + i, len1 - i);
            printf("   Galloping LEFT: copiar %d elementos desde izquierda\n", idx);
            memcpy(arr + k, left + i, idx * sizeof(int));
            k += idx;
            i += idx;
            countLeft = 0;
        }
        else if (countRight >= GALLOP_TRIGGER)
        {
            int idx = gallopLeft(left[i], right + j, len2 - j);
            printf("   Galloping RIGHT: copiar %d elementos desde derecha\n", idx);
            memcpy(arr + k, right + j, idx * sizeof(int));
            k += idx;
            j += idx;
            countRight = 0;
        }
    }

    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];

    printArray(arr + l, r - l + 1, "   Resultado parcial con galloping");

    free(left);
    free(right);
}

void timSort(int arr[], int n)
{
    for (int i = 0; i < n; i += RUN)
    {
        int right = (i + RUN - 1 < n - 1) ? i + RUN - 1 : n - 1;
        insertionSort(arr, i, right);
    }

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right)
            {
                mergeWithGalloping(arr, left, mid, right);
            }
        }
    }
}

int main()
{
    int *arr = generarArregloAleatorio(N, MAX_N);

    printArray(arr, N, "Arreglo original");
    timSort(arr, N);
    printArray(arr, N, "Arreglo final ordenado");

    return 0;
}
