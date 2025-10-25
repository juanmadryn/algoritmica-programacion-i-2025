#include <stdio.h>
#include "menu.h"

int mostrar_menu() {
    int opcion;

    printf("Seleccione el algoritmo de ordenamiento:\n");
    for (int i = 0; i < num_algorithms; i++) {
        printf("%d. %s\n", i + 1, sort_algorithms[i].name);
    }

    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > num_algorithms) {
        printf("Opción inválida.\n");
        return -1;
    }

    return opcion - 1;
}
