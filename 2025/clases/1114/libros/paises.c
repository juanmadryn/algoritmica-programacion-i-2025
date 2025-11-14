// paises.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"

Pais paises[MAX_PAISES];
int totalPaises = 0;

void cargarPaises(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        perror("Error al abrir archivo de países");
        return;
    }
    totalPaises = fread(paises, sizeof(Pais), MAX_PAISES, f);
    fclose(f);
    printf("%d países cargados desde %s.\n", totalPaises, path);
}

const char* obtenerDescripcionPais(int id) {
    for (int i = 0; i < totalPaises; i++) {
        if (paises[i].id == id) return paises[i].descripcion;
    }
    return "País desconocido";
}
