// paises.h
#ifndef PAISES_H
#define PAISES_H

#define MAX_PAISES 250

typedef struct {
    int id;
    char descripcion[128];
    char iso[4];
} Pais;

extern Pais paises[MAX_PAISES];
extern int totalPaises;

void cargarPaises(const char* path);
const char* obtenerDescripcionPais(int id);

#endif
