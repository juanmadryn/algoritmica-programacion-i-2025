// tipos.h
#ifndef TIPOS_H
#define TIPOS_H

#define MAX_TIPOS 20

typedef struct {
    int id;
    char descripcion[128];
} TipoParteLibro;

extern TipoParteLibro tipos[MAX_TIPOS];
extern int totalTipos;

void cargarTipos(const char* path);
const char* obtenerDescripcionTipo(int id);

#endif