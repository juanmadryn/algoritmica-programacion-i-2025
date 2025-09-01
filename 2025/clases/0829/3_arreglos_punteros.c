#include <stdio.h>

void mostrar_arreglo_con_indices(int arr[], int n) {
    printf("Usando arr[i]:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void mostrar_arreglo_con_punteros(int *ptr, int n) {
    printf("Usando *(ptr + i):\n");
    for (int i = 0; i < n; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int *p = numeros; // el arreglo se comporta como puntero al primer elemento

    printf("Dirección del arreglo: %p\n", numeros);
    printf("Dirección del puntero: %p\n", p);

    mostrar_arreglo_con_indices(numeros, 5);
    mostrar_arreglo_con_punteros(numeros, 5);

    printf("Acceso directo:\n");
    printf("numeros[2] = %d\n", numeros[2]);
    printf("*(numeros + 2) = %d\n", *(numeros + 2));
    printf("p[2] = %d\n", p[2]);
    printf("*(p + 2) = %d\n", *(p + 2));

    return 0;
}
