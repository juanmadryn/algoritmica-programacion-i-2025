// tipos.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

TipoParteLibro tipos[MAX_TIPOS];
int totalTipos = 0;

void cargarTipos(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        perror("Error al abrir archivo de tipos");
        return;
    }
    totalTipos = fread(tipos, sizeof(TipoParteLibro), MAX_TIPOS, f);
    fclose(f);
    printf("%d tipos cargados desde %s.\n", totalTipos, path);
}

const char* obtenerDescripcionTipo(int id) {
    for (int i = 0; i < totalTipos; i++) {
        if (tipos[i].id == id) return tipos[i].descripcion;
    }
    return "Tipo desconocido";
}