#include <stdio.h>
#include <time.h>
#include "../../1020/utils.h"
#include "algoritmos.h"
#include "menu.h"

int main()
{
    int n = 10000;
    int maxValor = 100;
    int *data = generarArregloAleatorio(n, maxValor);

    // Menú de selección
    int opcion = mostrar_menu();
    if (opcion == -1)
        return 1;

    // printf("Arreglo original:\n");
    // mostrarArreglo(data, n);

    clock_t start = clock();
    sort_algorithms[opcion].sort_func(data, n);
    clock_t end = clock();

    // printf("Arreglo ordenado:\n");
    // mostrarArreglo(data, n);

    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (%s): %.8f segundos\n",
           sort_algorithms[opcion].name, tiempo);
    return 0;
}
